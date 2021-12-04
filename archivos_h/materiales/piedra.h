#ifndef _PIEDRA_H_
#define _PIEDRA_H_

#include "material.h"

class Piedra : public Material {

    public:

        /*
        *Post: Creará un objeto de tipo Piedra con el parámetro cantidad_inventario.
        */
        Piedra(int cantidad_inventario);

        /*
        *Post: Creará un objeto de tipo Piedra, con sus valores por defecto.
        */
        Piedra();

        /*
        *Post: Mostrará un saludo.
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

#endif //_PIEDRA_H_