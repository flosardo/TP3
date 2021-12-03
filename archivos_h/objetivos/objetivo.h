#ifndef _OBJETIVO_H_
#define _OBJETIVO_H_

#include "../constantes.h"

class Objetivo {

    protected:

        std::string nombre;

    public:

        /*
        *Post: Construira un objeto de tipo Objetivo, con sus valores por defecto.
        */
        Objetivo();

        /*
        *Post: Devolvera un string con el nombre del objetivo.
        */
        std::string devolver_nombre();

        /*
        *Post: Mostrará por consola el progreso.
        */
        virtual void mostrar_progreso() = 0;

        /*
        *Post: Devolverá true si se cumplio el objetivo en las hijas, o false en caso contrario.
        */
        virtual bool se_cumplio_el_objetivo(int cantidad);

        /*
        *Post: Devolverá true si se cumplio el objetivo o false en caso contrario.
        */
        virtual bool se_cumplio_el_objetivo(std::string nombre);

        /*
        *Post: Cambiará el estado de construido del objetivo.
        */
        virtual void cambiar_estado_construido(std::string nombre);

};

#endif //_OBJETIVO_H_