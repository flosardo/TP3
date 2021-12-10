#ifndef _OBJETIVO_CANSADO_H_
#define _OBJETIVO_CANSADO_H_

#include "objetivo.h"

class Objetivo_cansado: public Objetivo {

    public:

        /*
        *Post: Crea un objeto de tipo Objetivo_cansado, con los valores por defecto.
        */
        Objetivo_cansado();

        /*
        *Post: Mostrará el progreso por consola.
        */
        void mostrar_progreso(int cantidad);

        /*
        *Post: Obtendrá true si se termina el turno con 0 de energia, false en caso contrario.
        */
        bool se_cumplio_el_objetivo(int cantidad);

};

#endif //_OBJETIVO_CANSADO_H_