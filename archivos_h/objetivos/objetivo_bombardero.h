#ifndef _OBJETIVO_BOMBARDERO_H_
#define _OBJETIVO_BOMBARDERO_H_

#include "objetivo.h"

class Objetivo_bombardero: public Objetivo {

    private:
    
        int cantidad_bombardero;

    public:

        /*
        *Post: Crea un objeto de tipo Objetivo_bombardero, con los valores por defecto.
        */
        Objetivo_bombardero();

        /*
        *Post: Mostrará el progreso por consola.
        */
        void mostrar_progreso();

        /*
        *Post: obtendra true si se usaron 5 bombas, false en caso contrario.
        */
        bool se_cumplio_objetivo(Jugador* jugador);

};

#endif //_OBJETIVO_BOMBARDERO_H_