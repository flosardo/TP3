#include "../../archivos_h/construcciones/aserradero.h"

Aserradero::Aserradero() : Edificio(){}

Aserradero::Aserradero(int piedra_necesaria, int metal_necesario, int madera_necesaria) : Edificio(piedra_necesaria, metal_necesario, madera_necesaria){
    nombre_edificio = ASERRADERO;
    nombre_material = MADERA;
    cantidad_material_producido = BRINDAR_MATERIALES_ASERRADERO;
}