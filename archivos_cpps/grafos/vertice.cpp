#include "../../archivos_h/grafos/vertice.h"

using namespace std;

Vertice::Vertice(string nombre) {
    this -> nombre = nombre;
}

string Vertice::obtenerNombre() {
    return nombre;
}

Vertice::~Vertice() {}