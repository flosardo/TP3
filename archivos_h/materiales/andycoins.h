#ifndef _ANDYCOINS_H_
#define _ANDYCOINS_H_

#include "material.h"

class Andycoins: public Material{

public:

    /*
    * Post: Creará un objeto de tipo andycoins con el parámetro cantidad_inventario.
    */
    Andycoins(unsigned int cantidad_inventario);

    void mostrar_material();

};

#endif // _ANDYCOINS_H_