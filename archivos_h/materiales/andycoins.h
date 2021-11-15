#ifndef _ANDYCOINS_H_
#define _ANDYCOINS_H_

#include "../material.h"

class Andycoins: public Material{

public:
    /*
        * Post: Creará un objeto de tipo andycoins, dejando sus atributos cargados con los valores por defecto.
        */
    Andycoins();

    /*
        * Post: Creará un objeto de tipo andycoins con el parámetro cantidad_inventario.
        */
    Andycoins(int cantidad_inventario);
};

#endif // _ANDYCOINS_H_