#include "../../archivos_h/grafos/floyd.h"

int** Floyd::crearMatrizCaminos(){

    int ** caminos = new int*[cantidadVertices];
    for(int i = 0; i < cantidadVertices; i++){
        caminos[i] = new int[cantidadVertices];
    }

    for(int i = 0; i < cantidadVertices; i++){
        for(int j = 0; j < cantidadVertices; j++) {
            caminos[i][j] = j;
        }
    }

    return caminos;
}

int ** Floyd::crearMatrizCostos(int ** matrizAdyacencia){

    int ** costos = new int*[cantidadVertices];
    for(int i = 0; i < cantidadVertices; i++){
        costos[i] = new int[cantidadVertices];
    }

    for(int i = 0; i < cantidadVertices; i++){
        for(int j = 0; j < cantidadVertices; j++){
            costos[i][j] = matrizAdyacencia[i][j];
        }
    }
    return costos;
}

void Floyd::calcularMatrices() {

    cantidadVertices = vertices -> obtenerCantidadDeElementos();
    matrizCostos = crearMatrizCostos(matrizAdyacencia);
    matrizCaminos = crearMatrizCaminos();

    for (int verticeIntermedio = 0; verticeIntermedio < cantidadVertices; verticeIntermedio++) {

        for (int origen = 0; origen < cantidadVertices; origen++){

            for (int destino = 0; destino < cantidadVertices; destino++) {

                int costo = matrizCostos[origen][verticeIntermedio] + matrizCostos[verticeIntermedio][destino];

                if (matrizCostos[origen][destino] > costo) {
                    matrizCostos[origen][destino] = costo;
                    matrizCaminos[origen][destino] = matrizCaminos[origen][verticeIntermedio];
                } else if (matrizCostos[origen][destino] == INFINITO){
                    matrizCaminos[origen][destino] = POSICION_NO_ENCONTRADA;
                }

            }

        }
    }

}

void Floyd::caminoMinimo(int & energia_consumida, int origen, int destino) {

    if(matrizCaminos[origen][destino] == POSICION_NO_ENCONTRADA){
        cout << COLOR_ROJO << "No hay un camino que conecte " <<  vertices->obtenerNombre(origen + 1) << " con " << vertices->obtenerNombre(destino + 1);
    }else{
        cout << "El camino minimo que une " <<  vertices->obtenerNombre(origen + 1) << " con " << vertices->obtenerNombre(destino + 1);
        cout << " tiene un costo de: " << matrizCostos[origen][destino] << " y es el siguiente: ";
        cout << vertices->obtenerNombre(origen + 1);
        energia_consumida = matrizCostos[origen][destino];
        do{
            origen = matrizCaminos[origen][destino];
            cout << " -> " << vertices->obtenerNombre(origen + 1);
        }while(origen != destino);
    }
    cout << endl;

}

void Floyd::liberarMatrices() {
    if(matrizCostos != nullptr && matrizCaminos != nullptr){
        for(int i = 0; i < cantidadVertices; i++){
            delete[] matrizCostos[i];
            delete[] matrizCaminos[i];
        }
        delete[] matrizCostos;
        delete[] matrizCaminos;

        matrizCostos = nullptr;
        matrizCaminos = nullptr;
    }
}

Floyd::~Floyd(){
    liberarMatrices();
}

Floyd::Floyd(Lista<Vertice> *vertices, int ** matrizAdyacencia) : CaminoMinimo(vertices, matrizAdyacencia){
    calcularMatrices();
}
