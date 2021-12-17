#ifndef _ANDYPOLIS_H_
#define _ANDYPOLIS_H_

#include "../arbol/abb.h"
#include "../mapa.h"
#include "../grafos/grafo.h"
#include "../objetivos/objetivo.h"
#include "auxiliares_andypolis.h"

class Andypolis {

    private:

        Mapa* mapa;
        Grafo* grafo;
        Jugador* jugador_1;
        Jugador* jugador_2;
        Jugador* jugador_actual;
        Objetivo** objetivos_1;
        Objetivo** objetivos_2;
        Abb* edificios_disponibles;
        Auxiliares_andypolis funciones_auxiliares;

    public:

        /*
        *Post: Creará un objeto de tipo Andypolis con sus valores por defecto.
        */
        Andypolis();
        
        /*
        *Pre: Que el parametro no sea null.
        *Post: Cargará el grafo.
        */
        void cargar_grafo();

        /*
        *Post: Obtendra un puntero de tipo Abb, con la información del arbol.
        */
        Abb* obtener_arbol();

        /*
        *Post: Obtendra un puntero de tipo Mapa, con la información del mapa de andypolis.
        */
        Mapa* obtener_mapa();
        
        /*
        *Post: Obtendra los objetivos.
        */
        Objetivo** obtener_objetivos();

        /*
        *Post: Cargará los objetivos de los 2 jugadores.
        */
        void cargar_objetivos();
        
        /*
        *Pre: Que los parametros no sean null.
        *Post: Asignará un objetivo a los objetivos de un jugador.
        */
        void asignar_objetivo(Objetivo** objetivos, Objetivo* objetivo, int indice);
        
        /*
        *Post: Devolvera true si se gano la partida, false en caso contrario.
        */
        bool gano_la_partida();
        
        /*
        *Post: Verificará la energía del jugador.
        */
        void verificar_energia(int & opcion_ingresada);

        /*
        *Post: Comenzará la partida de andypolis.
        */
        void comenzar_partida();

        /*
        *Post: Modificara edificio.
        */
        void modificar_edificio_nombre();

        /*
        *Post: Listará los edificios disponibles del menu de configuración.
        */
        void listar_edificios();

        /*
        *Post: Mostrará el mapa de andypolis.
        */
        void mostrar_mapa();

        /*
        *Post: Mostrará las preguntas frecuentes del juego.
        */
        void mostrar_preguntas_frecuentes();

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
        *Post: Obtendra el puntero de tipo Jugador, con el jugador actual.
        */
        Jugador* obtener_jugador_actual();

        /*
        *Post: Obtendra el puntero de tipo Jugador, con el jugador pedido.
        */
        Jugador* obtener_jugador(std::string numero_jugador);
        
        /*
        *Post: Liberará la memoria utilizada por los atributos objetivos.
        */
        void liberar_objetivos();

        /*
        *Post: Finalizará el turno del jugador actual.
        */
        void finalizar_turno();

        /*
        *Post: Liberará la memoria utilizada a lo largo del programa.
        */
        ~Andypolis();
    
    private:

        /*
        *Post: Inicializará los objetivos de los 2 jugadores.
        */
        void inicializar_objetivos();

};

#endif //_ANDYPOLIS_H_