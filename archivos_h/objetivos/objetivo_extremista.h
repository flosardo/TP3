#ifndef _OBJETIVO_EXTREMISTA_H
#define _OBJETIVO_EXTREMISTA_H

#include "objetivo.h"

class Objetivo_extremista: public Objetivo{

    private:

        unsigned int cantidad_bombas_compradas;

    public:

        /*
        * Post: Crea un objeto de tipo Objetivo_extremista, con los valores por defecto.
        */
        Objetivo_extremista();

        /*
        * Post: Mostrará el progreso por consola.
        */
        void mostrar_progreso();

        /*
        * Post: Devolvera true si hay 500 bombas compradas, false en caso contrario.
        */
        bool verificar(int cantidad);
};

#endif // _OBJETIVO_EXTREMISTA_H_