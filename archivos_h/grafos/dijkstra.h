#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include "camino_minimo.h"

class Dijkstra : public CaminoMinimo{
//Atributos
private:
    bool * verticesVisitados;
    int * distancia;
    int * recorrido;

//Métodos
    //post: pone todos los valores del vector de verticesVisitados en "false" menos el origen
    void inicializarVisitados(int origen);

    //post: pone las distancias exactamente igual que la distanciaOrigen
    void inicializarDistancia(const int * distanciaOrigen);

    //post: llena el vector de recorrido con el origen
    void inicializarRecorrido(int origen);

    //post: devuelve el número de vértice con menor distancia al origen
    int verticeMinimaDistancia();

    //post: actualiza el vector de distancias y el de recorrido con los valores que impone vertice.
    void actualizarDistancia(int vertice);

    //pre: para que tenga sentido, debe ejecutarse un recorrido previamente
    //post: muestra por pantalla el resultado del recorrido.
    void mostrarRecorrido(int origen, int destino);

    //post: muestra el estado instantaneo del vector de recorrido, distancia y visitados.
    void mostrarIteracion(int iteracion);

public:

    Dijkstra(Lista<Vertice> * vertices, int ** matrizAdyacencia);

    //post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    void caminoMinimo(int & energia_consumida, int origen, int destino) override;

    ~Dijkstra() override;

};

#endif //_DIJKSTRA_H_