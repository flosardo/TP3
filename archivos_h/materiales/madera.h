#ifndef _MADERA_H_
#define _MADERA_H_

#include "material.h"

class Madera : public Material {

    public:

        /*
        *Post: Creará un objeto de tipo Madera con el parámetro cantidad_inventario.
        */
        Madera(int cantidad_inventario);

        /*
        *Post: Creará un objeto de tipo Madera con sus valores por defecto.
        */
        Madera();

        /*
        *Post: Mostrará el estado en el que se encuentra el material.
        */
        void saludar();

        /*
        *Post: Mostrará el estado en el que se encuentra el material.
        */
        void mostrar_material();

         /*
        *Post: modifica la cantidad del material segun el parametro recibido.
        */
        void modificar_cantidad(int cantidad_a_modificar);
    
};

#endif //_MADERA_H_