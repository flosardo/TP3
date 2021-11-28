#include "../../archivos_h/construcciones/aserradero.h"

using namespace std;

Aserradero::Aserradero() : Edificio() {}

Aserradero::Aserradero(unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria, unsigned int permitidos) : Edificio(piedra_necesaria, metal_necesario, madera_necesaria, permitidos){
    this -> nombre_material = MADERA;
    this -> cantidad_material_producido = BRINDAR_MATERIALES_ASERRADERO;
    this -> nombre_del_edificio = NOMBRE_ASERRADERO;
    this -> codigo_emoji = EMOJI_ASERRADERO;
}

Aserradero::Aserradero(char jugador) {
    this -> jugador = jugador;
    this -> afectado = false;
    this -> codigo_emoji = EMOJI_ASERRADERO;
}

void Aserradero::mostrar_saludo() {
    cout << COLOR_MARRON << "Soy un aserradero y me encuentro en el casillero consultado" << COLOR_POR_DEFECTO << endl;
}