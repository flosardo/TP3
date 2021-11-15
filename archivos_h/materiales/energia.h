#ifndef _ENERGIA_H_
#define _ENERGIA_H_

#include "../material.h"

class Energia : public Material{

public:
    /*
        * Post: Creará un objeto de tipo Madera, dejando sus atributos cargados con los valores por defecto.
        */
    Energia();

    /*
        * Post: Creará un objeto de tipo Madera con el parámetro cantidad_inventario.
        */
    Energia(int cantidad_inventario);

    /*
        * Post: Mostrará el estado en el que se encuentra el material.
        */
    void mostrar_estado();

    void aumentar_cantidad(int cantidad_a_aumentar);
};

#endif // _MADERA_H_