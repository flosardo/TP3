#ifndef _GRAFO_H_
#define _GRAFO_H_

#include "camino_minimo.h"
//#include "Floyd.h"

class Grafo {

    private:

        int ** matriz_de_adyacencia;
        Lista* vertices;
        Camino_minimo* algoritmo_camino_minimo;

        //pre: tienen que existir tanto el origen como el destino. Ademas se deben haber calculado las matrices de Floyd
        //post: muestra el camino minimo entre el origen y el destino
        void camino_minimo(int origen, int destino);

        //post: agranda dinamicamente la matriz de adyacencia
        void agrandar_matriz_de_adyacencia();

        //pre: la matriz que se le envie ya debe tener memoria reservada
        //post: copia la matriz de adyacencia en la nueva matriz
        void copiar_matriz_adyacente(int** nuevaAdyacente);

        //post inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito
        void inicializar_nuevo_vertice(int** nuevaAdyacente);

        //post libera la memoria de la matriz de adyacencia
        void liberar_matriz_adyacencia();

        //post: imprime por pantalla los vertices del grafo
        void mostrar_vertices();

        //post: imprime por pantalla la matriz de adyacencia
        void mostrar_matriz_adyacencia();

    public:

        Grafo();
        //pre: No hay vertices repetidos en nombre
        //post: agrega un nuevo vertice al grafo
        void agregar_vertice(std::string nuevoVertice);

        //pre: se debe tener un algortimo para calcular el camino mínimo previamente elegido
        //post: muestra por terminal el camino mínimo desde un origen a un destino
        void camino_minimo(std::string origen, std::string destino);

        //pre: el peso es un valor positivo
        //post: Ajusta la matriz de adyacencia con el peso_1 o peso_2 dependiendo el caso.
        void agregar_camino(std::string origen, std::string destino, int peso_1, int peso_2);

        //post: imprime por pantalla el grafo
        void mostrar_grafo();

        //post: selecciona el algortimo de Floyd para calcular el camino mínimo
        void usar_floyd();

        //post: selecciona el algortimo de Dijkstra para calcular el camino mínimo
        void usar_dijkstra();

        ~Grafo();
};

#endif //_GRAFO_H_