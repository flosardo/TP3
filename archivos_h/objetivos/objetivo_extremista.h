#ifndef _OBJETIVO_EXTREMISTA_H_
#define _OBJETIVO_EXTREMISTA_H_

#include "objetivo.h"

class Objetivo_extremista: public Objetivo {

    private:

        int cantidad_bombas_compradas;

    public:

        /*
        * Post: Crea un objeto de tipo Objetivo_extremista con los valores por defecto.
        */
        Objetivo_extremista();

        /*
        * Post: Mostrará el progreso por consola.
        */
        void mostrar_progreso();

        /*
        * Post: Obtendrá true si hay 500 bombas compradas ó false en caso contrario.
        */
        bool se_cumplio_objetivo(Jugador* jugador);

};

#endif //_OBJETIVO_EXTREMISTA_H_