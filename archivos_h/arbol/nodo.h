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

        Nodo* obtener_izq(Nodo* nodo);

        Nodo* obtener_der(Nodo* nodo);

        Edificio* obtener_dato();
        
};


#endif