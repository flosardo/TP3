#ifndef _ANDYPOLIS_H_
#define _ANDYPOLIS_H_

#include "../mapa.h"
#include "../arbol/abb.h"


class Andypolis{

    private:

        Mapa* mapa;
        Jugador* jugador_1;
        Jugador* jugador_2;
        Jugador* jugador_actual;
        Abb* edificios_disponibles;

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

        void determinar_turno();

        void modificar_edificio_nombre(std::string edficio);

        void listar_edificio();

        void mostrar_mapa();

        void comenzar_partida();

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

};

#endif //_ANDYPOLIS_H_