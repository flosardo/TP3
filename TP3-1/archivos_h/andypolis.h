#ifndef _ANDYPOLIS_H_
#define _ANDYPOLIS_H_

#include "mapa.h"
#include <iostream>

class Andypolis{

    private:

        Mapa* mapa;
        Jugador* jugador_1;
        Jugador* jugador_2;
        Edificio** edificios_disponibles;

    public:

        /*
        *Post: Creará un objeto de tipo Andypolis con sus valores por defecto.
        */
        Andypolis();

        /*
        *Post: Devolverá un puntero de tipo Mapa, con la información del mapa de andypolis.
        */
        Mapa* devolver_mapa();

        /*
        *Post: Liberará la memoria utilizada a lo largo del programa.
        */
        ~Andypolis();

};


#endif //_ANDYPOLIS_H_