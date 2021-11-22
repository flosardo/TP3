#ifndef _OBJETIVO_ARMADO_H
#define _OBJETIVO_ARMADO_H

#include "objetivo.h"

class Objetivo_armado: public Objetivo{
    
    private:
    
        unsigned int cantidad_bombas;

    public:

        /*
        * Post: Crea un objeto de tipo Objetivo_armado, con los valores por defecto.
        */
        Objetivo_armado();

        /*
        * Post: Mostrará el progreso por consola.
        */
        void mostrar_progreso();

        /*
        * Post: Devolvera true si hay 10 bombas en el inventario, false en caso contrario.
        */
        bool verificar(int cantidad);
    
};

#endif // _OBJETIVO_ARMADO_H_