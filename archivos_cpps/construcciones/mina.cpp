#include "../../archivos_h/construcciones/mina.h"

Mina::Mina(): Edificio(){}

Mina::Mina(char jugador, unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria): Edificio(jugador, piedra_necesaria, metal_necesario, madera_necesaria){
    nombre_edificio = MINA;
    nombre_material = PIEDRA;
    cantidad_material_producido = BRINDAR_MATERIALES_MINA;
}