#include "../../archivos_h/arbol/nodo.h"

using namespace std;

Nodo::Nodo(Edificio* edifcio) {
    this -> edificio = edificio;
    this -> der = nullptr;
    this -> izq = nullptr;
}

Nodo* Nodo::obtener_izq(Nodo* nodo) {
    return this -> izq;
}
Nodo* Nodo::obtener_der(Nodo* nodo) {
    return this -> der;
}

Edificio* Nodo::obtener_dato() {
    return this -> edificio;
}