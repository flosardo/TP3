#include "../../archivos_h/grafos/camino_minimo.h"

Camino_minimo::Camino_minimo(Lista <Vertice>* vertices, int** matriz_adyacencia) {
    this -> vertices = vertices;
    this -> matriz_adyacencia = matriz_adyacencia;
    this -> cantidad_vertices = vertices -> obtener_cantidad_de_elementos();
}