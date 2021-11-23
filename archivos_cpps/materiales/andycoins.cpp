#include "../../archivos_h/materiales/andycoins.h"

using namespace std;

Andycoins::Andycoins(int cantidad_inventario) {
    this -> nombre = ANDYCOINS;
    this -> cantidad = cantidad_inventario;
}

void Andycoins::mostrar_material() {
    cout << COLOR_MARRON << "--> Material: andycoins, cantidad: " << COLOR_POR_DEFECTO << this -> cantidad << endl;
}