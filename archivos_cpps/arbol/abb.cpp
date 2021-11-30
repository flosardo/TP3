#include "../../archivos_h/arbol/abb.h"

using namespace std;

Abb::Abb(Nodo* nodo) {
    this -> raiz = nodo;
}

Abb::Abb() {
    this -> raiz = nullptr;
}

Nodo* Abb::obtener_raiz() {
    return this -> raiz;
}

void Abb::agregar_nodo(Edificio* nuevo_edficio) {
    this -> _agregar_nodo(this -> raiz, nuevo_edficio);
}

void Abb::_agregar_nodo(Nodo* nodo, Edificio* nuevo_edficio) {
    if (!nodo) {
        nodo = new Nodo(nuevo_edficio);
    }
    else {
        Edificio* valor_raiz = nodo -> obtener_dato();
        if (valor_raiz -> obtener_nombre_del_edificio() > nuevo_edficio -> obtener_nombre_del_edificio()) {
            _agregar_nodo(nodo -> obtener_izq(), nuevo_edficio);
        }
        else {
            _agregar_nodo(nodo -> obtener_der(), nuevo_edficio);
        }
    }
    //mostrar_arbol(this -> raiz, 1);
}

void Abb::mostrar_arbol(Nodo* nodo, int cantidad) {
    if (nodo == nullptr) {
        return;
    }
    else {
        mostrar_arbol(nodo -> obtener_der(), cantidad + 1);
        for (int i = 0; i < cantidad; i++) {
            cout << nodo -> obtener_dato() -> obtener_nombre_del_edificio() << "   " << endl;
        }
        mostrar_arbol(nodo -> obtener_izq(), cantidad + 1);
    }
}

bool Abb::existe_el_edificio(Nodo* arbol, string nombre) {
    bool existe = nombre == arbol -> obtener_dato() -> obtener_nombre_del_edificio();
    if (!arbol) {
        return existe;
    }
    if (nombre < arbol -> obtener_dato() -> obtener_nombre_del_edificio()) {
        return existe_el_edificio(arbol -> obtener_izq(), nombre);
    }
    return existe_el_edificio(arbol -> obtener_der(), nombre);
}

unsigned int* Abb::buscar_edificio(string nombre) {
    return  this -> _buscar_edificio(this -> raiz, nombre);
}

unsigned int* Abb::_buscar_edificio(Nodo* arbol, string nombre) {
    if (!arbol) {
        return nullptr;
    }

    if (nombre == arbol -> obtener_dato() -> obtener_nombre_del_edificio()) {
        unsigned int* materiales = arbol -> obtener_dato() -> obtener_materiales_necesarios();
        return materiales;
    }
    else if (nombre < arbol -> obtener_dato() -> obtener_nombre_del_edificio()){
        return _buscar_edificio(arbol -> obtener_izq(), nombre);
    }
    return _buscar_edificio(arbol -> obtener_der(), nombre);
}

Abb::~Abb() {}