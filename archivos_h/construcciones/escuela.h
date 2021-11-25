#ifndef _ESCUELA_H_
#define _ESCUELA_H_

#include "edificio.h"

class Escuela : public Edificio{

    public:

        /*
        *Post: Creará un objeto de tipo Escuela, dejandolo con sus atributos cargados con valores por defecto.
        */
        Escuela();

        /*
        *Post: Creará un objeto de tipo Escuela, usando los parámetros que recibe.
        */
        Escuela(char jugador, unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria);

        /*
        *Post: Creará un objeto de tipo Escuela usando los parámetros que recibe.
        */
        Escuela(char jugador);

        /*
        *Post: Mostrará un saludo por consola del edificio de tipo escuela.
        */
        void mostrar_saludo();
    
};

#endif //_ESCUELA_H_