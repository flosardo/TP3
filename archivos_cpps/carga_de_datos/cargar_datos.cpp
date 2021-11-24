#include "../../archivos_h/carga_de_datos/cargar_ubicaciones.h"

using namespace std;

Cargar_ubicaciones::Cargar_ubicaciones(){
    this -> archivo_ruta = RUTA_UBICACIONES;
}

bool Cargar_ubicaciones::carga_ubicaciones(Andypolis* Andypolis) {
    ifstream archivo_ubicaciones(this -> archivo_ruta);
    bool existe_el_archivo = (bool) archivo_ubicaciones;
    int fila;
    int columna;
    string nombre;
    while(existe_el_archivo && !archivo_ubicaciones.eof()){
        
    }
    return existe_el_archivo;
}