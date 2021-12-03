#include "../../archivos_h/materiales/bomba.h"

using namespace std;

Bomba::Bomba(int cantidad_inventario) {
    this -> nombre = BOMBA;
    this -> cantidad = cantidad_inventario;
    this -> codigo_emoji = EMOJI_BOMBA;
}

void Bomba::mostrar_material() {
    cout << "--> Material: bomba, cantidad: " << this -> cantidad << endl;
}