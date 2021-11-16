#include "../../archivos_h/construcciones/fabrica.h"

Fabrica::Fabrica() : Edificio(){}

Fabrica::Fabrica(char jugador, unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria) : Edificio(jugador, piedra_necesaria, metal_necesario, madera_necesaria){
    nombre_edificio = FABRICA;
    nombre_material = METAL;
    cantidad_material_producido = BRINDAR_MATERIALES_FABRICA;
}