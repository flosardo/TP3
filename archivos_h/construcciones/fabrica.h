#ifndef _FABRICA_H_
#define _FABRICA_H_

#include "edificio.h"

class Fabrica : public Edificio{
    
public:

    /*
    * Post: Creara un objeto de tipo Fábrica con sus valores por defecto.
    */
    Fabrica();

    /*
    * Post: Creará un objeto de tipo Fábrica con los valores pasados por parámetro.
    */
    Fabrica(char jugador, unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria);

    // PRE:
    // POS: muestra por pantalla el saludo del edificio
    virtual void mostrar_saludo() = 0;
};

#endif // _FABRICA_H_