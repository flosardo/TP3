#include "../../archivos_h/materiales/andycoins.h"

using namespace std;

Andycoins::Andycoins(int cantidad_inventario) {
    this -> nombre = ANDYCOINS;
    this -> cantidad = cantidad_inventario;
}

void Andycoins::mostrar_material() {
    cout << "--> Material: andycoins, cantidad: " << this -> cantidad << endl;
}