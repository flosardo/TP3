#include "../../archivos_h/construcciones/aserradero.h"

Aserradero::Aserradero(): Edificio(){}

Aserradero::Aserradero(char jugador, unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria): Edificio(jugador, piedra_necesaria, metal_necesario, madera_necesaria){
    nombre_edificio = ASERRADERO;
    nombre_material = MADERA;
    cantidad_material_producido = BRINDAR_MATERIALES_ASERRADERO;
}