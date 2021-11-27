#ifndef _ABB_H_
#define _ABB_H_

#include "nodo.h"

class Abb{

    private:

        Nodo* raiz;

    public:

        /*
        *Pre: Que el nodo raiz no sea null.
        *Post: Construirá un objeto de tipo Abb con los valores de los parametros recibidos.
        */
        Abb(Nodo* raiz);

        /*
        *Pre: Que los parametros no sean null.
        *Post: Agregará un nodo en la clase Abb.
        */
        void agregar_nodo(Nodo* raiz, Edificio* nuevo_edificio);
        
        /*
        *Post: Liberará la memoria utilizada por la clase a lo largo del programa.
        */
        ~Abb();

};

#endif //_ABB_H_