#include "../archivos_h/jugador.h"

using namespace std;

Jugador::Jugador() {
    this -> cantidad_construidos = 0;
    this -> edificios_construidos = new Edificio* [this -> cantidad_construidos];
    this -> energia = Energia();
    this -> coordenadas = new int [MAX_COORDENADAS];
    this -> coordenadas[INDICE_FILA] = -1;
    this -> coordenadas[INDICE_COLUMNA] = -1;
    this -> inventario = new Inventario();
    this -> codigo_emoji = VACIO;
    this -> nombre = VACIO;
}

void Jugador::establecer_nombre(string nombre) { // PARA COMENZAR PARTIDA
    this -> nombre = nombre;
}

void Jugador::establecer_coordenadas(int fila, int columna) {
    this -> coordenadas[INDICE_FILA] =  fila;
    this -> coordenadas[INDICE_COLUMNA] = columna;
}

void Jugador::establecer_codigo_emoji(string codigo_emoji) {
    this -> codigo_emoji = codigo_emoji;
}

void Jugador::cargar_edificio(Edificio* edificio) {
    redimensionar_edificio(this -> cantidad_construidos + 1);
    this -> edificios_construidos[this -> cantidad_construidos] = edificio;
    this -> cantidad_construidos++;
}

void Jugador::redimensionar_edificio(int nueva_longitud) {
    Edificio** nuevo_vector_edificios = new Edificio*[nueva_longitud];
    int indice = 0;
    for (int i = 0; i < this -> cantidad_construidos; i++) {
        if (this -> edificios_construidos[i]) {
            nuevo_vector_edificios[indice] = this -> edificios_construidos[i];
            indice++;
        }
    }
    delete [] this -> edificios_construidos;
    this -> edificios_construidos = nuevo_vector_edificios;
}

bool Jugador::existe_el_edificio(int fila, int columna) {
    bool existe = false;
    int i = 0;
    while(!existe && i < this -> cantidad_construidos) {
        if (this -> edificios_construidos[i] -> obtener_fila() == fila && this -> edificios_construidos[i] -> obtener_columna() == columna) {
            existe = true;
        }
        i++;
    }
    return existe;
}

bool Jugador::eliminar_edificio(int fila, int columna) {
    bool se_elimino = false;
    int i = 0;
    while (i < this -> cantidad_construidos && !se_elimino) {
        if(this -> existe_el_edificio(fila, columna)) {
            delete this -> edificios_construidos[i];
            this -> edificios_construidos[i] = nullptr;
            se_elimino = true;
            this -> redimensionar_edificio(this -> cantidad_construidos - 1);
            this -> cantidad_construidos--;
        }
        i++;
    }
    return se_elimino;
}

string Jugador::obtener_codigo_emoji() {
    return this -> codigo_emoji;
}

int* Jugador::devolver_coordenadas() {
    return this -> coordenadas;
}

int Jugador::obtener_energia_actual() {
    return this -> energia.obtener_energia_actual();
}

int Jugador::obtener_cantidad_construidos(string nombre_edificio) {
    int construidos = 0;
    for (int i = 0; i < this -> cantidad_construidos; i++) {
        if (this -> edificios_construidos[i] -> obtener_nombre() == nombre_edificio)
            construidos++;
    }
    return construidos;
}

void Jugador::mover(int fila, int columna) {
    /* HACER A FUTURO CON GRAFOS (CAMINOS MINIMOS). */
}

void Jugador::modificar_energia(int cantidad_energia) { 
    this -> energia.modificar_cantidad(cantidad_energia);
}

void Jugador::cargar_material(Material* material) {
    this -> inventario -> agregar_material(material);
}

void Jugador::modificar_inventario(string material, int cantidad) {
    this -> inventario -> modificar_cantidad_material(material, cantidad);
}

void Jugador::listar_construidos() {
    string esta_afectado;
    int fila;
    int columna; 
    for (int i = 0; i < this -> cantidad_construidos; i++) {
        esta_afectado = this -> edificios_construidos[i] -> esta_afectado() ? "SI" : "NO";
        fila =  this -> edificios_construidos[i] -> obtener_fila();
        columna =  this -> edificios_construidos[i] -> obtener_columna(); 
        cout << this -> edificios_construidos[i] -> obtener_nombre() << endl;
        cout << "Afectado: " << esta_afectado << endl;
        cout << "Coordenadas: " << '(' << fila << "," << columna << ')' << endl;
        cout << COLOR_MARRON << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
    }
}

Inventario* Jugador::obtener_inventario() {
    return this -> inventario;
}

Jugador::~Jugador() {
    delete [] this -> inventario;
    delete [] this -> coordenadas;
    this -> coordenadas = nullptr;
}