#ifndef _OBJETIVO_ANDYCOINS_H_
#define _OBJETIVO_ANDYCOINS_H_

#include "objetivo.h"

class Objetivo_andycoins: public Objetivo {


    public:

        /*
        *Post: Crea un objeto de tipo Objetivo_andycoins, con los valores por defecto.
        */
        Objetivo_andycoins();

        /*
        *Post: Mostrará el progreso por consola.
        */
        void mostrar_progreso(int cantidad);

        /*
        *Post: obtendra true si hay más de 100000 andycoins, false en caso contrario.
        */
        bool se_cumplio_el_objetivo(int cantidad);
        
};

#endif //_OBJETIVO_ANDYCOINS_H_