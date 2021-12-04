#include "../../archivos_h/materiales/madera.h"

using namespace std;

Madera::Madera(int cantidad_inventario) {
    this -> nombre = MADERA;
    this -> cantidad = cantidad_inventario;
    this -> codigo_emoji = EMOJI_MADERA;
}

Madera::Madera() {
    this -> nombre = MADERA;
    this -> cantidad = CANTIDAD_PRODUCIDA_MADERA;
    this -> codigo_emoji = EMOJI_MADERA;
}

void Madera::saludar() {
    cout << "Soy una Madera " << EMOJI_MADERA << ", y me encuentro en el casillero consultado." << endl;
}

void Madera::mostrar_material() {
    cout << "--> Material: madera, cantidad: " << this -> cantidad << endl;
}

void Madera::modificar_cantidad(int cantidad_a_modificar) {
    this -> cantidad -= cantidad_a_modificar;
}