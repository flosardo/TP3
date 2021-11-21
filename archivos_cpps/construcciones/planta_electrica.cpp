#include "../../archivos_h/construcciones/planta_electrica.h"

using namespace std;

Planta_electrica::Planta_electrica() : Edificio() {}

Planta_electrica::Planta_electrica(char jugador, unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria) : Edificio(jugador, piedra_necesaria, metal_necesario, madera_necesaria) {
    this -> nombre_edificio = PLANTA_ELECTRICA;
    this -> nombre_material = VACIO;
    this -> cantidad_material_producido = BRINDAR_MATERIALES_PLANTA_ELECTRICA;
}
void Planta_electrica::mostrar_saludo() {
    cout << COLOR_MARRON << "Soy una planta electrica y me encuentro en el casillero consultado" << COLOR_POR_DEFECTO << endl;
}