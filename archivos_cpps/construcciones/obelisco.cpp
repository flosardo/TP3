#include "../../archivos_h/construcciones/obelisco.h"


Obelisco::Obelisco() : Edificio(){}

Obelisco::Obelisco(int piedra_necesaria, int metal_necesario, int madera_necesaria) : Edificio(piedra_necesaria, metal_necesario, madera_necesaria){
    nombre_edificio = OBELISCO;
    nombre_material = VACIO;
    cantidad_material_producido = 0;
}