#include "../../archivos_h/arbol/abb.h"

using namespace std;

Abb::Abb(Nodo* nodo) {
    this -> raiz = nodo;
}

Abb::Abb() {
    this -> raiz = nullptr;
}

void Abb::agregar_nodo(Edificio* edificio) {
    this -> raiz = this -> agregar_nodo_rec(this -> raiz, edificio);
}

Nodo* Abb::agregar_nodo_rec(Nodo* nodo, Edificio* edificio) {
    if (!nodo)
        nodo = new Nodo(edificio);
    else if (edificio -> obtener_nombre_del_edificio() > nodo -> obtener_dato() -> obtener_nombre_del_edificio())
        nodo -> establecer_derecha(agregar_nodo_rec(nodo -> obtener_derecha(), edificio));
    else
        nodo -> establecer_izquierda(agregar_nodo_rec(nodo -> obtener_izquierda(), edificio));

    return nodo;
}

void Abb::mostrar_arbol(Nodo* nodo, int cantidad) {
    if (!nodo)
        return;

    mostrar_arbol(nodo -> obtener_derecha(), cantidad + 1);
    for (int i = 0; i < cantidad; i++)
        cout << nodo -> obtener_dato() -> obtener_nombre_del_edificio() << "   " << endl;

    mostrar_arbol(nodo -> obtener_izquierda(), cantidad + 1);
}

bool Abb::existe_el_edificio(Nodo* arbol, string nombre) {
    bool existe = nombre == arbol -> obtener_dato() -> obtener_nombre_del_edificio();
    if (!arbol) 
        return existe;
    
    if (nombre < arbol -> obtener_dato() -> obtener_nombre_del_edificio())
        return existe_el_edificio(arbol -> obtener_izquierda(), nombre);

    return existe_el_edificio(arbol -> obtener_derecha(), nombre);
}

Edificio* Abb::buscar_edificio(string nombre) {
    return  this -> buscar_edificio_rec(this -> raiz, nombre);
}

Edificio* Abb::buscar_edificio_rec(Nodo* arbol, string nombre) {
    if (!arbol) { 
        return nullptr;
    }

    Edificio* edificio =  arbol -> obtener_dato();
    if (nombre == edificio -> obtener_nombre_del_edificio()) {
        return edificio;
    }
    else if (nombre < edificio -> obtener_nombre_del_edificio())
        return buscar_edificio_rec(arbol -> obtener_izquierda(), nombre);

    return buscar_edificio_rec(arbol -> obtener_derecha(), nombre);
}

void Abb::borrar_arbol(Nodo* nodo) {
    if(!nodo)
        return;
    this -> borrar_arbol(nodo -> obtener_izquierda());
    this -> borrar_arbol(nodo -> obtener_derecha());
    delete nodo;
}

Abb::~Abb() {
    this -> borrar_arbol(this -> raiz);
}