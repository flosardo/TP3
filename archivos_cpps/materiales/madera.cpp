#include "../../archivos_h/materiales/madera.h"

using namespace std;

Madera::Madera() {
    this -> nombre = MADERA;
    this -> cantidad = CANTIDAD_PRODUCIDA_MADERA;
    this -> codigo_emoji = EMOJI_MADERA;
}

Madera::Madera(int cantidad_inventario) {
    this -> nombre = MADERA;
    this -> cantidad = cantidad_inventario;
    this -> codigo_emoji = EMOJI_MADERA;
}

void Madera::mostrar_material() {
    cout << "--> Material: madera, cantidad: " << this -> cantidad << endl;
}

void Madera::saludar() {
    cout << "Soy una Madera " << EMOJI_MADERA << ", y me encuentro en el casillero consultado." << endl;
}