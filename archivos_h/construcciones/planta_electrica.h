#ifndef _PLANTA_ELECTRICA_H_
#define _PLANTA_ELECTRICA_H_

#include "../edificio.h"

class Planta_electrica: public Edificio{
public:
    /*
        * Post: Creará un objeto de tipo PlantaElectrica, dejando sus atributos cargados con valores por defecto.
        */
    Planta_electrica();

    /*
        * Post: Creará un objeto de tipo PlantaElectrica con los parámetros recibidos.
        */
    Planta_electrica(int piedra_necesaria, int metal_necesario, int madera_necesaria);
};

#endif // _PLANTA_ELECTRICA_H_