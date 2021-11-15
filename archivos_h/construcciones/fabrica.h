#ifndef _FABRICA_H_
#define _FABRICA_H_

#include "../edificio.h"

class Fabrica : public Edificio{
public:
    /*
        * Post: Creara un objeto de tipo Fábrica con sus valores por defecto.
        */
    Fabrica();

    /*
        * Post: Creará un objeto de tipo Fábrica con los valores pasados por parámetro.
        */
    Fabrica(int piedra_necesaria, int metal_necesario, int madera_necesaria);
};

#endif // _FABRICA_H_