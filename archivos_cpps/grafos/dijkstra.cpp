#include "../../archivos_h/grafos/dijkstra.h"

Dijkstra::Dijkstra(Lista<Vertice> *vertices, int** matriz_adyacencia) : Camino_minimo(vertices, matriz_adyacencia) {
    this -> vertices_visitados = new bool[cantidad_vertices];
    this -> distancia = new int[cantidad_vertices];
    this -> recorrido = new int[cantidad_vertices];
}

void Dijkstra::camino_minimo(int & energia_consumida, int origen, int destino) {
    inicializar_visitados(origen);
    inicializar_distancia(matriz_adyacencia[origen]);
    inicializar_recorrido(origen);

    int minimo_vertice;

    bool destino_arribado = origen == destino;
    int vertices_recorridos = 1;
    while(!destino_arribado) {
        minimo_vertice = vertice_minima_distancia();
        destino_arribado = minimo_vertice == destino;

        if (!destino_arribado) {
            vertices_visitados[minimo_vertice] = true;
            this -> actualizar_distancia(minimo_vertice);
        }
        vertices_recorridos++;
    }
    energia_consumida = this -> distancia[destino];
    cout << "Energia necesaria: " << energia_consumida << endl;
    mostrar_recorrido(origen, destino);

}

int Dijkstra::vertice_minima_distancia() {
    int minima_distancia = INFINITO;
    int minimo_vertice;

    for(int i = 0; i < cantidad_vertices; i++) {
        if (!this -> vertices_visitados[i] && distancia[i] <= minima_distancia) {
            minima_distancia = distancia[i];
            minimo_vertice = i;
        }
    }

    return minimo_vertice;
}

void Dijkstra::inicializar_visitados(int origen) {
    for(int i = 0; i < cantidad_vertices; i++)
        this -> vertices_visitados[i] = false;
    this -> vertices_visitados[origen] = true;
}

void Dijkstra::inicializar_recorrido(int origen) {
    for(int i = 0; i < cantidad_vertices; i++)
        recorrido[i] = origen;
}


void Dijkstra::inicializar_distancia(const int * distancia_origen) {
    for(int i = 0; i < cantidad_vertices; i++)
        distancia[i] = distancia_origen[i];
}

void Dijkstra::actualizar_distancia(int vertice) {
    for(int i = 0; i < cantidad_vertices; i++) {
        if (!this -> vertices_visitados[i] && distancia[vertice] != INFINITO && distancia[i] > matriz_adyacencia[vertice][i] + distancia[vertice]) {
            distancia[i] = matriz_adyacencia[vertice][i] + distancia[vertice];
            recorrido[i] = vertice;
        }
    }
}

void Dijkstra::mostrar_recorrido(int origen, int destino) {
    if (distancia[destino] == INFINITO)
        cout << COLOR_ROJO << "No hay un camino que conecte " <<  vertices -> obtener_nombre(origen + 1) << " con " << vertices -> obtener_nombre(destino + 1);
    else {
        cout << COLOR_MARRON;
        cout << "El camino minimo que une " <<  vertices -> obtener_nombre(origen + 1) << " con " << vertices -> obtener_nombre(destino + 1);
        cout << " tiene un costo de: " << distancia[destino] << " y es el siguiente: ";
        cout << vertices -> obtener_nombre(destino + 1);
        do {
            destino = recorrido[destino];
            cout << " <- " << vertices -> obtener_nombre(destino + 1);
        } while(origen != destino);
    }
    cout << COLOR_POR_DEFECTO << endl;
}

Dijkstra::~Dijkstra() {
    delete [] this -> vertices_visitados;
    delete [] this -> distancia;
    delete [] this -> recorrido;
}