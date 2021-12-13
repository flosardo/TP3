#include "../../archivos_h/arbol/nodo.h"
using namespace std;

Nodo::Nodo() {
    this -> edificio = nullptr;
    this -> derecha = nullptr;
    this -> izquierda = nullptr;
}

Nodo::Nodo(Edificio* nuevo_edificio) {
    this -> edificio = nuevo_edificio;
    this -> derecha = nullptr;
    this -> izquierda = nullptr;
}

Edificio* Nodo::obtener_dato() {
    return this -> edificio;
}

Nodo* Nodo::obtener_izquierda() {
    return this -> izquierda;
}

Nodo* Nodo::obtener_derecha() {
    return this -> derecha;
}

void Nodo::establecer_derecha(Nodo* nuevo_nodo) {
    this -> derecha = nuevo_nodo;
}

void Nodo::establecer_izquierda(Nodo* nuevo_nodo) {
    this -> izquierda = nuevo_nodo;
}

Nodo::~Nodo() {
    delete this -> edificio;
    edificio = nullptr;
}