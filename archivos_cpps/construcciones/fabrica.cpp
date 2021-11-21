#include "../../archivos_h/construcciones/fabrica.h"

using namespace std;

Fabrica::Fabrica() : Edificio() {}

Fabrica::Fabrica(char jugador, unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria) : Edificio(jugador, piedra_necesaria, metal_necesario, madera_necesaria) {
    this -> nombre_edificio = FABRICA;
    this -> nombre_material = METAL;
    this -> cantidad_material_producido = BRINDAR_MATERIALES_FABRICA;
}
void Fabrica::mostrar_saludo() {
    cout << COLOR_MARRON << "Soy una fabrica y me encuentro en el casillero consultado" << COLOR_POR_DEFECTO << endl;
}