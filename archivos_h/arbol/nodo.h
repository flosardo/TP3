#ifndef _NODO_H
#define _NODO_H

#include "../construcciones/edificio.h"

class Nodo {
    private:
        Edificio* edificio;
        Nodo* izq;
        Nodo* der;
    public:
        Nodo(Edificio* edificio);

        Nodo* obtener_izq();

        Nodo* obtener_der();

        Edificio* obtener_dato();
        
};


#endif