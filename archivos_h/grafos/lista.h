#ifndef _LISTA_H_
#define _LISTA_H_

#include "../constantes.h"
#include "nodo_grafo.h"

using namespace std;

template < typename Tipo >
class Lista {

    private:

        int cantidad_de_elementos;
        Nodo_grafo <Tipo>* primero;
        Nodo_grafo <Tipo>* ultimo;


    public:

        /*
        *Post: Creará un objeto de tipo lista con sus valores por defecto.
        */
        Lista();

        /*
        *Post: Devuelve la cantidad de elementos que tiene la lista.
        */
        int obtener_cantidad_de_elementos();

        /*
        *Post: Devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra.
        */
        int obtener_posicion(string nombre);

        /*
        *Post: Devuelve el  nombre que se encuentra en la posicion recibida o NOMBRE_NO_ENCONTRADO si no lo encuentra.
        */
        string obtener_nombre(int posicion);

        /*
        *Post: Agrega un nuevo elemento a la lista.
        */
        void agregar(string nuevo_elemento);
    
        /*
        *Post: Liberará la memoria utilizada por el programa.
        */
        ~Lista();

};

template < typename Tipo >
Lista <Tipo>::Lista() {
    this -> cantidad_de_elementos = 0;
    this -> ultimo = nullptr;
    this -> primero =  nullptr;
}

template < typename Tipo >
int Lista <Tipo>::obtener_cantidad_de_elementos() {
    return this -> cantidad_de_elementos;
}

template < typename Tipo >
int Lista <Tipo>::obtener_posicion(string nombre) {
    bool elemento_encontrado = false;
    int i = 0;
    Nodo_grafo <Tipo>* auxiliar = this -> primero;

    while(!elemento_encontrado && i < cantidad_de_elementos) {
        if (auxiliar -> obtener_nombre() == nombre)
            elemento_encontrado = true;
        
        i++;
        auxiliar = auxiliar -> obtener_siguiente();
    }

    if (!elemento_encontrado)
        return POSICION_NO_ENCONTRADA;

    return i - 1;
}

template < typename Tipo >
void Lista <Tipo>::agregar(string nuevo_elemento) {
    Nodo_grafo <Tipo>* nuevo_nodo = new Nodo_grafo <Tipo>(nuevo_elemento);
    if (this -> primero == nullptr) {
        this -> primero = nuevo_nodo;
        this -> ultimo = this -> primero;
    } else {
        this -> ultimo -> asignar_siguiente(nuevo_nodo);
        this -> ultimo = nuevo_nodo;
    }
    cantidad_de_elementos++;
}

template < typename Tipo >
Lista <Tipo>::~Lista() {
    Nodo_grafo <Tipo>* siguiente;
    while(this -> primero != nullptr) {
        siguiente = this -> primero -> obtener_siguiente();
        delete this -> primero;
        this -> primero = siguiente;
    }
}

template < typename Tipo >
string Lista <Tipo>::obtener_nombre(int posicion) {
    int i = 0;
    Nodo_grafo <Tipo>* auxiliar = this -> primero;

    if (posicion > cantidad_de_elementos)
        return NOMBRE_NO_ENCONTRADO;

    while(i != posicion - 1) {
        auxiliar = auxiliar -> obtener_siguiente();
        i++;
    }
    return auxiliar -> obtener_nombre();
}

#endif //_LISTA_H_