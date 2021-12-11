#ifndef _LISTA_H_
#define _LISTA_H_

#include "nodo_grafo.h"
#include "../constantes.h"

class Lista {

    private:

        int cantidad_elementos;
        Nodo_grafo* primero;
        Nodo_grafo* ultimo;

    public:

        Lista();

        //post: devuelve la cantidad de elementos que tiene la lista
        int obtener_cantidad_elementos();

        //post: devuelve la posicion en la que se encuentra el nombre que recibe o -1 si no lo encuentra
        int obtener_posicion(std::string nombre);

        //post: devuelve el  nombre que se encuentra en la posicion recibida o NOMBRE_NO_ENCONTRADO si no lo encuentra
        std::string obtener_nombre(int posicion);

        //post: agrega un nuevo elemento a la lista
        void agregar(std::string nuevo_elemento);

        ~Lista();

};

#endif //_LISTA_H_