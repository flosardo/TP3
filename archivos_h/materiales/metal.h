#ifndef _METAL_H_
#define _METAL_H_

#include "material.h"

class Metal : public Material{
public:

    /*
    * Post: Creará un objeto de tipo Metal, con el parámetro cantidad_inventario.
    */
    Metal(unsigned int cantidad_inventario);

    /*
    * Post: Mostrará el estado en el que se encuentra el material.
    */
    void mostrar_estado();

};

#endif // _METAL_H_