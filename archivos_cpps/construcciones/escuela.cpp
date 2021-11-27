#include "../../archivos_h/construcciones/escuela.h"

using namespace std;

Escuela::Escuela() : Edificio() {}

Escuela::Escuela(char jugador, unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria) : Edificio(jugador, piedra_necesaria, metal_necesario, madera_necesaria) {
    this -> nombre_material = VACIO;
    this -> cantidad_material_producido = BRINDAR_MATERIALES_ESCUELA;
    this -> nombre_del_edificio = NOMBRE_ESCUELA;
    this -> codigo_emoji = EMOJI_ESCUELA;
}

Escuela::Escuela(char jugador) {
    this -> jugador = jugador;
    this -> afectado = false;
    this -> codigo_emoji = EMOJI_ESCUELA;
}

void Escuela::mostrar_saludo() {
    cout << COLOR_MARRON << "Soy una escuela y me encuentro en el casillero consultado" << COLOR_POR_DEFECTO << endl;
}