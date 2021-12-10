#ifndef _NODO_H_
#define _NODO_H_

#include "../construcciones/edificio.h"

class Nodo {

    private:

        Edificio* edificio;
        Nodo* izquierda;
        Nodo* derecha;

    public:

        /*
        *Post: Crea un objeto de tipo nodo.
        */
        Nodo();

        /*
        *Pre: Que el parametro no sea null.
        *Post: Construirá un objeto de tipo Nodo con los valores de los parametros recibidos.
        */
        Nodo(Edificio* edificio);

        /*
        *Post: Obtendra el nodo izquierdo.
        */
        Nodo* obtener_izquierda();

        /*
        *Post: Obtendra el nodo derecho.
        */
        Nodo* obtener_derecha();

        /*
        *Post: Obtendra el dato del edificio.
        */
        Edificio* obtener_dato();

        /*
        *Pre: Que el parámetro no sea null
        *Post: Establecerá el nodo de la derecha (hijo derecho).
        */
        void establecer_derecha(Nodo* derecha);

        /*
        *Pre: Que el parámetro no sea null
        *Post: Establecera el nodo de la izquierda (hijo izquierdo).
        */
        void establecer_izquierda(Nodo* izquierda);

        /*
        *Post: Liberará la memoria utilizada por el nodo.
        */
        ~Nodo();
        
};

#endif //_NODO_H_