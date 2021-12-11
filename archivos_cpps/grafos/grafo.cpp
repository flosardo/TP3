#include "../../archivos_h/grafos/dijkstra.h"
#include "../../archivos_h/grafos/grafo.h"

#include <iostream>

using namespace std;

Grafo::Grafo() {
    this -> matriz_de_adyacencia = nullptr;
    this -> vertices = new Lista();
    this -> algoritmo_camino_minimo = nullptr;
}

void Grafo::agregar_vertice(string nuevo_vertice) {
    this -> agrandar_matriz_de_adyacencia();
    this -> vertices -> agregar(nuevo_vertice);
}

void Grafo::mostrar_grafo() {
    this -> mostrar_vertices();
    this -> mostrar_matriz_adyacencia();
}

void Grafo::agregar_camino(string origen, string destino, int peso_1, int peso_2) {
    int posicion_origen = this -> vertices -> obtener_posicion(origen);
    int posicion_destino = this -> vertices -> obtener_posicion(destino);

    if(posicion_origen == POSICION_NO_ENCONTRADA)
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    
    if(posicion_destino == POSICION_NO_ENCONTRADA)
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    

    if(!(posicion_destino == POSICION_NO_ENCONTRADA || posicion_origen == POSICION_NO_ENCONTRADA)) {
        this -> matriz_de_adyacencia[posicion_origen][posicion_destino] = peso_1;
        this -> matriz_de_adyacencia[posicion_destino][posicion_origen] = peso_2;
    }
}

void Grafo::camino_minimo(string origen, string destino) { //REVIRSAR, NO HAY CASO BASE (CONDIDICION DE CORTE).
    int posicion_origen = this -> vertices -> obtener_posicion(origen);
    int posicion_destino = this -> vertices -> obtener_posicion(destino);

    if(posicion_origen == POSICION_NO_ENCONTRADA)
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    
    if(posicion_destino == POSICION_NO_ENCONTRADA)
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    

    this -> camino_minimo(posicion_origen, posicion_destino);
}

void Grafo::agrandar_matriz_de_adyacencia() {
    int** matriz_auxiliar;
    int nueva_cantidad_de_vertices = this -> vertices -> obtener_cantidad_elementos() + 1;

    matriz_auxiliar = new int*[nueva_cantidad_de_vertices];
    for(int i = 0; i < nueva_cantidad_de_vertices; i++)
        matriz_auxiliar[i] = new int[nueva_cantidad_de_vertices];
    

    this -> copiar_matriz_adyacente(matriz_auxiliar);
    this -> inicializar_nuevo_vertice(matriz_auxiliar);
    this -> liberar_matriz_adyacencia();
    this -> matriz_de_adyacencia = matriz_auxiliar;
}

void Grafo::copiar_matriz_adyacente(int** nueva_adyacente) {
    for(int i = 0; i < this -> vertices -> obtener_cantidad_elementos(); i++) {
        for(int j = 0; j < this -> vertices -> obtener_cantidad_elementos(); j++)
            nueva_adyacente[i][j] = matriz_de_adyacencia[i][j];
    }
}

void Grafo::inicializar_nuevo_vertice(int** nueva_adyacente) {
    for(int i = 0; i < this -> vertices -> obtener_cantidad_elementos(); i++){
        nueva_adyacente[this -> vertices -> obtener_cantidad_elementos()][i] = INFINITO;
        nueva_adyacente[i][this -> vertices -> obtener_cantidad_elementos()] = INFINITO;
    }
    nueva_adyacente[this -> vertices -> obtener_cantidad_elementos()][this -> vertices -> obtener_cantidad_elementos()] = 0;
}

void Grafo::liberar_matriz_adyacencia() {
    for(int i = 0; i < this -> vertices -> obtener_cantidad_elementos(); i++)
        delete[] this -> matriz_de_adyacencia[i];
    
    delete[] this -> matriz_de_adyacencia;
}

Grafo::~Grafo() {
    this -> liberar_matriz_adyacencia();
    matriz_de_adyacencia = nullptr;
    delete vertices;
    delete algoritmo_camino_minimo;
}

void Grafo::mostrar_vertices() {
    cout << "Lista de vértices: [";
    for(int i = 0; i < this -> vertices -> obtener_cantidad_elementos(); i++){
        cout << this -> vertices -> obtener_nombre(i + 1);
        if(i + 1 != this -> vertices -> obtener_cantidad_elementos())
            cout << ", ";
        
    }
    cout << "]" << endl;
}

/* OJO REVISAR ESTA, DEBERIA ESTAR COMENTADA, PORQUE NUNCA LO VAMOS A MOSTRAR EN EL TP. */
void Grafo::mostrar_matriz_adyacencia() {
    cout << "Matriz de adyacencia:" << endl;
    for(int i = 0; i < this -> vertices -> obtener_cantidad_elementos(); i++){
        for(int j = 0; j < this -> vertices -> obtener_cantidad_elementos() * 2; j++) {
            if(j == this -> vertices -> obtener_cantidad_elementos() * 2 - 1)
                cout << endl;
            else if(j % 2 == 0)
                if(matriz_de_adyacencia[i][j/2] == INFINITO)
                    cout << "∞";
                else
                    cout << matriz_de_adyacencia[i][j/2];
            else
                cout << "|";
        }
    }
    cout << endl;
}

void Grafo::camino_minimo(int origen, int destino) {
    this -> algoritmo_camino_minimo -> camino_minimo(origen, destino);
}

void Grafo::usar_floyd() {
    //delete algoritmo_camino_minimo;
    //algoritmo_camino_minimo = new Floyd(vertices, matriz_de_adyacencia);
}

void Grafo::usar_dijkstra() {
    delete this -> algoritmo_camino_minimo;
    this -> algoritmo_camino_minimo = new Dijkstra(this -> vertices, this -> matriz_de_adyacencia);
}