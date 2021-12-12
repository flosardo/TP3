#ifndef _OBJETIVO_H_
#define _OBJETIVO_H_
#include "../constantes.h"
#include "../jugador.h"
#include <iomanip>

class Objetivo {

    protected:

        std::string nombre;
        bool se_cumplio;

    public:

        /*
        *Post: Construira un objeto de tipo Objetivo, con sus valores por defecto.
        */
        Objetivo();

        /*
        *Pre: Que el parametro no sea null.
        *Post: Devolvera true si el objetivo se cumplio al menos una vez, false en caso contrario.
        */
        bool obtener_estado_objetivo(Jugador* jugador);

        /*
        *Post: Obtendrá un string con el nombre del objetivo.
        */
        std::string obtener_nombre();

        /*
        *Post: Mostrará por consola el progreso.
        */
        virtual void mostrar_progreso() = 0;

        /*
        *Post: Obtendrá true si se cumplio el objetivo en las hijas, o false en caso contrario.
        */
        virtual bool se_cumplio_el_objetivo(Jugador* jugador) = 0;

        /*
        *Post: Cambiará el estado de construido del objetivo.
        */
        virtual void cambiar_estado_construido(std::string nombre);

};

#endif //_OBJETIVO_H_