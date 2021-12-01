#include "../../archivos_h/construcciones/aserradero.h"

using namespace std;

Aserradero::Aserradero() : Edificio() {
    this -> inicializar_atributos();
}

Aserradero::Aserradero(unsigned int piedra_necesaria, unsigned int madera_necesaria, unsigned int metal_necesario, unsigned int permitidos) : Edificio(piedra_necesaria, madera_necesaria, metal_necesario, permitidos) {
    this -> inicializar_atributos();
}

Aserradero::Aserradero(unsigned int fila, unsigned int columna) : Edificio(fila, columna) {
    this -> inicializar_atributos();
}

void Aserradero::inicializar_atributos(){
    this -> nombre_material = MADERA;
    this -> cantidad_material_producido = BRINDAR_MATERIALES_ASERRADERO;
    this -> nombre_del_edificio = NOMBRE_ASERRADERO;
    this -> codigo_emoji = EMOJI_ASERRADERO;
}

void Aserradero::mostrar_saludo() {
    cout << COLOR_MARRON << "Soy un aserradero y me encuentro en el casillero consultado" << COLOR_POR_DEFECTO << endl;
}