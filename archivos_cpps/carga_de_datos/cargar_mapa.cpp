#include "../../archivos_h/carga_de_datos/cargar_mapa.h"

using namespace std;

Cargar_mapa::Cargar_mapa() {
    this -> archivo_ruta = RUTA_MAPA;
}

void Cargar_mapa::carga_mapa(Mapa* mapa) {
    ifstream archivo_mapa(this -> archivo_ruta);
    if (!archivo_mapa) {
        cout << COLOR_ROJO << "El archivo_mapa de mapa no existe. Para continuar, crealo y volve a correr el programa." << COLOR_POR_DEFECTO << endl;
        exit(1);
    }

    int cantidad_filas;
    int cantidad_columnas;
    archivo_mapa >> cantidad_filas >> cantidad_columnas;

    mapa -> crear_mapa(cantidad_filas, cantidad_columnas);
    procesar_archivo(archivo_mapa, mapa, cantidad_filas, cantidad_columnas);
    archivo_mapa.close();
} 

void Cargar_mapa::procesar_archivo(ifstream & archivo_mapa, Mapa* mapa, int cantidad_filas, int cantidad_columnas) {
    char caracter;
    for (int fila = 0; fila < cantidad_filas; fila++) {
        for (int columna = 0; columna < cantidad_columnas; columna++) {
            archivo_mapa >> caracter;
            mapa -> inicializar_casillero(caracter, fila, columna);
        }
    }
}