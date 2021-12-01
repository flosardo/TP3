#ifndef _AUXILIARES_ANDYPOLIS_H_
#define _AUXILIARES_ANDYPOLIS_H_

#include <iostream>

class Auxiliares_andypolis{

    public:

        Auxiliares_andypolis();

        bool es_edificio_valido(std::string edificio);

        bool validar_coordenadas(int fila, int columna);

        void pedir_coordenadas(int & fila,int & columna);

        void pedir_bombas(int & cantidad_bombas);

        void seleccionar_jugador(std::string & nombre_1, std::string & nombre_2);

        // Podría agregarse algun método para validar la cantidad de energía para realizar una acción
};


#endif //_AUXILIARES_ANDYPOLIS_H_