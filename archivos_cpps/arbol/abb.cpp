#include "../../archivos_h/arbol/abb.h"

using namespace std;

Abb::Abb(Nodo* nodo) {
    this -> raiz = nodo;
}

Abb::Abb() {
    this -> raiz = nullptr;
}

void Abb::agregar_nodo(Edificio* edificio) {
    this -> raiz = this -> _agregar_nodo(this -> raiz, edificio);
}

Nodo* Abb::_agregar_nodo(Nodo* nodo, Edificio* edificio) {
    if (!nodo) {
        nodo = new Nodo(edificio);
    }
    else if (edificio -> obtener_nombre_del_edificio() > nodo -> obtener_dato() -> obtener_nombre_del_edificio()) {
        nodo -> establecer_derecha(_agregar_nodo(nodo -> obtener_der(), edificio));
    }
    else {
        nodo -> establecer_izquierda(_agregar_nodo(nodo -> obtener_izq(), edificio));
    }
    return nodo;
}

void Abb::mostrar_arbol(Nodo* nodo, int cantidad) {
    if (!nodo) {
        return;
    }
    mostrar_arbol(nodo -> obtener_der(), cantidad + 1);
    for (int i = 0; i < cantidad; i++) {
        cout << nodo -> obtener_dato() -> obtener_nombre_del_edificio() << "   " << endl;
    }
    mostrar_arbol(nodo -> obtener_izq(), cantidad + 1);
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
        return arbol -> obtener_dato() -> obtener_materiales_necesarios();
    }
    else if (nombre < arbol -> obtener_dato() -> obtener_nombre_del_edificio()){
        return _buscar_edificio(arbol -> obtener_izq(), nombre);
    }
    return _buscar_edificio(arbol -> obtener_der(), nombre);
}

void Abb::borrar_arbol(Nodo* nodo) {
    if(!nodo)
        return;
    this -> borrar_arbol(nodo -> obtener_izq());
    this -> borrar_arbol(nodo -> obtener_der());
    delete nodo;
}

Abb::~Abb() {
    this -> borrar_arbol(this -> raiz);
}