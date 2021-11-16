#ifndef _PLANTA_ELECTRICA_H_
#define _PLANTA_ELECTRICA_H_

#include "edificio.h"

class Planta_electrica: public Edificio{
public:

    /*
    * Post: Creará un objeto de tipo Planta_electrica, dejando sus atributos cargados con valores por defecto.
    */
    Planta_electrica();

    /*
    * Post: Creará un objeto de tipo Planta_electrica con los parámetros recibidos.
    */
    Planta_electrica(char jugador, unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria);

};

#endif // _PLANTA_ELECTRICA_H_