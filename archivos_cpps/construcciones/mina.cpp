#include "../../archivos_h/construcciones/mina.h"

using namespace std;

Mina::Mina() : Edificio() {}

Mina::Mina(unsigned int piedra_necesaria, unsigned int madera_necesaria, unsigned int metal_necesario, unsigned int permitidos) : Edificio(piedra_necesaria, madera_necesaria, metal_necesario, permitidos) {
    this -> nombre_material = PIEDRA;
    this -> cantidad_material_producido = BRINDAR_MATERIALES_MINA;
    this -> nombre_del_edificio = NOMBRE_MINA;
    this -> codigo_emoji = EMOJI_MINA;
}

Mina::Mina(char jugador) {
    this -> jugador = jugador;
    this -> afectado = false;
    this -> codigo_emoji = EMOJI_MINA;
}

void Mina::mostrar_saludo() {
    cout << COLOR_MARRON << "Soy una mina y me encuentro en el casillero consultado" << COLOR_POR_DEFECTO << endl;
}