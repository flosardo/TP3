#ifndef _ANDYPOLIS_H_
#define _ANDYPOLIS_H_

#include "mapa.h"
#include "inventario.h"
#include "jugador.h"
#include "construcciones/edificio.h"

class Andypolis{
    private:
        Mapa mapa;
        Jugador jugador1;
        Jugador jugador2;
        Edificio** edificios_disponibles;

    public:
        Andypolis();
        ~Andypolis();
};





#endif // _ANDYPOLIS_H_