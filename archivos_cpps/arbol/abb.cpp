#include "../../archivos_h/arbol/abb.h"

using namespace std;

Abb::Abb() {
    this -> raiz = nullptr;
    this -> cantidad_nodos = 0;
}

int Abb::obtener_cantidad_nodos() {
    return this -> cantidad_nodos;
}

void Abb::cargar_en_arreglo(Edificio** edificios) {
    int indice = 0;
    this -> cargar_en_arreglo_recursivo(edificios, this -> raiz, indice);
}

void Abb::cargar_en_arreglo_recursivo(Edificio** edificios, Nodo* nodo, int & indice) {
    if (!nodo)
        return;

    edificios[indice] = nodo -> obtener_dato();
    indice++;
    this -> cargar_en_arreglo_recursivo(edificios, nodo -> obtener_izquierda(), indice);
    this -> cargar_en_arreglo_recursivo(edificios, nodo -> obtener_derecha(), indice);
}

void Abb::agregar_nodo(Edificio* nuevo_edificio) {
    this -> raiz = this -> agregar_nodo_recursiva(this -> raiz, nuevo_edificio);
}

Nodo* Abb::agregar_nodo_recursiva(Nodo* nodo, Edificio* nuevo_edificio) {
    if (!nodo) {
        nodo = new Nodo(nuevo_edificio);
        this -> cantidad_nodos++;
    }
    else if (nuevo_edificio -> obtener_nombre() > nodo -> obtener_dato() -> obtener_nombre())
        nodo -> establecer_derecha(this -> agregar_nodo_recursiva(nodo -> obtener_derecha(), nuevo_edificio));
    else
        nodo -> establecer_izquierda(this -> agregar_nodo_recursiva(nodo -> obtener_izquierda(), nuevo_edificio));
    
    return nodo;
}

Edificio* Abb::buscar_edificio(string nombre_edificio_buscado) {
    return  this -> buscar_edificio_recursiva(this -> raiz, nombre_edificio_buscado);
}

Edificio* Abb::buscar_edificio_recursiva(Nodo* arbol, string nombre_edificio_buscado) {
    if (!arbol)
        return nullptr;

    Edificio* edificio_guardado =  arbol -> obtener_dato();
    string nombre_edificio_guardado = edificio_guardado -> obtener_nombre();

    if (nombre_edificio_buscado == nombre_edificio_guardado)
        return edificio_guardado;
    else if (nombre_edificio_buscado < nombre_edificio_guardado)
        return this -> buscar_edificio_recursiva(arbol -> obtener_izquierda(), nombre_edificio_buscado);

    return this -> buscar_edificio_recursiva(arbol -> obtener_derecha(), nombre_edificio_buscado);
}

int Abb::contar_construidos(Jugador* jugador, string nombre_edificio) {
    return jugador -> obtener_cantidad_edificio(nombre_edificio);
}

void Abb::mostrar_arbol(Jugador* jugador) {
    this -> mostrar_arbol_recursiva(this -> raiz, jugador);
}

void Abb::mostrar_arbol_recursiva(Nodo* nodo, Jugador* jugador) {
    if (!nodo)
        return;

    int construidos = this -> contar_construidos(jugador, nodo -> obtener_dato() -> obtener_nombre());
    nodo -> obtener_dato() -> mostrar_caracteristicas(construidos);
    this -> mostrar_arbol_recursiva(nodo -> obtener_derecha(), jugador);
    this -> mostrar_arbol_recursiva(nodo -> obtener_izquierda(), jugador);
}

void Abb::borrar_arbol(Nodo* nodo) {
    if (!nodo)
        return;
    this -> borrar_arbol(nodo -> obtener_izquierda());
    this -> borrar_arbol(nodo -> obtener_derecha());
    delete nodo;
}

Abb::~Abb() {
    this -> borrar_arbol(this -> raiz);
}