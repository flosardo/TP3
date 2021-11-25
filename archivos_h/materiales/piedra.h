#ifndef _PIEDRA_H_
#define _PIEDRA_H_

#include "material.h"

class Piedra : public Material{

public:

    /*
    * Post: Creará un objeto de tipo Piedra con el parámetro cantidad_inventario.
    */
    Piedra(int cantidad_inventario);

    Piedra();

    /*
    * Post: Mostrará un saludo.
    */
    void saludar();

    /*
    * Post: Mostrará el estado en el que se encuentra el material.
    */
    void mostrar_material();
};

#endif // _PIEDRA_H_