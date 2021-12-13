#ifndef _ENERGIA_H_
#define _ENERGIA_H_

#include "material.h"

class Energia : public Material {

    public:

        /*
        *Post: Creará un objeto de tipo Energia, dejando sus atributos cargados con los valores por defecto.
        */
        Energia();

        /*
        *Post: Creará un objeto de tipo Energia con el parametro cantidad_energía.
        */
        Energia(int cantidad_energia);

        /*
        *Post: Mostrará el estado en el que se encuentra el material.
        */
        int obtener_energia_actual();

        /*
        *Post: Modificará la cantidad segun corresponda.
        */
        void modificar_cantidad(int cantidad_a_modificar);

        /*
        *Post: Mostrará el estado en el que se encuentra el material.
        */
        void mostrar_material();

};

#endif //_ENERGIA_H_