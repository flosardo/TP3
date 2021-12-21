#ifndef _ABB_H_
#define _ABB_H_

#include "nodo.h"
#include "../jugador.h"

class Abb {

    private:

        Nodo* raiz;
        int cantidad_nodos;

    public:

        /* 
        *Post: Crea un objeto de tipo Abb
        */
        Abb();

        /* 
        *Post: Obtendrá la cantidad de nodos.
        */
        int obtener_cantidad_nodos();

        /* 
        *Pre: Que el parametro no sea null.
        *Post: Cargará en el arreglo de edificios, un edificio.
        */
        void cargar_en_arreglo(Edificio** edificios);

        /*
        *Pre: Que el parametro no sean null.
        *Post: Agregará un nodo en la clase Abb.
        */
        void agregar_nodo(Edificio* nuevo_edficio);

        /*
        *Post: Obtendra null si no se encontro el edificio, en caso contrario Obtendra un puntero de tipo edificio, del edificio buscado. 
        */
        Edificio* buscar_edificio(std::string nombre);

        /*
        *Pre: Que el parámetro jugador no sea null.
        *Pos: Obtendra la cantidad de edificios construidos.
        */
        int contar_construidos(Jugador* jugador, std::string nombre_edificio);

        /*
        *Pre: Que el parametro jugador no sea null.
        *Post: Mostrará el arbol.
        */
        void mostrar_arbol(Jugador* jugador);

        /*
        *Post: Liberará la memoria utilizada por la clase a lo largo del programa.
        */
        ~Abb();

    private:


        /* 
        *Pre: Que el parametro nodo y edificio no sean null, que indice sea >= 0.
        *Post: Cargará en el arreglo de edificios, un edificio.
        */
        void cargar_en_arreglo_recursivo(Edificio** edificios, Nodo* nodo, int & indice);

        /*
        *Pre: Que los parametros no sean null.
        *Post: Agregará un nodo en la clase Abb.
        */
        Nodo* agregar_nodo_recursiva(Nodo* arbol, Edificio* nuevo_edificio);

        /*
        *Pre: Recibe un puntero a nodo y un string
        *Post: Devuelve un puntero a los materiales necesarios
        */
        Edificio* buscar_edificio_recursiva(Nodo* nodo, std::string nombre);

        /*
        *Pre: Que los parámetros no sean null.
        *Post: Mostrará el arbol.
        */
        void mostrar_arbol_recursiva(Nodo* arbol, Jugador* jugador);

        /*
        *Post: Liberará la memoria utilizada por la clase a lo largo del programa.
        */
        void borrar_arbol(Nodo* nodo);
        
};

#endif //_ABB_H_