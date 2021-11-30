#ifndef _AUXILIARES_ANDYPOLIS_H_
#define _AUXILIARES_ANDYPOLIS_H_

#include <iostream>
#include "andypolis.h"

class Auxiliares_andypolis{

    public:

        void construir_edificio_auxiliar(std::string edificio,Jugador* jugador);

        void listar_mis_edificios_auxiliar(Jugador* jugador);

        void demoler_edificio_auxiliar(std::string edificio,Jugador* jugador);

        void atacar_edificio_auxiliar(Jugador* jugador);

        void reparar_edificio_auxiliar(Jugador* jugador);

        void comprar_bombas_auxiliar(Jugador* jugador);

        void consultar_coordenada_auxiliar(Jugador* jugador);

        void mostrar_inventario_auxiliar(Jugador* jugador);

        void recolectar_recursos_auxiliar(Jugador* jugador);

        void mostrar_objetivos_auxiliar(Jugador* jugador);

        void recolectar_recursos_auxiliar(Jugador* jugador);

        void moverse_auxiliar(Jugador* jugador);

};



#endif //_AUXILIARES_ANDYPOLIS_H_