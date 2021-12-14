#ifndef _NODO_GRAFO_H_
#define _NODO_GRAFO_H_

#include "vertice.h"

using namespace std;

template < typename Tipo >
class Nodo_grafo {

    private:

        Tipo* elemento;
        Nodo_grafo <Tipo>* siguiente;
   
    public:
        
        /*
        *Post: Creará un objeto de tipo Nodo_grafo con los parametros recibidos.
        */
        Nodo_grafo(string nombre);

        /*
        *Post: Devuelve el nodo_grafo siguiente.
        */
        Nodo_grafo <Tipo>* obtener_siguiente();

        /*
        *Post: Devuelve el nombre del nodo_grafo
        */
        string obtener_nombre();

        /*
        *Post: Le asigna como siguiente el nodo_grafo recibido.
        */
        void asignar_siguiente(Nodo_grafo <Tipo>* siguiente);
        
        /*
        *Post: Liberará la memoria utilizada por la clase.
        */
        ~Nodo_grafo();

};

template < typename Tipo >
Nodo_grafo <Tipo>::Nodo_grafo(string nombre) {
    this -> elemento = new Tipo(nombre);
    this -> siguiente = nullptr;
}

template < typename Tipo >
Nodo_grafo <Tipo> *Nodo_grafo <Tipo>::obtener_siguiente() {
    return this -> siguiente;
}

template < typename Tipo >
string Nodo_grafo <Tipo>::obtener_nombre() {
    return this -> elemento -> obtener_nombre();
}

template < typename Tipo >
void Nodo_grafo <Tipo>::asignar_siguiente(Nodo_grafo <Tipo>* siguiente) {
    this -> siguiente = siguiente;
}

template < typename Tipo >
Nodo_grafo <Tipo>::~Nodo_grafo() {
    delete this -> elemento;
}

#endif //_NODO_GRAFO_H_