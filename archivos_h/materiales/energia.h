#ifndef _ENERGIA_H_
#define _ENERGIA_H_

#include "material.h"

class Energia : public Material{

public:

    /*
    * Post: Creará un objeto de tipo Energia, dejando sus atributos cargados con los valores por defecto.
    */
    Energia();

    /*
    * Post: Creará un objeto de tipo Energia con el parametro cantidad_energía.
    */
    Energia(unsigned int cantidad_energia);

    /*
    * Post: Aumentará la cantidad de energia (segun sea el valor de cantidad_a_aumentar), siempre y cuando no supere el maximo total de energía.
    */
    void aumentar_cantidad(unsigned int cantidad_a_aumentar);

    void mostrar_material();

};

#endif // _ENERGIA_H_