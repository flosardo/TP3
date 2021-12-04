#include "../../archivos_h/materiales/metal.h"

using namespace std;

Metal::Metal(int cantidad_inventario) {
    this -> nombre = METAL;
    this -> cantidad = cantidad_inventario;
    this -> codigo_emoji = EMOJI_METAL;
}

Metal::Metal() {
    this -> nombre = METAL;
    this -> cantidad = CANTIDAD_PRODUCIDA_METAL;
    this -> codigo_emoji = EMOJI_METAL;
}

void Metal::saludar() {
    cout << "Soy un metal, " << EMOJI_METAL << " y me encuentro en el casillero consultado." << endl;
}

void Metal::mostrar_material() {
    cout << "--> Material: metal, cantidad: " << this -> cantidad << endl;
}
void Metal::modificar_cantidad(int cantidad_a_modificar) {
    this -> cantidad -= cantidad_a_modificar;
}