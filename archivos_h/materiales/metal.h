#ifndef _METAL_H_
#define _METAL_H_

#include "material.h"

class Metal : public Material {

    public:

        /*
        *Post: Creará un objeto de tipo Metal, con el parámetro cantidad_inventario.
        */
        Metal(int cantidad_inventario);

        /*
        *Post: Creará un objeto de tipo Metal, con sus valores por defecto.
        */
        Metal();

        /*
        *Post: Mostrará el estado en el que se encuentra el material.
        */
        void saludar();

        /*
        *Post: Mostrará el estado en el que se encuentra el material.
        */
        void mostrar_material();    
        
};

#endif //_METAL_H_