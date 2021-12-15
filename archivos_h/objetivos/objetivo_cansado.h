#ifndef _OBJETIVO_CANSADO_H_
#define _OBJETIVO_CANSADO_H_

#include "objetivo.h"

class Objetivo_cansado: public Objetivo {

    private:
    
        int cantidad_energia;

    public:

        /*
        *Post: Crea un objeto de tipo Objetivo_cansado, con los valores por defecto.
        */
        Objetivo_cansado();

        /*
        *Post: Mostrará el progreso por consola.
        */
        void mostrar_progreso();

        /*
        *Post: Obtendrá true si se termina el turno con 0 de energia, false en caso contrario.
        */
        bool se_cumplio_objetivo(Jugador* jugador);

};

#endif //_OBJETIVO_CANSADO_H_