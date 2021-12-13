#ifndef _LISTA_H_
#define _LISTA_H_

#include "../constantes.h"
#include "nodo_grafo.h"

using namespace std;

template < typename Tipo >
class Lista{
/*ATRIBUTOS*/
private:
    int cantidadDeElementos;
    Nodo_grafo<Tipo>* primero;
    Nodo_grafo<Tipo>* ultimo;

/*MÉTODOS*/
public:
    Lista();

    //post: devuelve la cantidad de elementos que tiene la lista
    int obtenerCantidadDeElementos();

    //post: devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra
    int obtenerPosicion(string nombre);

    //post: devuelve el  nombre que se encuentra en la posicion recibida o NOMBRE_NO_ENCONTRADO si no lo encuentra
    string obtenerNombre(int posicion);

    //post: agrega un nuevo elemento a la lista
    void agregar(string nuevoElemento);

    ~Lista();
};

template < typename Tipo >
Lista<Tipo>::Lista(){
    cantidadDeElementos = 0;
    ultimo = nullptr;
    primero =  nullptr;
}

template < typename Tipo >
int Lista<Tipo>::obtenerCantidadDeElementos(){
    return cantidadDeElementos;
}

template < typename Tipo >
int Lista<Tipo>::obtenerPosicion(string nombre) {
    bool elementoEncontrado = false;
    int i = 0;
    Nodo_grafo<Tipo>* auxiliar = primero;

    while(!elementoEncontrado && i < cantidadDeElementos){
        if(auxiliar -> obtenerNombre() == nombre){
            elementoEncontrado = true;
        }
        i++;
        auxiliar = auxiliar -> obtenerSiguiente();
    }

    if(!elementoEncontrado){
        return POSICION_NO_ENCONTRADA;
    }
    return i - 1;
}

template < typename Tipo >
void Lista<Tipo>::agregar(string nuevoElemento) {
    Nodo_grafo<Tipo>* nuevoNodo = new Nodo_grafo<Tipo>(nuevoElemento);
    if(primero == nullptr){
        primero = nuevoNodo;
        ultimo = primero;
    } else {
        ultimo -> asignarSiguiente(nuevoNodo);
        ultimo = nuevoNodo;
    }
    cantidadDeElementos++;
}

template<typename Tipo>
Lista<Tipo>::~Lista() {
    Nodo_grafo<Tipo>* siguiente;
    while(primero != nullptr){
        siguiente = primero -> obtenerSiguiente();
        delete primero;
        primero = siguiente;
    }
}

template<typename Tipo>
string Lista<Tipo>::obtenerNombre(int posicion) {
    int i = 0;
    Nodo_grafo<Tipo>* auxiliar = primero;

    if(posicion > cantidadDeElementos){
        return NOMBRE_NO_ENCONTRADO;
    }

    while(i != posicion - 1){
        auxiliar = auxiliar -> obtenerSiguiente();
        i++;
    }
    return auxiliar -> obtenerNombre();
}
#endif //_LISTA_H_