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
        nombre.pop_back();
        if (nombre == "1" || nombre == "2") {
            jugador = stoi(nombre);
            mapa -> posicionar_jugador(/*OBJETO JUGADOR*/);
        }
        else if (jugador) {
            Edificio* edificio_creado = crear_edificio(nombre, jugador);//jugador tendria q ser char
            mapa -> agregar_edificio_casillero(edificio_creado, stoi(fila), stoi(columna));
        }

        else{
            Material* material_creado = crear_material(nombre);
            mapa -> agregar_material_casillero(nombre, stoi(fila), stoi(columna));
        }
    }
    return existe_el_archivo;
}

Edificio* Cargar_ubicaciones::crear_edificio(string nombre, char jugador) {
    Edificio* edificio_creado = 0;
    if (nombre == "aserradero") {
        edificio_creado = new Aserradero(jugador);
    }
    else if (nombre == "escuela") {
        edificio_creado = new Escuela(jugador);
    }
    else if (nombre == "fabrica") {
        edificio_creado = new Fabrica(jugador);
    }
    else if (nombre == "mina") {
        edificio_creado = new Mina(jugador);
    }
    else if (nombre == "obelisco") {
        edificio_creado = new Obelisco(jugador);
    }
    else if (nombre == "planta electrica") {
        edificio_creado = new Planta_electrica(jugador);
    }
    else if (nombre == "mina oro") {
        edificio_creado = new Mina_oro(jugador);
    }
    return edificio_creado;
}

Material* Cargar_ubicaciones::crear_material(string nombre) {
    Material* material_creado = 0;
    if (nombre == "piedra") {
        material_creado = new Piedra();
    }
    else if (nombre == "madera") {
        material_creado = new Madera();
    }
    else if (nombre == "metal") {
        material_creado = new Metal();
    }
    else if (nombre == "andycoins") {
        material_creado = new Andycoins();
    }
    return material_creado;
}
