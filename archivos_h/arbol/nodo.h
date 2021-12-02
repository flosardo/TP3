#ifndef _NODO_H_
#define _NODO_H_

#include "../construcciones/edificio.h"

class Nodo{

    private:

        Edificio* edificio;
        Nodo* izquierda;
        Nodo* derecha;

    public:

        /*
        *Post: crea un objeto de tipo nodo.
        */
        Nodo();

        /*
        *Pre: Que el parametro no sea null.
        *Post: Construirá un objeto de tipo Nodo con los valores de los parametros recibidos.
        */
        Nodo(Edificio* edificio);

        /*
        *Post: Devolvera el nodo izquierdo.
        */
        Nodo* obtener_izquierda();

        /*
        *Post: Devolvera el nodo derecho.
        */
        Nodo* obtener_derecha();

        /*
        *Post: Devolvera el dato del edificio.
        */
        Edificio* obtener_dato();

        /*
        *Pre:
        *Post:
        */
        void establecer_derecha(Nodo* derecha);

        /*
        *Pre:
        *Post:
        */
        void establecer_izquierda(Nodo* izquierda);

        /*
        *Pre:
        *Post:
        */
        ~Nodo();
};

#endif //_NODO_H_