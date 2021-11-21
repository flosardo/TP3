#include "../../archivos_h/materiales/bomba.h"

using namespace std;

Bomba::Bomba(unsigned int cantidad_inventario) {
    this -> nombre = BOMBA;
    this -> cantidad = cantidad_inventario;
}

void Bomba::mostrar_material() {
    cout << "--> Material: bomba, cantidad: " << this -> cantidad << endl;
}