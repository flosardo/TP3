#include "../../archivos_h/construcciones/planta_electrica.h"

Planta_electrica::Planta_electrica(): Edificio(){}

Planta_electrica::Planta_electrica(int piedra_necesaria, int metal_necesario, int madera_necesaria) : Edificio(piedra_necesaria, metal_necesario, madera_necesaria){
    nombre_edificio = PLANTA_ELECTRICA;
    nombre_material = VACIO;
    cantidad_material_producido = BRINDAR_MATERIALES_PLANTA_ELECTRICA;
}