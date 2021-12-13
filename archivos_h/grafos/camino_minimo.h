#ifndef _CAMINO_MINIMO_H_
#define _CAMINO_MINIMO_H_

#include "lista.h"

class CaminoMinimo {
//Atributos
protected:
    int ** matrizAdyacencia;
    Lista<Vertice> * vertices;
    int cantidadVertices;

//Métodos
public:
    CaminoMinimo(Lista<Vertice> * vertices, int** matrizAdyacencia);

    //post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    virtual void caminoMinimo(int & energia_minima, int origen, int destino) = 0;

    virtual ~CaminoMinimo() = default;
};


#endif //_CAMINO_MINIMO_H_