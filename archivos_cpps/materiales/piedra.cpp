#include "../../archivos_h/materiales/piedra.h"

using namespace std;

Piedra::Piedra(int cantidad_inventario) {
    this -> nombre = PIEDRA;
    this -> cantidad = cantidad_inventario;
}

Piedra::Piedra() {
    this -> nombre = PIEDRA;
    this -> cantidad = CANTIDAD_PRODUCIDA_PIEDRA;
}

void Piedra::saludar() {
    cout << "Soy una piedra " << EMOJI_PIEDRA << " y me encuentro en el casillero consultado." << endl;
}

void Piedra::mostrar_material() {
    cout << COLOR_MARRON << "--> Material: piedra, cantidad: " << COLOR_POR_DEFECTO << this->cantidad << endl;
}