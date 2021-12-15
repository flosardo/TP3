#ifndef _OBJETIVO_CONSTRUCTOR_H_
#define _OBJETIVO_CONSTRUCTOR_H_

#include "objetivo.h"

class Objetivo_constructor: public Objetivo {

    private:

        bool construidos[MAX_EDIFICIOS_DISPONIBLES];

    public:

        /*
        *Post: Crea un objeto de tipo Objetivo_constructor, con los valores por defecto.
        */
        Objetivo_constructor();

        /*
        *Post: Mostrará el progreso por consola.
        */
        void mostrar_progreso();

        /*
        *Post: Obtendrá true si se cumplio el objetivo constructor, ó false en caso contrario.
        */
        bool se_cumplio_objetivo(Jugador* jugador);
    private:

        /*
        *Post: Cambiara el estado de construido.
        */
        void cambiar_estado_construido(std::string nombre);

};

#endif //_OBJETIVO_CONTRUCTOR_H_