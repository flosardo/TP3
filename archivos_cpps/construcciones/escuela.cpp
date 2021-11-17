#include "../../archivos_h/construcciones/escuela.h"

Escuela::Escuela(): Edificio(){}

Escuela::Escuela(char jugador, unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria): Edificio(jugador, piedra_necesaria, metal_necesario, madera_necesaria){
    nombre_edificio = ESCUELA;
    nombre_material = VACIO;
    cantidad_material_producido = BRINDAR_MATERIALES_ESCUELA;
}