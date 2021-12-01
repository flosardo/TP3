#ifndef _AUXILIARES_ANDYPOLIS_H_
#define _AUXILIARES_ANDYPOLIS_H_
#include "../../archivos_h/arbol/abb.h"
#include "../../archivos_h/mapa.h"
#include <iostream>

class Auxiliares_andypolis {

    private:

        Abb* edificios_disponibles;
        Mapa* mapa;

    public:

        /*
        *Pre:
        *Post:
        */
        Auxiliares_andypolis();

        /*
        *Pre:
        *Post:
        */
        Auxiliares_andypolis(Abb* edificios_disponibles, Mapa* mapa);

        /*
        *Pre:
        *Post:
        */
        bool es_edificio_valido(std::string edificio);

        /*
        *Pre:
        *Post:
        */
        bool validar_coordenadas(int fila, int columna);
        
        /*
        *Pre:
        *Post:
        */
        int* pedir_coordenadas();

        /*
        *Pre:
        *Post:
        */
        bool es_posible_comprar_bombas(int & cantidad_bombas, int cantidad_andycoins);

        /*
        *Pre:
        *Post:
        */
        void seleccionar_jugador(std::string & nombre_1, std::string & nombre_2);

        /*
        *Pre:
        *Post:
        */
        bool hay_energia_suficiente(int energia_necesaria, int eneregia_del_jugador);
        
};


#endif //_AUXILIARES_ANDYPOLIS_H_