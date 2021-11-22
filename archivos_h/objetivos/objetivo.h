#ifndef OBJETIVO_H
#define OBJETIVO_H

#include <iostream>
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
        virtual bool verificar(int cantidad);

        /*
        *Post: 
        */
        virtual bool verificar(std::string nombre);

        /*
        *Post: 
        */
        virtual void cambiar_estado_construido(std::string nombre);

};

#endif //_OBJETIVO_H