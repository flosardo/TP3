#ifndef _CAMINO_MINIMO_H_
#define _CAMINO_MINIMO_H_

#include "lista.h"

class Camino_minimo {

    protected:

        int** matriz_adyacencia;
        Lista <Vertice>* vertices;
        int cantidad_vertices;

    public:

        /*
        *Post: Creará un objeto de tipo Camino_minimo con sus valores pasados por parametro.
        */
        Camino_minimo(Lista<Vertice>* vertices, int** matriz_adyacencia);

        /*
        *Post: Muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso.
        */
        virtual void camino_minimo(int & energia_minima, int origen, int destino) = 0;
    
        /*
        *Post: Destruirá la memoria utilizada por la clase.
        */
        virtual ~Camino_minimo() = default;

};

#endif //_CAMINO_MINIMO_H_