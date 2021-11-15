#include "../../archivos_h/materiales/bomba.h"
#include "../../archivos_h/constantes.h"
using namespace std;

Bomba::Bomba() {}

Bomba::Bomba(int cantidad_inventario){
    nombre = BOMBA;
    cantidad = cantidad_inventario;
}