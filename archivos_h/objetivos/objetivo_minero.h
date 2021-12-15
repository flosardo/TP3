#ifndef _OBJETIVO_MINERO_H_
#define _OBJETIVO_MINERO_H_

#include "objetivo.h"

class Objetivo_minero: public Objetivo {

    private:
    
        bool mina_oro_construida;
        bool mina_construida;

    public:

        /*
        *Post: Construira un objeto de tipo Objetivo_minero, con sus valores por defecto.
        */
        Objetivo_minero();

        /*
        *Post: Mostrará por consola el progreso.
        */
        void mostrar_progreso();

        /*
        *Post: Verificará si se cumplio el objetivo.
        */
        bool se_cumplio_objetivo(Jugador* jugador);
};

#endif //_OBJETIVO_MINERO_H_