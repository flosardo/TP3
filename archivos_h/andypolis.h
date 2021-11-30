#ifndef _ANDYPOLIS_H_
#define _ANDYPOLIS_H_

#include "mapa.h"
#include <iostream>
#include "arbol/abb.h"
#include "auxiliares_andypolis.h"

class Andypolis{

    private:

        Mapa* mapa;
        Jugador* jugador_1;
        Jugador* jugador_2;
        Edificio** edificios_disponibles;
        Abb* arbol;

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

        void modificar_edificio_nombre(std::string edficio);

        void listar_edificio();

        void mostrar_mapa();

        void comenzar_partida();

        void construir_edificio(std::string edificio);

        void listar_edificios(char jugador);

        void demoler_edificio(std::string edificio);

        void atacar_edificio();

        void reparar_edificio();

        void comprar_bombas();

        void consultar_coordenada();

        void mostrar_inventario();






};


#endif //_ANDYPOLIS_H_