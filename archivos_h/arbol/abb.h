#ifndef _ABB_H_
#define _ABB_H_

#include "nodo.h"
#include "../jugador.h"

class Abb {

    // ATRIBUTOS
    private:

        Nodo* raiz;

    // MÉTODOS
    public:

        /* 
        Post: Crea un objeto de tipo Abb
        */
        Abb();

        /*
        *Pre: Que el nodo raiz no sea null.
        *Post: Construirá un objeto de tipo Abb con los valores de los parametros recibidos.
        */
        Abb(Nodo* raiz);

        /*
        *Pre: Que el parametro no sean null.
        *Post: Agregará un nodo en la clase Abb.
        */
        void agregar_nodo(Edificio* nuevo_edficio);

        /*
        *Pre:
        *Pos:
        */
        Edificio* buscar_edificio(std::string nombre);

        /*
        *POS:
        */
        void mostrar_arbol(Jugador* jugador);

        /*
        *Post: Liberará la memoria utilizada por la clase a lo largo del programa.
        */
        ~Abb();

    private:

        /*
        *Pre: Que los parametros no sean null.
        *Post: Agregará un nodo en la clase Abb.
        */
        Nodo* agregar_nodo_recursiva(Nodo* arbol, Edificio* nuevo_edificio);

        /*
        *Pre: Recibe un puntero a nodo y un string
        *Pos: Devuelve un puntero a los materiales necesarios
        */
        Edificio* buscar_edificio_recursiva(Nodo* nodo, std::string nombre);

        // NO SE USA NUNCA, PORQUE USAMOS BUSCAR_EDIFICIO
        // /*
        // *Pre: Recibe un puntero a nodo y un string
        // *Pos: Devuelve verdadero en caso que el nombre exista, falso de lo contrario
        // */
        // bool existe_el_edificio(Nodo* nodo, std::string nombre);

        /*
        *POS:
        */
        void mostrar_arbol_recursiva(Nodo* arbol, Jugador* jugador);

        /*
        *Pre:
        *Pos:
        */
        int contar_construidos(Jugador* jugador, std::string nombre_edificio);

        /*
        *Post: Liberará la memoria utilizada por la clase a lo largo del programa.
        */
        void borrar_arbol(Nodo* nodo);
};

#endif //_ABB_H_