#include "../../archivos_h/construcciones/escuela.h"

Escuela::Escuela(): Edificio(){}

Escuela::Escuela(int piedra_necesaria, int metal_necesario, int madera_necesaria) : Edificio(piedra_necesaria, metal_necesario, madera_necesaria){
    nombre_edificio = ESCUELA;
    nombre_material = VACIO;
    cantidad_material_producido = BRINDAR_MATERIALES_ESCUELA;
}