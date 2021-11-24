#include "../../archivos_h/carga_de_datos/cargar_mapa.h"

using namespace std;

Cargar_mapa::Cargar_mapa() {
    this -> archivo_ruta = RUTA_MAPA;
}

bool Cargar_mapa::carga_mapa(Andypolis* Andypolis, Mapa mapa) {
    ifstream archivo_mapa(RUTA_MAPA);
    if (!archivo_mapa) {
        cout << COLOR_ROJO << "El archivo_mapa de mapa no existe. Para continuar, crealo y volve a correr el programa." << COLOR_POR_DEFECTO << endl;
        exit(1);
    }

    char caracter;
    int cantidad_filas;
    int cantidad_columnas;
    archivo_mapa >> cantidad_filas;
    archivo_mapa >> cantidad_columnas;
    //this -> crear_mapa(fila, col);
    for (int fila = 0; fila < cantidad_filas; fila++) {
        for (int columna = 0; columna < cantidad_columnas; columna++) {
            archivo_mapa >> caracter;
            if (caracter == 'T')
            {
                this->mapa[fila][columna] = new Casillero_construible(caracter);
            }
            else if (caracter == 'C')
            {
                this->mapa[fila][columna] = new Casillero_transitable(caracter);
            }
            else if (caracter == 'L')
            {
                this->mapa[fila][columna] = new Casillero_inaccesible(caracter);
            }
        }
    }
    archivo_mapa.close();
} 