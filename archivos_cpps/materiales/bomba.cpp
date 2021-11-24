#include "../../archivos_h/materiales/bomba.h"

using namespace std;

Bomba::Bomba(int cantidad_inventario){
    this -> nombre = BOMBA;
    this -> cantidad = cantidad_inventario;
}

void Bomba::mostrar_material() {
    cout << COLOR_MARRON << "--> Material: bomba, cantidad: " << COLOR_POR_DEFECTO << this->cantidad << endl;
}