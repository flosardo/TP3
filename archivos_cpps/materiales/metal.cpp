#include "../../archivos_h/materiales/metal.h"

using namespace std;

Metal::Metal() {
    this -> nombre = METAL;
    this -> cantidad = CANTIDAD_PRODUCIDA_METAL;
    this -> codigo_emoji = EMOJI_METAL;
}

Metal::Metal(int cantidad_inventario) {
    this -> nombre = METAL;
    this -> cantidad = cantidad_inventario;
    this -> codigo_emoji = EMOJI_METAL;
}

void Metal::mostrar_material() {
    cout << "--> Material: metal, cantidad: " << this -> cantidad << endl;
}

void Metal::saludar() {
    cout << "Soy un metal, " << EMOJI_METAL << " y me encuentro en el casillero consultado." << endl;
}