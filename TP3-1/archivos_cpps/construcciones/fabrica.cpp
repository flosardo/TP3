#include "../../archivos_h/construcciones/fabrica.h"

using namespace std;

Fabrica::Fabrica() : Edificio() {}

Fabrica::Fabrica(unsigned int piedra_necesaria, unsigned int madera_necesaria, unsigned int metal_necesario, unsigned int permitidos) : Edificio(piedra_necesaria, madera_necesaria, metal_necesario, permitidos) {
    this -> nombre_material = METAL;
    this -> cantidad_material_producido = BRINDAR_MATERIALES_FABRICA;
    this -> nombre_del_edificio = NOMBRE_FABRICA;
    this -> codigo_emoji = EMOJI_FABRICA;
}

Fabrica::Fabrica(char jugador) {
    this -> jugador = jugador;
    this -> afectado = false;
    this -> codigo_emoji = EMOJI_FABRICA;
}

void Fabrica::mostrar_saludo() {
    cout << COLOR_MARRON << "Soy una fabrica y me encuentro en el casillero consultado" << COLOR_POR_DEFECTO << endl;
}