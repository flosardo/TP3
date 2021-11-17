#include "../../archivos_h/materiales/energia.h"

Energia::Energia() {}

Energia::Energia(unsigned int cantidad_energia) {
    nombre = ENERGIA;
    cantidad = cantidad_energia;
}

void Energia::aumentar_cantidad(unsigned int cantidad_a_aumentar) {
    if(this -> cantidad < MAXIMO_ENERGIA){
        this -> cantidad += cantidad_a_aumentar;
    }
}
void Energia::mostrar_material() {}