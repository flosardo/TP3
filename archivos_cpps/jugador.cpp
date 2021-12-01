#include "../archivos_h/jugador.h"

using namespace std;

Jugador::Jugador(int coordenada_x, int coordenada_y) {
    this -> cantidad_construidos = 0;
    this -> edificios_construidos = new Edificio* [this -> cantidad_construidos];
    this -> energia = ENERGIA_INICIAL;
    this -> coordenadas = new int [MAX_COORDENADAS];
    this -> coordenadas[POSICION_FILA] = coordenada_y;
    this -> coordenadas[POSICION_COLUMNA] = coordenada_x;
    this -> inventario = nullptr;
    this -> nombre = VACIO;
}

void Jugador::cargar_edificio(Edificio* edificio) {
    redimensionar_edificio(this -> cantidad_construidos + 1);
    this -> edificios_construidos[this -> cantidad_construidos] = edificio;
    this -> cantidad_construidos++;
}

void Jugador::redimensionar_edificio(unsigned int nueva_longitud) {
    Edificio** nuevo_vector_edificios = new Edificio*[nueva_longitud];
    for (unsigned int i = 0; i < this -> cantidad_construidos; i++) {
        if(this -> edificios_construidos[i])
            nuevo_vector_edificios[i] = this -> edificios_construidos[i];
    }
    delete [] this -> edificios_construidos;
    this -> edificios_construidos = nuevo_vector_edificios;
}

void Jugador::eliminar_edificio(unsigned int fila, unsigned int columna) {
    bool se_elimino = false;
    unsigned int i = 0;
    while (i < this -> cantidad_construidos && !se_elimino){
        if(this -> edificios_construidos[i] -> obtener_fila() == fila && this -> edificios_construidos[i] -> obtener_columna() == columna){
            this -> redimensionar_edificio(this -> cantidad_construidos - 1);
            this -> cantidad_construidos--;
            delete this -> edificios_construidos[i];
            this -> edificios_construidos[i] = nullptr;
            se_elimino = true;
        }
        i++;
    }
    
}

void Jugador::establecer_nombre(char nombre) {
    this -> nombre = nombre;
}

char Jugador::obtener_nombre() {
    return this -> nombre;
}

int* Jugador::devolver_coordenadas() {
    return this -> coordenadas;
}

void Jugador::mover(int coordenada_x, int coordenada_y) {
    /* HACER A FUTURO CON GRAFOS (CAMINOS MINIMOS). */
}

void Jugador::modificar_energia(int cantidad_energia) { 
    this -> energia.modificar_cantidad(cantidad_energia);
}

void Jugador::cargar_material(Material* material) {
    this -> inventario -> agregar_material(material);
}

void Jugador::modificar_inventario(string material, int cantidad) {
    int indice = this -> inventario -> obtener_indice_del_material(material);
    this -> inventario -> modificar_cantidad_material(indice, cantidad);
}

Jugador::~Jugador(){
    delete [] this -> inventario;
    delete [] this -> coordenadas;
    this -> coordenadas = nullptr;
}