#ifndef _CAMINO_MINIMO_H_
#define _CAMINO_MINIMO_H_

#include "lista.h"

class Camino_minimo {

    protected:

        int** matriz_adyacencia;
        Lista* vertices;
        int cantidad_vertices;

    public:

        Camino_minimo(Lista * vertices, int** matriz_adyacencia);

        //post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
        virtual void camino_minimo(int origen, int destino) = 0;

        virtual ~Camino_minimo() = default;
        
};

#endif //_CAMINO_MINIMO_H_