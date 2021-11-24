#include "../../archivos_h/carga_de_datos/cargar_ubicaciones.h"

using namespace std;

Cargar_ubicaciones::Cargar_ubicaciones(){
    this -> archivo_ruta = RUTA_UBICACIONES;
}

bool Cargar_ubicaciones::carga_ubicaciones(Mapa* mapa){
    ifstream archivo_ubicaciones(this -> archivo_ruta);
    bool existe_el_archivo = (bool) archivo_ubicaciones;
    string fila;
    string columna;
    string nombre;
    int jugador = 0;
    while(existe_el_archivo && !archivo_ubicaciones.eof()) {
        getline(archivo_ubicaciones, nombre, '(');
        getline(archivo_ubicaciones, fila, ',');
        getline(archivo_ubicaciones, columna, ')');
        if (nombre == "1 " || nombre == "2 ") {
            jugador = stoi(nombre);
            mapa -> posicionar_jugador(/*OBJETO JUGADOR*/);
        }
        else if (jugador)
            mapa -> agregar_edificio_casillero(/*OBJETO EDIFICIO*/, stoi(fila), stoi(columna));
        else
            mapa -> agregar_material_casillero(/*OBJETO MATERIAL*/, stoi(fila), stoi(columna));
    }

    /*
    HAY QUE PONER IF ELSE IF PARA VER QUE OBJETO MATERIAL Y QUE OBJETO EDIFICIO HAY QUE CREAR
    */

    return existe_el_archivo;
}