#ifndef _OBJETIVO_OBELISCO_H_
#define _OBJETIVO_OBELISCO_H_

#include "objetivo.h"

class Objetivo_obelisco: public Objetivo {

    public:

        /*
        *Post: Construira un objeto de tipo Objetivo_obelisco, con sus valores por defecto.
        */
        Objetivo_obelisco();

        /*
        *Post: Mostrará por consola el progreso.
        */
        void mostrar_progreso();

        /*
        *Post: Obtendrá true si se construyo un obelisco, false en caso contrario.
        */
        bool se_cumplio_objetivo(Jugador* jugador);        
};

#endif //_OBJETIVO_OBELISCO_H_