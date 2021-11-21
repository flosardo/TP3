#include "../../archivos_h/materiales/metal.h"

using namespace std;

Metal::Metal(unsigned int cantidad_inventario) {
    this -> nombre = METAL;
    this -> cantidad = cantidad_inventario;
}

void Metal::saludar() {
    cout << "Soy un metal, " << EMOJI_METAL << " y me encuentro en el casillero consultado." << endl;
}

void Metal::mostrar_material() {
    cout << "--> Material: metal, cantidad: " << this -> cantidad << endl;
}