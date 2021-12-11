#include "../../archivos_h/grafos/dijkstra.h"
#include "../../archivos_h/grafos/camino_minimo.h"

using namespace std;

#include <iostream>

Dijkstra::Dijkstra(Lista* vertices, int **matriz_adyacencia) : Camino_minimo(vertices, matriz_adyacencia) {
    this -> vertices_visitados = new bool[this -> cantidad_vertices];
    this -> distancia = new int[this -> cantidad_vertices];
    this -> recorrido = new int[this -> cantidad_vertices];
}

void Dijkstra::camino_minimo(int origen, int destino) {
    inicializar_visitados(origen);
    inicializar_distancia(matriz_adyacencia[origen]);
    inicializar_recorrido(origen);

    int minimo_vertice;

    bool destino_arribado = origen == destino;
    int vertices_recorridos = 1;
    while(!destino_arribado){
        //mostrar_iteracion(vertices_recorridos - 1);
        minimo_vertice = vertice_minima_distancia();
        destino_arribado = minimo_vertice == destino;

        if(!destino_arribado){
            vertices_visitados[minimo_vertice] = true;
            actualizar_distancia(minimo_vertice);
        }
        vertices_recorridos++;
    }

    mostrar_recorrido(origen, destino);
}

int Dijkstra::vertice_minima_distancia() {
    int minima_distancia = INFINITO;
    int minimo_vertice;

    for(int i = 0; i < this -> cantidad_vertices; i++){
        if(!vertices_visitados[i] && this -> distancia[i] <= minima_distancia){
            minima_distancia = this -> distancia[i];
            minimo_vertice = i;
        }
    }

    return minimo_vertice;
}

void Dijkstra::inicializar_visitados(int origen) {
    for(int i = 0; i < this -> cantidad_vertices; i++)
        this -> vertices_visitados[i] = false;
    this -> vertices_visitados[origen] = true;
}

void Dijkstra::inicializar_recorrido(int origen) {
    for(int i = 0; i < this -> cantidad_vertices; i++)
        this -> recorrido[i] = origen;
}

void Dijkstra::inicializar_distancia(const int * distancia_origen) {
    for(int i = 0; i < this -> cantidad_vertices; i++)
        this -> distancia[i] = distancia_origen[i];
}

void Dijkstra::actualizar_distancia(int vertice) {
    for(int i = 0; i < this -> cantidad_vertices; i++){
        if(!this -> vertices_visitados[i] && this -> distancia[vertice] != INFINITO && this -> distancia[i] > this -> matriz_adyacencia[vertice][i] + this -> distancia[vertice]){
            this -> distancia[i] = this -> matriz_adyacencia[vertice][i] + this -> distancia[vertice];
            this -> recorrido[i] = vertice;
        }
    }
}

void Dijkstra::mostrar_recorrido(int origen, int destino) {
    if(this -> distancia[destino] == INFINITO){
        cout << "No hay un camino que conecte " <<  this -> vertices -> obtener_nombre(origen + 1) << " con " << this -> vertices -> obtener_nombre(destino + 1);
    }else{
        cout << "El camino minimo que une " <<  this -> vertices -> obtener_nombre(origen + 1) << " con " << this -> vertices -> obtener_nombre(destino + 1);
        cout << " tiene un costo de: " << distancia[destino] << " y es el siguiente: ";
        cout << this -> vertices -> obtener_nombre(destino + 1);
        do{
            destino = recorrido[destino];
            cout << " <- " << this -> vertices -> obtener_nombre(destino + 1);
        }while(origen != destino);
    }
    cout << endl;
}

void Dijkstra::mostrar_iteracion(int iteracion) {
    cout << endl << "Iteración " << iteracion << endl;

    cout << "Visitados: [";
    for(int i = 0; i < this -> cantidad_vertices; i++){
        cout << this -> vertices_visitados[i];
        if(i + 1 != this -> cantidad_vertices){
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "Distancia: [";
    for(int i = 0; i < this -> cantidad_vertices; i++){
        if(this -> distancia[i] != INFINITO) {
            cout << this -> distancia[i];
        } else {
            cout << "∞";
        }
        if(i + 1 != this -> cantidad_vertices){
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "Recorrido: [";
    for(int i = 0; i < this -> cantidad_vertices; i++){
        cout << vertices -> obtener_nombre(recorrido[i] + 1);
        if(i + 1 != this -> cantidad_vertices){
            cout << ", ";
        }
    }
    cout << "]" << endl << endl;
}

Dijkstra::~Dijkstra() {
    delete[] this -> vertices_visitados;
    delete[] this -> distancia;
    delete[] this -> recorrido;
}