#include "../../archivos_h/materiales/bomba.h"

using namespace std;

Bomba::Bomba(unsigned int cantidad_inventario){
    nombre = BOMBA;
    cantidad = cantidad_inventario;
}

void Bomba::mostrar_material() {
    cout << "--> Material: bomba, cantidad: " << this -> cantidad << endl;
}