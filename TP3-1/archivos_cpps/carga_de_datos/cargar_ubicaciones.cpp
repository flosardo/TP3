#include "../../archivos_h/carga_de_datos/cargar_ubicaciones.h"

using namespace std;

Cargar_ubicaciones::Cargar_ubicaciones(){
    this -> archivo_ruta = RUTA_UBICACIONES;
}

bool Cargar_ubicaciones::carga_ubicaciones(Mapa* mapa){
    ifstream archivo_ubicaciones(this -> archivo_ruta);
    bool existe_el_archivo = (bool) archivo_ubicaciones;
    string nombre;
    while(existe_el_archivo && getline(archivo_ubicaciones, nombre, '(')) {
        procesar_archivo(archivo_ubicaciones, mapa, nombre);
    }
    archivo_ubicaciones.close();
    return existe_el_archivo;
}

void Cargar_ubicaciones::procesar_archivo(ifstream & archivo_ubicaciones, Mapa* mapa, string nombre){
    int fila;
    int columna;
    string basura;
    char convencion_jugador = VACIO;
    int numero_jugador = 0;
    archivo_ubicaciones >> fila;
    archivo_ubicaciones >> basura;
    archivo_ubicaciones >> columna;
    archivo_ubicaciones >> basura;
    nombre.pop_back();
    if (nombre == NUMERO_JUGADOR_1 || nombre == NUMERO_JUGADOR_2) {
        if (nombre == NUMERO_JUGADOR_1)
            convencion_jugador = JUGADOR_1;
        else 
            convencion_jugador = JUGADOR_2;
            
        numero_jugador = stoi(nombre);
        mapa -> posicionar_jugador(new Jugador(fila, columna));
    }
    else if (numero_jugador) {
        Edificio* edificio_creado = crear_edificio(nombre, convencion_jugador);
        mapa -> agregar_edificio_casillero(edificio_creado, fila, columna);
    }
    else {
        Material* material_creado = crear_material(nombre);
        mapa -> agregar_material_casillero(material_creado, fila, columna);
    }
}

Edificio* Cargar_ubicaciones::crear_edificio(string nombre, char jugador) {
    Edificio* edificio_creado = 0;
    if (nombre == "aserradero")
        edificio_creado = new Aserradero(jugador);
    else if (nombre == "escuela") 
        edificio_creado = new Escuela(jugador);
    else if (nombre == "fabrica") 
        edificio_creado = new Fabrica(jugador);
    else if (nombre == "mina") 
        edificio_creado = new Mina(jugador);
    else if (nombre == "obelisco") 
        edificio_creado = new Obelisco(jugador);
    else if (nombre == "planta electrica") 
        edificio_creado = new Planta_electrica(jugador);
    else if (nombre == "mina oro") 
        edificio_creado = new Mina_oro(jugador);
    
    return edificio_creado;
}

Material* Cargar_ubicaciones::crear_material(string nombre) {
    Material* material_creado = 0;
    if (nombre == "piedra") 
        material_creado = new Piedra();
    else if (nombre == "madera")
        material_creado = new Madera();
    else if (nombre == "metal") 
        material_creado = new Metal();
    else if (nombre == "andycoins") 
        material_creado = new Andycoins();
    
    return material_creado;
}