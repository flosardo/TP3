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
    while(existe_el_archivo && !archivo_ubicaciones.eof()){
        mapa -> 
    }

    return existe_el_archivo;
}