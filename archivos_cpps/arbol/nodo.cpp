#include "../../archivos_h/arbol/nodo.h"
using namespace std;


Nodo::Nodo(Edificio* edificio) {
    this -> edificio = edificio;
    this -> derecha = nullptr;
    this -> izquierda = nullptr;
}

Nodo::Nodo() {
    this -> edificio = nullptr;
    this -> derecha = nullptr;
    this -> izquierda = nullptr;
}

Nodo* Nodo::obtener_izquierda() {
    return this -> izquierda;
}

Nodo* Nodo::obtener_derecha() {
    return this -> derecha;
}

Edificio* Nodo::obtener_dato() {
    return this -> edificio;
}

void Nodo::establecer_derecha(Nodo* derecha){
    this -> derecha = derecha;
}

void Nodo::establecer_izquierda(Nodo* izquierda) {
    this -> izquierda = izquierda;
}

Nodo::~Nodo() {
    delete this -> edificio;
}