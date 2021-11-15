#include "../../archivos_h/construcciones/fabrica.h"

Fabrica::Fabrica() : Edificio(){}

Fabrica::Fabrica(int piedra_necesaria, int metal_necesario, int madera_necesaria) : Edificio(piedra_necesaria, metal_necesario, madera_necesaria){
    nombre_edificio = FABRICA;
    nombre_material = METAL;
    cantidad_material_producido = BRINDAR_MATERIALES_FABRICA;
}