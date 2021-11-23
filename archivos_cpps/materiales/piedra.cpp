#include "../../archivos_h/materiales/piedra.h"

using namespace std;

Piedra::Piedra(int cantidad_inventario) {
    this -> nombre = PIEDRA;
    this -> cantidad = cantidad_inventario;
}

void Piedra::saludar() {
    cout << "Soy una piedra " << EMOJI_PIEDRA << " y me encuentro en el casillero consultado." << endl;
}

void Piedra::mostrar_material() {
    cout << COLOR_MARRON << "--> Material: piedra, cantidad: " << COLOR_POR_DEFECTO << this->cantidad << endl;
}