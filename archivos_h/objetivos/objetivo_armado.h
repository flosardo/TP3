#ifndef _OBJETIVO_ARMADO_H_
#define _OBJETIVO_ARMADO_H_

#include "objetivo.h"

class Objetivo_armado: public Objetivo {
    
    private:
    
        int cantidad_bombas;

    public:

        /*
        *Post: Crea un objeto de tipo Objetivo_armado, con los valores por defecto.
        */
        Objetivo_armado();

        /*
        *Post: Mostrará el progreso por consola.
        */
        void mostrar_progreso();

        /*
        *Post: obtendra true si hay 10 bombas en el inventario, false en caso contrario.
        */
        bool se_cumplio_objetivo(Jugador* jugador);

};

#endif //_OBJETIVO_ARMADO_H_