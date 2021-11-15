#include "../../archivos_h/materiales/energia.h"

Energia::Energia() {}

Energia::Energia(int cantidad_inventario) {
    nombre = ENERGIA;
    cantidad = cantidad_inventario;
}
void Energia::aumentar_cantidad(int cantidad_a_aumentar) {
    if(this -> cantidad < MAXIMO_ENERGIA){
        this -> cantidad += cantidad_a_aumentar;
    }
}