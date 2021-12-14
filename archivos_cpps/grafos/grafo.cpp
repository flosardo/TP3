#include "../../archivos_h/grafos/grafo.h"
#include "../../archivos_h/grafos/dijkstra.h"

#include <iostream>

using namespace std;

Grafo::Grafo() {
    this -> matriz_de_adyacencia = nullptr;
    this -> vertices = new Lista<Vertice>();
    this -> algoritmo_camino_minimo = nullptr;
}

void Grafo::agregar_vertice(string nuevo_vertice) {
    agrandar_matriz_de_adyacencia();
    this -> vertices -> agregar(nuevo_vertice);
}

void Grafo::agregar_camino(string origen, string destino, int peso_1, int peso_2) {
    int posicion_origen = this -> vertices -> obtener_posicion(origen);
    int posicion_destino = this -> vertices -> obtener_posicion(destino);

    if (posicion_origen == POSICION_NO_ENCONTRADA)
        cout << COLOR_ROJO << "El vertice " << origen << " no existe en el grafo" << COLOR_POR_DEFECTO << endl;

    if (posicion_destino == POSICION_NO_ENCONTRADA)
        cout << COLOR_ROJO << "El vertice " << destino << " no existe en el grafo" << COLOR_POR_DEFECTO << endl;
    
    if (!(posicion_destino == POSICION_NO_ENCONTRADA || posicion_origen == POSICION_NO_ENCONTRADA)) {
        this -> matriz_de_adyacencia[posicion_origen][posicion_destino] = peso_2;
        this -> matriz_de_adyacencia[posicion_destino][posicion_origen] = peso_1;
    }
}

void Grafo::camino_minimo(int & energia_consumida, string origen, string destino) {
    int posicion_origen = this -> vertices -> obtener_posicion(origen);
    int posicion_destino = this -> vertices -> obtener_posicion(destino);

    if (posicion_origen == POSICION_NO_ENCONTRADA)
        cout << COLOR_ROJO << "El vertice " << origen << " no existe en el grafo" << COLOR_POR_DEFECTO << endl;
    
    if (posicion_destino == POSICION_NO_ENCONTRADA)
        cout << COLOR_ROJO << "El vertice " << destino << " no existe en el grafo" << COLOR_POR_DEFECTO << endl;
    
    camino_minimo(energia_consumida, posicion_origen, posicion_destino);
}

void Grafo::agrandar_matriz_de_adyacencia() {
    int** matriz_auxiliar;
    int nueva_cantidad_de_vertices = this -> vertices -> obtener_cantidad_de_elementos() + 1;

    matriz_auxiliar = new int*[nueva_cantidad_de_vertices];

    for(int i = 0; i < nueva_cantidad_de_vertices; i++)
        matriz_auxiliar[i] = new int[nueva_cantidad_de_vertices];

    copiar_matriz_adyacente(matriz_auxiliar);
    inicializar_nuevo_vertice(matriz_auxiliar);
    liberar_matriz_adyacencia();
    this -> matriz_de_adyacencia = matriz_auxiliar;
}

void Grafo::copiar_matriz_adyacente(int** nueva_adyacente) {
    for(int i = 0; i < this -> vertices -> obtener_cantidad_de_elementos(); i++) {
        for(int j = 0; j < this -> vertices -> obtener_cantidad_de_elementos(); j++)
            nueva_adyacente[i][j] = this -> matriz_de_adyacencia[i][j];
    }
}

void Grafo::inicializar_nuevo_vertice(int** nueva_adyacente) {
    for(int i = 0; i < this -> vertices -> obtener_cantidad_de_elementos(); i++) {
        nueva_adyacente[this -> vertices -> obtener_cantidad_de_elementos()][i] = INFINITO;
        nueva_adyacente[i][this -> vertices -> obtener_cantidad_de_elementos()] = INFINITO;
    }
    nueva_adyacente[this -> vertices -> obtener_cantidad_de_elementos()][vertices -> obtener_cantidad_de_elementos()] = 0;
}

void Grafo::liberar_matriz_adyacencia() {
    for(int i = 0; i < this -> vertices -> obtener_cantidad_de_elementos(); i++)
        delete [] this -> matriz_de_adyacencia[i];
    
    delete [] this -> matriz_de_adyacencia;
}

Grafo::~Grafo() {
    liberar_matriz_adyacencia();
    this -> matriz_de_adyacencia = nullptr;
    delete this -> vertices;
    delete this -> algoritmo_camino_minimo;
}

void Grafo::camino_minimo(int & energia_consumida, int origen, int destino) {
    return this -> algoritmo_camino_minimo -> camino_minimo(energia_consumida, origen, destino);
}

void Grafo::usar_dijkstra() {
    delete this -> algoritmo_camino_minimo;
    this -> algoritmo_camino_minimo = new Dijkstra(vertices, matriz_de_adyacencia);
}