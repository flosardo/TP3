#include "../../archivos_h/construcciones/mina.h"

using namespace std;

Mina::Mina() : Edificio() {}

Mina::Mina(char jugador, unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria) : Edificio(jugador, piedra_necesaria, metal_necesario, madera_necesaria) {
    this -> nombre_edificio = MINA;
    this -> nombre_material = PIEDRA;
    this -> cantidad_material_producido = BRINDAR_MATERIALES_MINA;
}
void Mina::mostrar_saludo() {
    cout << COLOR_MARRON << "Soy una mina y me encuentro en el casillero consultado" << COLOR_POR_DEFECTO << endl;
}