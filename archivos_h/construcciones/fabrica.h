#ifndef _FABRICA_H_
#define _FABRICA_H_

#include "edificio.h"

class Fabrica : public Edificio {
    
    public:

        /*
        *Post: Creara un objeto de tipo Fábrica con sus valores por defecto.
        */
        Fabrica();

        /*
        *Post: Creará un objeto de tipo Fábrica con los valores pasados por parámetro.
        */
        Fabrica(unsigned int piedra_necesaria, unsigned int madera_necesaria, unsigned int metal_necesario, unsigned int permitidos);

        /*
        *Post: Creará un objeto de tipo Fabrica usando los parámetros que recibe.
        */
        Fabrica(char jugador);

        /*
        *Post: Mostrará un saludo por consola de un edificio Fabrica.
        */
        void mostrar_saludo();

        /*
        *Post: muestra por pantalla las caractersiticas del edificio
        */
        void mostrar_edificio();

};

#endif //_FABRICA_H_