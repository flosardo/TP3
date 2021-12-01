#include "../archivos_h/jugador.h"

using namespace std;

Jugador::Jugador(int coordenada_x, int coordenada_y) {
    this -> energia = ENERGIA_INICIAL;
    this -> coordenadas = new int [MAX_COORDENADAS];
    this -> coordenadas[POSICION_FILA] = coordenada_y;
    this -> coordenadas[POSICION_COLUMNA] = coordenada_x;
    this -> inventario = nullptr;
    this -> nombre = VACIO;
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

int Jugador::obtener_cantidad_construidos(string nombre_edificio, Mapa* mapa) {
    int cantidad_construidos = 0;
    int* dimensiones = mapa -> obtener_dimensiones();
    int fila = dimensiones[0];
    int columna = dimensiones[1];

    for(int i = 0; i < fila; i++) {
        for(int j = 0; j < columna; j++) {
            if(mapa[i][j] -> obtener_tipo_de_terreno() == TERRENO) {
                if(mapa[i][j] -> obtener_puntero_edificio() -> obtener_nombre_del_edificio() == nombre_edificio && this -> nombre == mapa[i][j] -> obtener_puntero_jugador() -> obtener_nombre()) {
                    cantidad_construidos++;
                }
            }
        }
    }
    delete [] dimensiones;
    dimensiones = nullptr;
    return cantidad_construidos;
}

Jugador::~Jugador(){
    delete [] this -> inventario;
    delete [] this -> coordenadas;
    this -> coordenadas = nullptr;
}