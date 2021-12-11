#include "../../archivos_h/grafos/nodo_grafo.h"

using namespace std;

Nodo_grafo::Nodo_grafo(string nombre) {
    this -> elemento = new Vertice(nombre);
    this -> siguiente = nullptr;
}

Nodo_grafo* Nodo_grafo::obtener_siguiente() {
    return this -> siguiente;
}

string Nodo_grafo::obtener_nombre() {
    return this -> elemento -> obtener_nombre();
}

void Nodo_grafo::asignar_siguiente(Nodo_grafo* siguiente) {
    this -> siguiente = siguiente;
}

Nodo_grafo::~Nodo_grafo() {
    delete elemento;
}