#include "../../archivos_h/arbol/abb.h"

using namespace std;

Abb::Abb(Nodo* nodo) {
    this -> raiz = nodo;
}
Abb::Abb(){}

void Abb::_agregar_nodo(Edificio* nuevo_edficio) {
    this -> agregar_nodo(this -> raiz, nuevo_edficio);
}

void Abb::agregar_nodo(Nodo* nodo, Edificio* nuevo_edficio) {
    if (nodo == nullptr) {
        nodo = new Nodo(nuevo_edficio);
    }
    else {
        Edificio* valor_raiz = nodo -> obtener_dato();
        if (valor_raiz -> obtener_nombre_del_edificio() > nuevo_edficio -> obtener_nombre_del_edificio()) {
            agregar_nodo(nodo -> obtener_izq(), nuevo_edficio);
        }
        else {
            agregar_nodo(nodo -> obtener_der(), nuevo_edficio);
        }
    }
    //mostrar_arbol(nodo, 1);
}

void Abb::mostrar_arbol(Nodo* nodo, int cantidad) {
    if (nodo == nullptr) {
        return;
    }
    else {
        mostrar_arbol(nodo -> obtener_der(), cantidad + 1);
        for (int i = 0; i < cantidad; i++) {
            cout << nodo->obtener_dato()->obtener_nombre_del_edificio() << "   " << endl;;
        }
        mostrar_arbol(nodo -> obtener_izq(), cantidad + 1);
    }
}

bool existe_el_edificio(Nodo* arbol, string nombre) {
    bool existe = false;
    if(arbol == nullptr) {
        return existe;
    }
    else if(nombre == arbol -> obtener_dato() -> obtener_nombre_del_edificio()) {
        existe = true;
    }
    else if (nombre < arbol -> obtener_dato() -> obtener_nombre_del_edificio()) {
        existe_el_edificio(arbol -> obtener_izq(), nombre);
    }
    else {
        existe_el_edificio(arbol -> obtener_der(), nombre);
    }
    return existe;
}

unsigned int* buscar_edificio(Nodo* arbol, string nombre) {
    if (arbol -> obtener_dato() == nullptr) {
        return nullptr;
    }
    else if (nombre == arbol -> obtener_dato() -> obtener_nombre_del_edificio()) {
        return arbol -> obtener_dato() -> obtener_materiales_necesarios();
    }
    else if (nombre < arbol -> obtener_dato() -> obtener_nombre_del_edificio()){
        return buscar_edificio(arbol -> obtener_izq(), nombre);
    }
    else {
        return buscar_edificio(arbol -> obtener_der(), nombre);
    }
}

Abb::~Abb() {}