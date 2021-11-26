#include "../../archivos_h/arbol/abb.h"

using namespace std;

Abb::Abb(Nodo* nodo) {
    this -> raiz = nodo;
}

void Abb::agregar_nodo(Nodo* nodo, Edificio* nuevo_edficio) {
    if (nodo == nullptr) {
        Nodo* nuevo_nodo = new Nodo(nuevo_edficio);
        nodo = nuevo_nodo;
    }
    else {
        Edificio* valor_de_raiz = nodo -> obtener_dato();
        if (nuevo_edficio -> obtener_nombre_string() < valor_raiz -> obtener_nombre_string()) {
            agregar_nodo(nodo -> obtener_izq(), nuevo_edficio); 
        }
        else {
            agregar_nodo(nodo -> obtener_der(), nuevo_edficio);
        }
    }
}
Abb::~Abb() {}
