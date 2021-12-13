#ifndef _FLOYD_H_
#define _FLOYD_H_

#include "camino_minimo.h"

using namespace std;

class Floyd : public CaminoMinimo{
private:
    int ** matrizCostos;
    int ** matrizCaminos;

    //pre: requiere una matriz de adyacencia bien cargada
    //post: crea la matriz costo inicializandola con los valores de la matriz de adyacencia
    int ** crearMatrizCostos(int ** matrizAdyacencia);

    //post: crea una matriz de caminos
    int ** crearMatrizCaminos();

    //post: libera la memoria de las matrices de costos y caminos
    void liberarMatrices();

    //post: muestra la matriz de costo y de caminos.
    void mostrarMatrices();

    //post:calcula las matrices de costos y caminos.
    void calcularMatrices();

public:
    Floyd(Lista<Vertice> *vertices, int ** matrizAdyacencia);

    //post: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    void caminoMinimo(int & energia_consumida, int origen, int destino) override;

    ~Floyd() override;
};

#endif //_FLOYD_H_