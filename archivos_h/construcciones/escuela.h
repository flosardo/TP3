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
        Escuela(unsigned int piedra_necesaria, unsigned int madera_necesaria, unsigned int metal_necesario, unsigned int permitidos);

        /*
        *Post: Creará un objeto de tipo Escuela usando los parámetros que recibe.
        */
        Escuela(char jugador);

        /*
        *Post: Mostrará un saludo por consola del edificio de tipo escuela.
        */
        void mostrar_saludo();

        /*
        *Post: muestra por pantalla las caractersiticas del edificio
        */
        void mostrar_edificio(Mapa *mapa, Jugador *jugador);
};

#endif //_ESCUELA_H_