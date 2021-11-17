#include "../../archivos_h/construcciones/planta_electrica.h"

Planta_electrica::Planta_electrica(): Edificio(){}

Planta_electrica::Planta_electrica(char jugador, unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria): Edificio(jugador, piedra_necesaria, metal_necesario, madera_necesaria){
    nombre_edificio = PLANTA_ELECTRICA;
    nombre_material = VACIO;
    cantidad_material_producido = BRINDAR_MATERIALES_PLANTA_ELECTRICA;
}