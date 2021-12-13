#include "../../archivos_h/grafos/dijkstra.h"

Dijkstra::Dijkstra(Lista<Vertice> *vertices, int **matrizAdyacencia) : CaminoMinimo(vertices, matrizAdyacencia) {
    verticesVisitados = new bool[cantidadVertices];
    distancia = new int[cantidadVertices];
    recorrido = new int[cantidadVertices];
}

void Dijkstra::caminoMinimo(int & energia_consumida, int origen, int destino) {
    inicializarVisitados(origen);
    inicializarDistancia(matrizAdyacencia[origen]);
    inicializarRecorrido(origen);

    int minimoVertice;

    bool destinoArribado = origen == destino;
    int verticesRecorridos = 1;
    while(!destinoArribado) {
        minimoVertice = verticeMinimaDistancia();
        destinoArribado = minimoVertice == destino;

        if (!destinoArribado) {
            verticesVisitados[minimoVertice] = true;
            actualizarDistancia(minimoVertice);
        }
        verticesRecorridos++;
    }
    energia_consumida = this -> distancia[destino];
    cout << "Energia: " << energia_consumida << endl;
    mostrarRecorrido(origen, destino);

}

int Dijkstra::verticeMinimaDistancia() {
    int minimaDistancia = INFINITO;
    int minimoVertice;

    for(int i = 0; i < cantidadVertices; i++) {
        if (!verticesVisitados[i] && distancia[i] <= minimaDistancia) {
            minimaDistancia = distancia[i];
            minimoVertice = i;
        }
    }

    return minimoVertice;
}

void Dijkstra::inicializarVisitados(int origen) {
    for(int i = 0; i < cantidadVertices; i++)
        verticesVisitados[i] = false;
    verticesVisitados[origen] = true;
}

void Dijkstra::inicializarRecorrido(int origen) {
    for(int i = 0; i < cantidadVertices; i++)
        recorrido[i] = origen;
}

Dijkstra::~Dijkstra() {
    delete [] verticesVisitados;
    delete [] distancia;
    delete [] recorrido;
}

void Dijkstra::inicializarDistancia(const int * distanciaOrigen) {
    for(int i = 0; i < cantidadVertices; i++)
        distancia[i] = distanciaOrigen[i];
}

void Dijkstra::actualizarDistancia(int vertice) {
    for(int i = 0; i < cantidadVertices; i++) {
        if (!verticesVisitados[i] && distancia[vertice] != INFINITO && distancia[i] > matrizAdyacencia[vertice][i] + distancia[vertice]) {
            distancia[i] = matrizAdyacencia[vertice][i] + distancia[vertice];
            recorrido[i] = vertice;
        }
    }
}

void Dijkstra::mostrarRecorrido(int origen, int destino) {
    if (distancia[destino] == INFINITO) {
        cout << "No hay un camino que conecte " <<  vertices->obtenerNombre(origen + 1) << " con " << vertices->obtenerNombre(destino + 1);
    }else{
        cout << "El camino minimo que une " <<  vertices->obtenerNombre(origen + 1) << " con " << vertices->obtenerNombre(destino + 1);
        cout << " tiene un costo de: " << distancia[destino] << " y es el siguiente: ";
        cout << vertices->obtenerNombre(destino + 1);
        do{
            destino = recorrido[destino];
            cout << " <- " << vertices->obtenerNombre(destino + 1);
        }while(origen != destino);
    }
    cout << endl;
}