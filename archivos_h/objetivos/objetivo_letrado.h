#ifndef _OBJETIVO_LETRADO_H_
#define _OBJETIVO_LETRADO_H_

#include "objetivo.h"

class Objetivo_letrado: public Objetivo{

    private:

        unsigned int cantidad_maxima_escuelas;
        unsigned int cantidad_escuelas_construidas;

    public:

        /*
        *Post: Construira un objeto de tipo Objetivo_letrado, con sus valores por defecto.
        */
        Objetivo_letrado(unsigned int cantidad_maxima_escuelas);

        /*
        *Post: Mostrará por consola el progreso.
        */
        void mostrar_progreso();

        /*
        *Post: Devolverá true si se construyo el maximo de escuelas permitidas, o false en caso contrario.
        */
        bool verificar(int cantidad);

};

#endif // _OBJETIVO_LETRADO_H_