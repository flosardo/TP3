#include "../../archivos_h/grafos/vertice.h"

using namespace std;

Vertice::Vertice(string nombre) {
    this -> nombre = nombre;
}

string Vertice::obtener_nombre() {
    return this -> nombre;
}

Vertice::~Vertice() {}