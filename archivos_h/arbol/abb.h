#ifndef _ABB_H_
#define _ABB_H_
#include "nodo.h"
class Abb {
    private:
        Nodo* raiz;
    public:
        Abb(Nodo* raiz);

        void agregar_nodo(Nodo* raiz, Edificio* nuevo_edificio);
        
        ~Abb();
};

#endif