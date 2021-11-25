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
        Mapa* devolver_mapa();

        Andypolis();
        ~Andypolis();
};


#endif // _ANDYPOLIS_H_