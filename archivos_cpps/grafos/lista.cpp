#include "../../archivos_h/grafos/lista.h"

using namespace std;

Lista::Lista(){
    this -> cantidad_elementos = 0;
    this -> primero = nullptr;
    this -> ultimo = nullptr;
}

int Lista::obtener_cantidad_elementos(){
    return this -> cantidad_elementos;
}

int Lista::obtener_posicion(string nombre){
    bool elemento_encontrado = false;
    int i = 0;
    Nodo_grafo* auxiliar = this -> primero;

    while(!elemento_encontrado && i < this -> cantidad_elementos){
        if(auxiliar -> obtener_nombre() == nombre)
            elemento_encontrado = true;
        
        i++;
        auxiliar = auxiliar -> obtener_siguiente();
    }

    if(!elemento_encontrado)
        return POSICION_NO_ENCONTRADA;
    
    return i - 1;
}

string Lista::obtener_nombre(int posicion){
    int i = 0;
    Nodo_grafo* auxiliar = this -> primero;

    if(posicion > this -> cantidad_elementos)
        return NOMBRE_NO_ENCONTRADO;
    
    while(i != posicion - 1){
        auxiliar = auxiliar -> obtener_siguiente();
        i++;
    }
    return auxiliar -> obtener_nombre();
}

void Lista::agregar(string nuevo_elemento){
    Nodo_grafo* nuevo_nodo = new Nodo_grafo(nuevo_elemento);
    if(!primero){
        this -> primero = nuevo_nodo;
        this -> ultimo = primero;
    } else {
        this -> ultimo -> asignar_siguiente(nuevo_nodo);
        this -> ultimo = nuevo_nodo;
    }
    this -> cantidad_elementos++;
}

Lista::~Lista(){
    Nodo_grafo* siguiente = nullptr;
    while(this -> primero){
        siguiente = this -> primero -> obtener_siguiente();
        delete primero;
        primero = siguiente;
    }
}