#ifndef _ANDYPOLIS_H_
#define _ANDYPOLIS_H_

#include "../mapa.h"
#include "../arbol/abb.h"
#include "auxiliares_andypolis.h"


class Andypolis {

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

        // MENU 1

        /*
        *Pre:
        *Post:
        */
        void comenzar_partida();

        /*
        *Pre:
        *Post:
        */
        void determinar_turno();

        /*
        *Pre:
        *Post:
        */
        void modificar_edificio_nombre();

        /*
        *Pre:
        *Post:
        */
        void listar_edificios(Jugador* jugador);
        
        // FIN, GURADAR_Y_SALIR COMPARTEN

        /*
        *Pre:
        *Post:
        */
        void mostrar_mapa();

        /*
        *Pre:
        *Post:
        */
        void construir_edificio(std::string edificio, Jugador* jugador);

        /*
        *Pre:
        *Post:
        */
        void listar_mis_edificios(Jugador* jugador);

        /*
        *Pre:
        *Post:
        */
        void demoler_edificio(std::string edificio, Jugador* jugador);

        /*
        *Pre:
        *Post:
        */
        void atacar_edificio(Jugador* jugador);

        /*
        *Pre:
        *Post:
        */
        void reparar_edificio(Jugador* jugador);

        /*
        *Pre:
        *Post:
        */
        void comprar_bombas(Jugador* jugador);

        /*
        *Pre:
        *Post:
        */
        void consultar_coordenada(Jugador* jugador);

        /*
        *Pre:
        *Post:
        */
        void mostrar_inventario(Jugador* jugador);

        /*
        *Pre:
        *Post:
        */
        void mostrar_objetivos(Jugador* jugador);

        /*
        *Pre:
        *Post:
        */
        void recolectar_recursos(Jugador* jugador);

        /*
        *Pre:
        *Post:
        */
        void moverse(Jugador* jugador);

        /*
        *Pre:
        *Post:
        */
        void finalizar_turno();

        /*
        *Pre:
        *Post:
        */
        void guardar_y_salir();

        /*
        *Post: Liberará la memoria utilizada a lo largo del programa.
        */
        ~Andypolis();

};

#endif //_ANDYPOLIS_H_