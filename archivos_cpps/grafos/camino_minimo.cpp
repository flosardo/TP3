#include "../../archivos_h/grafos/camino_minimo.h"

CaminoMinimo::CaminoMinimo(Lista<Vertice> *vertices, int** matrizAdyacencia) {
    this -> vertices = vertices;
    this -> matrizAdyacencia = matrizAdyacencia;
    cantidadVertices = vertices -> obtenerCantidadDeElementos();
}