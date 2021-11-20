#include "../../archivos_h/materiales/energia.h"

using namespace std;

Energia::Energia() {}

Energia::Energia(unsigned int cantidad_energia) {
    nombre = ENERGIA;
    cantidad = cantidad_energia;
}

void Energia::modificar_cantidad(int cantidad_a_modificar){
    if( (this -> cantidad + cantidad_a_modificar) >= MAXIMO_ENERGIA )
        this -> cantidad = MAXIMO_ENERGIA;
    else
        this -> cantidad += cantidad_a_modificar;
}

void Energia::mostrar_material() {
    cout << "--> Material: Energía, cantidad: " << this -> cantidad << endl;
}