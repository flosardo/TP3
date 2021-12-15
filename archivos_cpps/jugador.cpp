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
    this -> andycoins_juntados = 0;
    this -> bombas_usadas = 0;
    this -> bombas_compradas = 0;
}

void Jugador::establecer_nombre(string nombre) {
    this -> nombre = nombre;
}

int Jugador::obtener_bombas_usadas() {
    return this -> bombas_usadas;
}

int Jugador::obtener_cantidad_bombas_compradas() {
    return this -> bombas_compradas;
}

void Jugador::aumentar_bombas_usadas() {
    this -> bombas_usadas++;
}

string Jugador::obtener_nombre() {
    return this -> nombre;
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
    int* coordenadas = 0;
    while(!existe && i < this -> cantidad_construidos) {
        coordenadas = edificios_construidos[i] -> obtener_coordenadas();
        existe = coordenadas[INDICE_FILA] == fila && coordenadas[INDICE_COLUMNA] == columna;
        i++;
    }
    return existe;
}

bool Jugador::eliminar_edificio(int fila, int columna) {
    bool se_elimino = false;
    int i = 0;
    int* coordenadas = nullptr;
    while (!se_elimino && i < this -> cantidad_construidos) {
        coordenadas = edificios_construidos[i] -> obtener_coordenadas();
        if (coordenadas[INDICE_FILA] == fila && coordenadas[INDICE_COLUMNA] == columna) {
            delete this -> edificios_construidos[i];
            this -> edificios_construidos[i] = nullptr;
            se_elimino = true;
        }
        i++;
    }
    this -> redimensionar_edificio(this -> cantidad_construidos - 1);
    this -> cantidad_construidos--;
    coordenadas = nullptr;
    return se_elimino;
}

string Jugador::obtener_codigo_emoji() {
    return this -> codigo_emoji;
}

int* Jugador::obtener_coordenadas() {
    return this -> coordenadas;
}

int Jugador::obtener_andycoins_juntados() {
    return this -> andycoins_juntados;
}

int Jugador::obtener_energia_actual() {
    return this -> energia.obtener_energia_actual();
}

int Jugador::obtener_cantidad_edificio(string nombre_edificio) {
    int construidos = 0;
    for (int i = 0; i < this -> cantidad_construidos; i++) {
        if (this -> edificios_construidos[i] -> obtener_nombre() == nombre_edificio)
            construidos++;
    }
    return construidos;
}

Edificio** Jugador::obtener_edificios_construidos() {
    return this -> edificios_construidos;
}

int Jugador::obtener_construidos() {
    return this -> cantidad_construidos;
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
    int* coordenadas = 0;
    if (!this -> cantidad_construidos)
        cout << COLOR_ROJO << "Oops, parece que te quedaste sin edificios, construi para verlos aqui :)" << COLOR_POR_DEFECTO << endl;
    else {
        for (int i = 0; i < this -> cantidad_construidos; i++) {
            esta_afectado = this -> edificios_construidos[i] -> esta_afectado() ? "SI" : "NO";
            coordenadas = edificios_construidos[i] -> obtener_coordenadas();
            cout << this -> edificios_construidos[i] -> obtener_nombre() << endl;
            cout << "Afectado: " << esta_afectado << endl;
            cout << "Coordenadas: " << '(' << coordenadas[INDICE_FILA] << "," << coordenadas[INDICE_COLUMNA] << ')' << endl;
            cout << COLOR_MARRON << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
        }
    }
}

Inventario* Jugador::obtener_inventario() {
    return this -> inventario;
}

Jugador::~Jugador() {
    for (int i = 0; i < this -> cantidad_construidos; i++)
        delete this -> edificios_construidos[i];
    delete [] this -> edificios_construidos;
    delete [] this -> coordenadas;
    delete this -> inventario;
    this -> coordenadas = nullptr;
    this -> inventario = nullptr;
    this -> edificios_construidos = nullptr;
}