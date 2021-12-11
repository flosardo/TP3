#ifndef _NODO_GRAFO_H_
#define _NODO_GRAFO_H_

#include "vertice.h"

class Nodo_grafo {

    private:

        Vertice* elemento;
        Nodo_grafo* siguiente;

    public:

        Nodo_grafo(std::string nombre);

        //post: devuelve el nodo siguiente.
        Nodo_grafo* obtener_siguiente();

        //post: devuelve el nombre del nodo
        std::string obtener_nombre();

        //post: le asigna como siguiente el nodo recibido
        void asignar_siguiente(Nodo_grafo* siguiente);

        ~Nodo_grafo();
        
};

#endif //_NODO_GRAFO_H_