#include "../archivos_h/jugador.h"

Jugador::Jugador(int coordenada_x, int coordenada_y) {
    this -> energia = ENERGIA_INICIAL;
    this -> coordenadas = new int [MAX_COORDENADAS];
    this -> coordenadas[POSICION_FILA] = coordenada_y;
    this -> coordenadas[POSICION_COLUMNA] = coordenada_x;
    this -> inventario = nullptr;
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

void Jugador::modificar_inventario(char material, int cantidad) {
    int indice = this -> inventario -> obtener_indice_del_material(material);
    this -> inventario -> modificar_cantidad_material(indice, cantidad);
}

Jugador::~Jugador(){
    delete [] this -> coordenadas;
    this -> coordenadas = nullptr;
}