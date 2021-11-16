#include "../../archivos_h/construcciones/obelisco.h"

Obelisco::Obelisco() : Edificio(){}

Obelisco::Obelisco(char jugador, unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria) : Edificio(jugador, piedra_necesaria, metal_necesario, madera_necesaria){
    nombre_edificio = OBELISCO;
    nombre_material = VACIO;
    cantidad_material_producido = 0;
}