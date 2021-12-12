#ifndef _GRAFO_H_
#define _GRAFO_H_

#include "camino_minimo.h"
#include "floyd.h"

class Grafo {
/*ATRIBUTOS*/
private:
    int ** matrizDeAdyacencia;
    Lista<Vertice> * vertices;
    CaminoMinimo * algoritmoCaminoMinimo;

/*MÉTODOS*/

    //pre: tienen que existir tanto el origen como el destino. Ademas se deben haber calculado las matrices de Floyd
    //post: muestra el camino minimo entre el origen y el destino
    void caminoMinimo(int origen, int destino);

    //post: agranda dinamicamente la matriz de adyacencia
    void agrandarMatrizDeAdyacencia();

    //pre: la matriz que se le envie ya debe tener memoria reservada
    //post: copia la matriz de adyacencia en la nueva matriz
    void copiarMatrizAdyacente(int** nuevaAdyacente);

    //post inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito
    void inicializarNuevoVertice(int** nuevaAdyacente);

    //post libera la memoria de la matriz de adyacencia
    void liberarMatrizAdyacencia();

    //post: imprime por pantalla los vertices del grafo
    void mostrarVertices();

    //post: imprime por pantalla la matriz de adyacencia
    void mostrarMatrizAdyacencia();
public:

    Grafo();
    //pre: No hay vertices repetidos en nombre
    //post: agrega un nuevo vertice al grafo
    void agregarVertice(std::string nuevoVertice);

    //pre: se debe tener un algortimo para calcular el camino mínimo previamente elegido
    //post: muestra por terminal el camino mínimo desde un origen a un destino
    void caminoMinimo(std::string origen, std::string destino);

    //pre: el peso es un valor positivo
    //post: Ajusta la matriz de adyacencia con el peso ingresado
    void agregarCamino(std::string origen, std::string destino, int peso);

    //post: imprime por pantalla el grafo
    void mostrarGrafo();

    //post: selecciona el algortimo de Floyd para calcular el camino mínimo
    void usarFloyd();

    //post: selecciona el algortimo de Dijkstra para calcular el camino mínimo
    void usarDijkstra();

    ~Grafo();
};

#endif //_GRAFO_H_