#include "../../archivos_h/construcciones/aserradero.h"

using namespace std;

Aserradero::Aserradero() : Edificio() {}

Aserradero::Aserradero(char jugador, unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria) : Edificio(jugador, piedra_necesaria, metal_necesario, madera_necesaria) {
    this -> nombre_edificio = ASERRADERO;
    this -> nombre_material = MADERA;
    this -> cantidad_material_producido = BRINDAR_MATERIALES_ASERRADERO;
}
void Aserradero::mostrar_saludo() {
    cout << COLOR_MARRON << "Soy un aserradero y me encuentro en el casillero consultado" << COLOR_POR_DEFECTO << endl;
}