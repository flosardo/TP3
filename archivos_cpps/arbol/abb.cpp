#include "../../archivos_h/arbol/abb.h"

using namespace std;

Abb::Abb() {
    this -> raiz = nullptr;
}

Abb::Abb(Nodo* nodo) {
    this -> raiz = nodo;
}


void Abb::agregar_nodo(Edificio* nuevo_edificio) {
    this -> raiz = this -> agregar_nodo_recursiva(this -> raiz, nuevo_edificio);
}

Nodo* Abb::agregar_nodo_recursiva(Nodo* nodo, Edificio* nuevo_edificio) {
    if (!nodo)
        nodo = new Nodo(nuevo_edificio);
    else if (nuevo_edificio -> obtener_nombre_del_edificio() > nodo -> obtener_dato() -> obtener_nombre_del_edificio())
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
    string nombre_edificio_guardado = edificio_guardado -> obtener_nombre_del_edificio();

    if (nombre_edificio_buscado == nombre_edificio_guardado)
        return edificio_guardado;
    else if (nombre_edificio_buscado < nombre_edificio_guardado)
        return this -> buscar_edificio_recursiva(arbol -> obtener_izquierda(), nombre_edificio_buscado);

    return this -> buscar_edificio_recursiva(arbol -> obtener_derecha(), nombre_edificio_buscado);
}


// NO SE USA NUNCA, PORQUE USAMOS BUSCAR_EDIFICIO
// bool Abb::existe_el_edificio(Nodo* nodo_actual, string nombre_edificio_buscado) {
//     string nombre_edificio_guardado =  nodo_actual -> obtener_dato() -> obtener_nombre_del_edificio();

//     if (!nodo_actual) 
//         return nombre_edificio_buscado == nombre_edificio_guardado;

//     if (nombre_edificio_buscado < nombre_edificio_guardado)
//         return this -> existe_el_edificio(nodo_actual -> obtener_izquierda(), nombre_edificio_buscado);

//     return this -> existe_el_edificio(nodo_actual -> obtener_derecha(), nombre_edificio_buscado);
// }


int Abb::contar_construidos(Jugador* jugador, std::string nombre_edificio) {
    int construidos = 0;
    construidos = jugador -> obtener_cantidad_construidos(nombre_edificio);
    return construidos;
}

void Abb::mostrar_arbol(Jugador* jugador) {
    this -> mostrar_arbol_recursiva(this -> raiz, jugador);
}

void Abb::mostrar_arbol_recursiva(Nodo* nodo, Jugador* jugador) {
    if (!nodo)
        return;

    int construidos = this -> contar_construidos(jugador, nodo -> obtener_dato() -> obtener_nombre_del_edificio());
    nodo -> obtener_dato() -> mostrar_caracteristicas(construidos);
    this -> mostrar_arbol_recursiva(nodo -> obtener_derecha(), jugador);
    this -> mostrar_arbol_recursiva(nodo -> obtener_izquierda(), jugador);
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