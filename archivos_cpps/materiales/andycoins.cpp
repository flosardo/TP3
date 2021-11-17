#include "../../archivos_h/materiales/andycoins.h"

using namespace std;

Andycoins::Andycoins(unsigned int cantidad_inventario){
    nombre = ANDYCOINS;
    cantidad = cantidad_inventario;
}
void Andycoins::mostrar_material(){
    cout << "--> Material: andycoins, cantidad: " << this -> cantidad << endl;
}