#ifndef _ESCUELA_H_
#define _ESCUELA_H_

#include "../edificio.h"

class Escuela : public Edificio{

public:
    /*
        * Post: Creará un objeto de tipo Escuela, dejandolo con sus atributos cargados con valores por defecto.
        */
    Escuela();

    /*
        * Post: Creará un objeto de tipo Escuela, usando los parámetros que recibe.
        */
    Escuela(int piedra_necesaria, int metal_necesario, int madera_necesaria);
};

#endif // _ESCUELA_H_