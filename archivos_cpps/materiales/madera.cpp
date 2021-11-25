#include "../../archivos_h/materiales/madera.h"

using namespace std;

Madera::Madera(int cantidad_inventario) {
    this -> nombre = MADERA;
    this -> cantidad = cantidad_inventario;
}

Madera::Madera() {}

void Madera::saludar() {
    cout << "Soy una Madera " << EMOJI_MADERA << ", y me encuentro en el casillero consultado." << endl;
}

void Madera::mostrar_material() {
    cout << COLOR_MARRON << "--> Material: madera, cantidad: " << COLOR_POR_DEFECTO << this->cantidad << endl;
}