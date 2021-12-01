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
        Auxiliares_andypolis();

        Auxiliares_andypolis(Abb* edificios_disponibles, Mapa* mapa);

        bool es_edificio_valido(std::string edificio);

        bool validar_coordenadas(int fila, int columna);

        int* pedir_coordenadas();

        bool es_posible_comprar_bombas(int & cantidad_bombas, int cantidad_andycoins);

        void seleccionar_jugador(std::string & nombre_1, std::string & nombre_2);

        // Podría agregarse algun método para validar la cantidad de energía para realizar una acción
};


#endif //_AUXILIARES_ANDYPOLIS_H_