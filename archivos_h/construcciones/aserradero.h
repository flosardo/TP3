#ifndef _ASERRADERO_H_
#define _ASERRADERO_H_

#include "../edificio.h"

class Aserradero: public Edificio{

public:
    /*
        * Post: Creará un objeto de tipo Aserradero dejando sus atributos cargados con valores por defecto.
        */
    Aserradero();

    /*
        * Post: Creará un objeto de tipo Aserradero usando los parametros que recibe.
        */
    Aserradero(int piedra_necesaria, int metal_necesario, int madera_necesaria);
};

#endif // _ASERRADERO_H_