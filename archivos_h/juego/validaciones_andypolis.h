#ifndef _VALIDACIONES_ANDYPOLIS_H_
#define _VALIDACIONES_ANDYPOLIS_H_

#include <iostream>

class Validaciones_andypolis{

    public:

        bool es_edificio_valido(std::string edificio);

        bool validar_coordenadas(int fila, int columna);

        void pedir_coordenadas(int & fila,int & columna);

        void pedir_bombas(int & cantidad_bombas);

        // Podría agregarse algun método para validar la cantidad de energía para realizar una acción
};


#endif //_VALIDACIONES_ANDYPOLIS_H_