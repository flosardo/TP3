#ifndef _AUXILIARES_ANDYPOLIS_H_
#define _AUXILIARES_ANDYPOLIS_H_

#include <iostream>


class Auxiliares_andypolis{

    public:

        bool es_edificio_valido(std::string edificio);

        bool validar_coordenadas(int fila, int columna);

        void pedir_coordenadas(int & fila,int & columna);

        void pedir_bombas(int & cantidad_bombas);






};


#endif //_AUXILIARES_ANDYPOLIS_H_