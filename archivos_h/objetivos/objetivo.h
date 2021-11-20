#ifndef OBJETIVO_H
#define OBJETIVO_H
#include "constantes.h"

class Objetivo {

    protected:

        std::string nombre;

    public:

        /*
        *Pre:
        *Post:
        */
        Objetivo();

        /*
        *Pre:
        *Post:
        */
        std::string devolver_nombre();

        /*
        *Pre:
        *Post:
        */
        virtual void mostrar_progreso() = 0;

        /*
        *Pre:
        *Post:
        */
        virtual bool verificar() = 0;

};

#endif // _OBJETIVO_H