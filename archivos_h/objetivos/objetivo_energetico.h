#ifndef _OBJETIVO_ENERGETICO_H_
#define _OBJETIVO_ENERGETICO_H_

#include "objetivo.h"

class Objetivo_energetico: public Objetivo {

    private:

        int cantidad_energia;

    public:

        /*
        *Post: Construira un objeto de tipo Objetivo_energetico, con sus valores por defecto.
        */
        Objetivo_energetico();

        /*
        *Post: Mostrará por consola el progreso.
        */
        void mostrar_progreso();

        /*
        *Post: Obtendrá true si se termina el turno con 100 de energía, o false en caso contrario.
        */
        bool se_cumplio_objetivo(Jugador* jugador);

};

#endif //_OBJETIVO_ENERGETICO_H_