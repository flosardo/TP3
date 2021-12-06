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
        *Post: Comenzará la partida de andypolis.
        */
        void comenzar_partida();

        /*
        *Pre: Que la opcion sea >= 0.
        *Post: Verificará la energía.
        */
        void verificar_energia(int & opcion_ingresada);

        /*
        *Post: Cambiara el turno del jugador actual.
        */
        void cambiar_turno();

        /*
        *Post: Modificara edificio.
        */
        void modificar_edificio_nombre();

        /*
        *Post: Listará los edificios disponibles del menu de configuración.
        */
        void listar_edificios();
        
        // FIN, GURADAR_Y_SALIR COMPARTEN

        /*
        *Post: Mostrará el mapa de andypolis.
        */
        void mostrar_mapa();

        /*
        *Post: Construirá un edificio.
        */
        void construir_edificio();

        /*
        *Post: Listará los edificios del jugador actual.
        */
        void listar_mis_edificios();

        /*
        *Post: Demolera un edificio de andypolis.
        */
        void demoler_edificio();

        /*
        *Post: Se atacará un edificio del jugador contrario.
        */
        void atacar_edificio();

        /*
        *Post: Se repará un edificio del jugador actual
        */
        void reparar_edificio();

        /*
        *Post: Se realizará la compara de las bombas, del jugador actual.
        */
        void comprar_bombas();

        /*
        *Post: Mostrará la información de la coordenada consultada.
        */
        void consultar_coordenada();

        /*
        *Post: Mostrará el invetario del jugador actual.
        */
        void mostrar_inventario();

        /*
        *Post: Mostrará los objetivos.
        */
        void mostrar_objetivos();

        /*
        *Post: Recolectará los recursos de andypolis.
        */
        void recolectar_recursos();

        /*
        *Post: Cambiará las coordenadas del jugador actual, moviendolo de posición.
        */
        void moverse();

        /*
        *Post: Finalizará el turno del jugador actual.
        */
        void finalizar_turno();

        /*
        *Post: Guardará la partida de andypolis.
        */
        void guardar_y_salir();

        /*
        *Post: Devolverá el puntero de tipo Jugador, con el jugador actual.
        */
        Jugador* devolver_jugador_actual();

        /*
        *Post: Devolveráel puntero de tipo Jugador, con el jugador pedido.
        */
        Jugador* devolver_jugador(std::string numero_jugador);

        /*
        *Post: Liberará la memoria utilizada a lo largo del programa.
        */
        ~Andypolis();

};

#endif //_ANDYPOLIS_H_