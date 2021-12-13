#include "../../archivos_h/materiales/piedra.h"

using namespace std;

Piedra::Piedra() {
    this -> nombre = PIEDRA;
    this -> cantidad = CANTIDAD_PRODUCIDA_PIEDRA;
    this -> codigo_emoji = EMOJI_PIEDRA;
}

Piedra::Piedra(int cantidad_inventario) {
    this -> nombre = PIEDRA;
    this -> cantidad = cantidad_inventario;
    this -> codigo_emoji = EMOJI_PIEDRA;
}

void Piedra::mostrar_material() {
    cout << "--> Material: piedra, cantidad: " << this -> cantidad << endl;
}

void Piedra::saludar() {
    cout << "Soy una piedra " << EMOJI_PIEDRA << " y me encuentro en el casillero consultado." << endl;
}