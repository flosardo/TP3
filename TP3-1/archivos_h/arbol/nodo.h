#ifndef _NODO_H_
#define _NODO_H_

#include "../construcciones/edificio.h"

class Nodo{

    private:

        Edificio* edificio;
        Nodo* izq;
        Nodo* der;

    public:

        /*
        *Pre: Que el parametro no sea null.
        *Post: Construirá un objeto de tipo Nodo con los valores de los parametros recibidos.
        */
        Nodo(Edificio* edificio);
        
        /*
        *Post: crea un objeto de tipo nodo.
        */
        Nodo();

        /*
        *Post: Devolvera el nodo izquierdo.
        */
        Nodo* obtener_izq();

        /*
        *Post: Devolvera el nodo derecho.
        */
        Nodo* obtener_der();

        /*
        *Post: Devolvera el dato del edificio.
        */
        Edificio* obtener_dato();

        void establecer_derecha(Nodo* der);

        void establecer_izquierda(Nodo* izq);
};

#endif //_NODO_H_