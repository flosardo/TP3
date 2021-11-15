#include "../../archivos_h/materiales/andycoins.h"
#include "../../archivos_h/constantes.h"
using namespace std;

Andycoins::Andycoins(){}

Andycoins::Andycoins(int cantidad_inventario){
    nombre = ANDYCOINS;
    cantidad = cantidad_inventario;
}