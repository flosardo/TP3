#ifndef _ANDYPOLIS_H_
#define _ANDYPOLIS_H_

#include "../mapa.h"
#include "../arbol/abb.h"
#include "auxiliares_andypolis.h"


class Andypolis{

    private:

        Mapa* mapa;
        Jugador* jugador_1;
        Jugador* jugador_2;
        Jugador* jugador_actual;
        Abb* edificios_disponibles;
        Auxiliares_andypolis funciones_auxiliares;

    public:

        /*
        *Post: Creará un objeto de tipo Andypolis con sus valores por defecto.
        */
        Andypolis();

        /*
        *Post: Devolverá un puntero de tipo Abb, con la información del arbol.
        */
        Abb* devolver_arbol();

        /*
        *Post: Devolverá un puntero de tipo Mapa, con la información del mapa de andypolis.
        */
        Mapa* devolver_mapa();

        void comenzar_partida();

        void determinar_turno();

        void modificar_edificio_nombre(std::string edficio);

        void listar_edificio();

        void mostrar_mapa();

        void construir_edificio(std::string edificio, Jugador* jugador);

        void listar_mis_edificios(Jugador* jugador);

        void demoler_edificio(std::string edificio, Jugador* jugador);

        void atacar_edificio(Jugador* jugador);

        void reparar_edificio(Jugador* jugador);

        void comprar_bombas(Jugador* jugador);

        void consultar_coordenada(Jugador* jugador);;

        void mostrar_inventario(Jugador* jugador);

        void mostrar_objetivos(Jugador* jugador);

        void recolectar_recursos(Jugador* jugador);

        void moverse(Jugador* jugador);

        void finalizar_turno();

        void guardar_y_salir();

        /*
        *Post: Liberará la memoria utilizada a lo largo del programa.
        */
        ~Andypolis();

};

#endif //_ANDYPOLIS_H_