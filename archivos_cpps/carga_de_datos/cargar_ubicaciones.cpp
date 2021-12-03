#include "../../archivos_h/carga_de_datos/cargar_ubicaciones.h"

using namespace std;

Cargar_ubicaciones::Cargar_ubicaciones() {
    this -> archivo_ruta = RUTA_UBICACIONES;
}

bool Cargar_ubicaciones::carga_ubicaciones(Mapa* mapa, Jugador* jugador_1, Jugador* jugador_2) {
    ifstream archivo_ubicaciones(this -> archivo_ruta);
    bool existe_el_archivo = false;
    string nombre;
    char convencion_jugador = VACIO;
    while (getline(archivo_ubicaciones, nombre, '(')) {
        existe_el_archivo = true;
        procesar_archivo(archivo_ubicaciones, mapa, jugador_1, jugador_2, nombre, convencion_jugador);
    }
    archivo_ubicaciones.close();
    return existe_el_archivo;
}

void Cargar_ubicaciones::procesar_archivo(ifstream & archivo_ubicaciones, Mapa* mapa, Jugador* jugador_1, Jugador* jugador_2, string nombre, char & convencion_jugador) {
    int fila;
    int columna;
    string basura;
    archivo_ubicaciones >> fila;
    archivo_ubicaciones >> basura;
    archivo_ubicaciones >> columna;
    archivo_ubicaciones >> basura;
    archivo_ubicaciones.ignore();
    nombre.pop_back();

    if (nombre == NUMERO_JUGADOR_1 || nombre == NUMERO_JUGADOR_2) {
        convencion_jugador = nombre == NUMERO_JUGADOR_1 ? JUGADOR_1 : JUGADOR_2;
        mapa -> posicionar_jugador(new Jugador(convencion_jugador, fila, columna), fila, columna);
    }
    else if (convencion_jugador != VACIO) {
        Edificio* edificio_creado = crear_edificio(nombre, fila, columna);
        mapa -> agregar_edificio_casillero(edificio_creado, fila, columna);
        this -> cargar_edificio_en_jugador(edificio_creado, jugador_1, jugador_2, convencion_jugador);
    } 
    else {
        Material* material_creado = crear_material(nombre);
        mapa -> agregar_material_casillero(material_creado, fila, columna);
    }
}

void Cargar_ubicaciones::cargar_edificio_en_jugador(Edificio* edificio, Jugador* jugador_1, Jugador* jugador_2, char convencion) {
    Jugador* jugador = convencion == JUGADOR_1 ? jugador_1 : jugador_2;
    jugador -> cargar_edificio(edificio);
    jugador = nullptr;
}

Edificio* Cargar_ubicaciones::crear_edificio(string nombre, int fila, int columna) {
    Edificio* edificio_creado = 0;
    if (nombre == NOMBRE_ASERRADERO)
        edificio_creado = new Aserradero(fila, columna);
    else if (nombre == NOMBRE_ESCUELA) 
        edificio_creado = new Escuela(fila, columna);
    else if (nombre == NOMBRE_FABRICA) 
        edificio_creado = new Fabrica(fila, columna);
    else if (nombre == NOMBRE_MINA) 
        edificio_creado = new Mina(fila, columna);
    else if (nombre == NOMBRE_OBELISCO) 
        edificio_creado = new Obelisco(fila, columna);
    else if (nombre == NOMBRE_PLANTA_ELECTRICA) 
        edificio_creado = new Planta_electrica(fila, columna);
    else if (nombre == NOMBRE_MINA_ORO) 
        edificio_creado = new Mina_oro(fila, columna);

    return edificio_creado;
}

Material* Cargar_ubicaciones::crear_material(string nombre) {
    Material* material_creado = 0;
    if (nombre == PIEDRA) 
        material_creado = new Piedra();
    else if (nombre == MADERA)
        material_creado = new Madera();
    else if (nombre == METAL) 
        material_creado = new Metal();
    else if (nombre == ANDYCOINS) 
        material_creado = new Andycoins();
    
    return material_creado;
}