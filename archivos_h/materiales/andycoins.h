#ifndef _ANDYCOINS_H_
#define _ANDYCOINS_H_

#include "material.h"

class Andycoins: public Material {

    public:

        /*
        *Post: Creará un objeto de tipo andycoins con sus valores por defecto.
        */
        Andycoins();

        /*
        *Post: Creará un objeto de tipo andycoins con el parámetro cantidad_inventario.
        */
        Andycoins(int cantidad_inventario);

        /*
        *Post: Mostrara el estado en el que se encuentra el material.
        */
        void mostrar_material();

        /*
        *Post: Mostrara el estado en el que se encuentra el material.
        */
        void saludar();

};

#endif //_ANDYCOINS_H_