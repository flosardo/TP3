#include "../../archivos_h/materiales/andycoins.h"

using namespace std;

Andycoins::Andycoins() {
    this -> nombre = ANDYCOINS;
    this -> cantidad = CANTIDAD_PRODUCIDA_ANDYCOINS;
    this -> codigo_emoji = EMOJI_ANDYCOINS;
}

Andycoins::Andycoins(int cantidad_inventario) {
    this -> nombre = ANDYCOINS;
    this -> cantidad = cantidad_inventario;
    this -> codigo_emoji = EMOJI_ANDYCOINS;
}

void Andycoins::mostrar_material() {
    cout << "--> Material: andycoins, cantidad: " << this -> cantidad << endl;
}

void Andycoins::saludar() {
    cout << "Soy una bolsa de Andycoins " << EMOJI_ANDYCOINS << " y me encuentro en el casillero consultado." << endl;
}