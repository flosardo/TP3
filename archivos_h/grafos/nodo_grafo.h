#ifndef _NODO_GRAFO_H_
#define _NODO_GRAFO_H_

#include "vertice.h"

using namespace std;

template < typename Tipo >
class Nodo_grafo {
/*ATRIBUTOS*/
private:
    Tipo* elemento;
    Nodo_grafo<Tipo>* siguiente;

/*MÉTODOS*/
public:
    Nodo_grafo(string nombre);

    //post: devuelve el nodo_grafo siguiente.
    Nodo_grafo<Tipo>* obtenerSiguiente();

    //post: devuelve el nombre del nodo_grafo
    string obtenerNombre();

    //post: le asigna como siguiente el nodo_grafo recibido
    void asignarSiguiente(Nodo_grafo<Tipo>* siguiente);

    ~Nodo_grafo();
};

template<typename Tipo>
Nodo_grafo<Tipo>::Nodo_grafo(string nombre) {
    elemento = new Tipo(nombre);
    siguiente = nullptr;
}

template<typename Tipo>
Nodo_grafo<Tipo> *Nodo_grafo<Tipo>::obtenerSiguiente() {
    return siguiente;
}

template<typename Tipo>
string Nodo_grafo<Tipo>::obtenerNombre() {
    return elemento -> obtenerNombre();
}

template<typename Tipo>
void Nodo_grafo<Tipo>::asignarSiguiente(Nodo_grafo<Tipo> *siguiente) {
    this -> siguiente = siguiente;
}

template<typename Tipo>
Nodo_grafo<Tipo>::~Nodo_grafo() {
    delete elemento;
}

#endif //_NODO_GRAFO_H_