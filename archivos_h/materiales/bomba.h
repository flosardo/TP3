#ifndef _BOMBA_H_
#define _BOMBA_H_

#include "material.h"

class Bomba: public Material {

    public:

        /*
        *Post: Creará un objeto bomba con sus valores por defecto.
        */
        Bomba();

        /*
        *Post: Creará un objeto de tipo Bomba con el parámetro cantidad_inventario.
        */
        Bomba(int cantidad_inventario);

        /*
        *Post: Mostrará el estado en el que se encuentra el material.
        */
        void mostrar_material();

};

#endif //_BOMBA_H_