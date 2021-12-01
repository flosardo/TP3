#include "../../archivos_h/construcciones/aserradero.h"

using namespace std;

Aserradero::Aserradero() : Edificio() {}

Aserradero::Aserradero(unsigned int piedra_necesaria, unsigned int madera_necesaria, unsigned int metal_necesario, unsigned int permitidos) : Edificio(piedra_necesaria, madera_necesaria, metal_necesario, permitidos) {
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

void Aserradero::mostrar_edificio() {
    cout << "--> " << COLOR_VERDE_AGUA << this -> nombre << COLOR_POR_DEFECTO << endl;
    cout << endl;
    cout << "Piedra requerida: " << this -> materiales_necesarios[0] << endl;
    cout << "Madera requerida: " << this -> materiales_necesarios[1] << endl;
    cout << "Metal requerido: " << this -> materiales_necesarios[2] << endl;
    cout << "Construidos hasta el momento: " << this -> cantidad_construidos << endl;
    cout << "Puede construir " << this -> cantidad_permitida - this -> cantidad_construidos << " mas" << endl;
    cout << "Brinda material: SI" << endl;
    cout << COLOR_MARRON << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
}