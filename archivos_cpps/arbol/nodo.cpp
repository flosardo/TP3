#include "../../archivos_h/arbol/nodo.h"


Nodo::Nodo(Edificio* edificio) {
    this -> edificio = edificio;
    this -> der = nullptr;
    this -> izq = nullptr;
}

Nodo* Nodo::obtener_izq() {
    return this -> izq;
}
Nodo* Nodo::obtener_der() {
    return this -> der;
}

Edificio* Nodo::obtener_dato() {
    return this -> edificio;
}