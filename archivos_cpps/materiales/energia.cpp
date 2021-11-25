#include "../../archivos_h/materiales/energia.h"

using namespace std;

Energia::Energia() {
    this -> nombre = ENERGIA;
    this -> cantidad = ENERGIA_INICIAL;
}

Energia::Energia(int cantidad_energia) {
    this -> nombre = ENERGIA;
    this -> cantidad = cantidad_energia;
}

void Energia::modificar_cantidad(int cantidad_a_modificar){
    if ( (this -> cantidad + cantidad_a_modificar) > MAXIMO_ENERGIA )
        this -> cantidad = MAXIMO_ENERGIA;
    else
        this -> cantidad += cantidad_a_modificar;
}

void Energia::mostrar_material() {
    cout << COLOR_MARRON << "--> Material: energia, cantidad: " << COLOR_POR_DEFECTO << this->cantidad << endl;
}