#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include "camino_minimo.h"

class Dijkstra : public Camino_minimo {

    private:

        bool* vertices_visitados;
        int* distancia;
        int* recorrido;

        /*
        *Post: Pone todos los valores del vector de vertices_visitados en "false" menos el origen.
        */
        void inicializar_visitados(int origen);

        /*
        *Post: Pone las distancias exactamente igual que la distancia_origen.
        */
        void inicializar_distancia(const int * distancia_origen);

        /*
        *Post: Llena el vector de recorrido con el origen.
        */
        void inicializar_recorrido(int origen);

        /*
        *Post: Devuelve el número de vértice con menor distancia al origen.
        */
        int vertice_minima_distancia();

        /*
        *Post: Actualiza el vector de distancias y el de recorrido con los valores que impone vertice.
        */
        void actualizar_distancia(int vertice);

        /*
        *Pre: Para que tenga sentido, debe ejecutarse un recorrido previamente.
        *Post: Muestra por pantalla el resultado del recorrido.
        */
        void mostrar_recorrido(int origen, int destino);

    public:

        /*
        *Pre: Que los parametros no sean null.
        *Post: Creará un objeto de tipo Dijkstra con los parametros recibidos.
        */
        Dijkstra(Lista<Vertice> * vertices, int ** matriz_adyacencia);

        /*
        *Post: Muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso.
        */
        void camino_minimo(int & energia_consumida, int origen, int destino) override;
        
        /*
        *Post: Muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso.
        */
        ~Dijkstra() override;

};

#endif //_DIJKSTRA_H_