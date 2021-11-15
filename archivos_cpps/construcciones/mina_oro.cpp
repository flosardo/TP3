#include "../../archivos_h/construcciones/mina_oro.h"

Mina_oro::Mina_oro(): Edificio() {}

Mina_oro::Mina_oro(int piedra_necesaria, int metal_necesario, int madera_necesaria): Edificio(piedra_necesaria, metal_necesario, madera_necesaria){
    nombre_edificio = MINA;
    nombre_material = PIEDRA;
    cantidad_material_producido = BRINDAR_MATERIALES_MINA_ORO;
}