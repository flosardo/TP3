#ifndef _GRAFO_H_
#define _GRAFO_H_

#include "camino_minimo.h"
#include "dijkstra.h"

class Grafo {

    private:

        int** matriz_de_adyacencia;
        Lista <Vertice>* vertices;
        Camino_minimo* algoritmo_camino_minimo;

        /*
        *Pre: Tienen que existir tanto el origen como el destino. Ademas se deben haber calculado las matrices de Floyd.
        *Post: Muestra el camino minimo entre el origen y el destino.
        */
        void camino_minimo(int & energia_consumida, int origen, int destino);
        
        /*
        *Post: Agranda dinamicamente la matriz de adyacencia.
        */
        void agrandar_matriz_de_adyacencia();

        /*
        *Pre: La matriz que se le envie ya debe tener memoria reservada.
        *Post: copia la matriz de adyacencia en la nueva matriz.
        */
        void copiar_matriz_adyacente(int** nuevaAdyacente);
        
        /*
        *Post: Inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito.
        */
        void inicializar_nuevo_vertice(int **nuevaAdyacente);
        
        /*
        *Post Libera la memoria de la matriz de adyacencia.
        */
        void liberar_matriz_adyacencia();

    public:
        
        /*
        *Post: Creará un objeto de tipo grafo con sus valores por defecto.
        */
        Grafo();

        /*
        *Pre: No hay vertices repetidos en nombre.
        *Post: Agrega un nuevo vertice al grafo.
        */
        void agregar_vertice(std::string nuevoVertice);
    
        /*
        *Pre: Se debe tener un algortimo para calcular el camino mínimo previamente elegido.
        *Post: Muestra por terminal el camino mínimo desde un origen a un destino.
        */
        void camino_minimo(int &energia_consumida, std::string origen, std::string destino);
    
        /*
        *Pre: El peso es un valor positivo.
        *Post: Ajusta la matriz de adyacencia con el peso ingresado.
        */
        void agregar_camino(std::string origen, std::string destino, int peso_1, int peso_2);
        
        /*
        *Post: Selecciona el algortimo de Dijkstra para calcular el camino mínimo.
        */
        void usar_dijkstra();
        
        /*
        *Post: Liberará la memoria utilizada por el programa.
        */
        ~Grafo();

};

#endif //_GRAFO_H_