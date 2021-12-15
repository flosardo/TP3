#ifndef _OBJETIVO_LETRADO_H_
#define _OBJETIVO_LETRADO_H_

#include "objetivo.h"

class Objetivo_letrado: public Objetivo {

    private:

        int cantidad_maxima_escuelas;
        int cantidad_escuelas_construidas;

    public:

        /*
        *Post: Construira un objeto de tipo Objetivo_letrado, con sus valores por defecto.
        */
        Objetivo_letrado(int cantidad_maxima_escuelas);

        /*
        *Post: Mostrará por consola el progreso.
        */
        void mostrar_progreso();

        /*
        *Post: Obtendrá true si se construyo el maximo de escuelas permitidas, o false en caso contrario.
        */
        bool se_cumplio_objetivo(Jugador* jugador);

};

#endif //_OBJETIVO_LETRADO_H_