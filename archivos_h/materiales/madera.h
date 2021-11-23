#ifndef _MADERA_H_
#define _MADERA_H_

#include "material.h"

class Madera : public Material{

public:

    /*
    * Post: Creará un objeto de tipo Madera con el parámetro cantidad_inventario.
    */
    Madera(int cantidad_inventario);

    /*
    * Post: Mostrará el estado en el que se encuentra el material.
    */
    void saludar();

    void mostrar_material();
    
};

#endif // _MADERA_H_