#include "../../archivos_h/materiales/metal.h"

using namespace std;

Metal::Metal(int cantidad_inventario) {
    this -> nombre = METAL;
    this -> cantidad = cantidad_inventario;
}

void Metal::saludar() {
    cout << "Soy un metal, " << EMOJI_METAL << " y me encuentro en el casillero consultado." << endl;
}

void Metal::mostrar_material() {
    cout << COLOR_MARRON << "--> Material: metal, cantidad: " << COLOR_POR_DEFECTO << this->cantidad << endl;
}