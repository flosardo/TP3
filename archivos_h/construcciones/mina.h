#ifndef _MINA_H_
#define _MINA_H_

#include "../edificio.h"

class Mina : public Edificio{
public:
    /*
        * Post: Creará un objeto de tipo Mina con los valores por defecto.
        */
    Mina();

    /*
        * Post: Creará un objeto de tipo Mina con los valores pasados por parámetro.
        */
    Mina(int piedra_necesaria, int metal_necesario, int madera_necesaria);
};

#endif // _MINA_H_