#include "../../archivos_h/carga_de_datos/cargar_ubicaciones.h"

using namespace std;

Cargar_ubicaciones::Cargar_ubicaciones() {
    this -> archivo_ruta = RUTA_UBICACIONES;
}

bool Cargar_ubicaciones::carga_ubicaciones(Mapa* mapa, Jugador* jugador_1, Jugador* jugador_2) {
    ifstream archivo_ubicaciones(this -> archivo_ruta);
    bool existe_el_archivo = false;
    string nombre;
    string convencion_jugador = " ";
    while (getline(archivo_ubicaciones, nombre, '(')) {
        existe_el_archivo = true;
        procesar_archivo(archivo_ubicaciones, mapa, jugador_1, jugador_2, nombre, convencion_jugador);
    }
    archivo_ubicaciones.close();
    return existe_el_archivo;
}

void Cargar_ubicaciones::procesar_archivo(ifstream & archivo_ubicaciones, Mapa* mapa, Jugador* jugador_1, Jugador* jugador_2, string nombre, string & convencion_jugador) {
    int fila;
    int columna;
    string basura;
    Jugador* jugador;
    archivo_ubicaciones >> fila >> basura >> columna >> basura;
    archivo_ubicaciones.ignore();
    nombre.pop_back();

    if (nombre == NUMERO_JUGADOR_1 || nombre == NUMERO_JUGADOR_2) {
        convencion_jugador = nombre == NUMERO_JUGADOR_1 ? JUGADOR_1 : JUGADOR_2;
        jugador = nombre == NUMERO_JUGADOR_1 ? jugador_1 : jugador_2;
        jugador -> establecer_nombre(nombre);
        jugador -> establecer_coordenadas(fila, columna);
        jugador -> establecer_codigo_emoji(convencion_jugador);
        mapa -> se_ubico_jugador(jugador, fila, columna);
    }
    else if (convencion_jugador != " ") {
        Edificio* edificio_creado = crear_edificio(nombre, fila, columna);
        mapa -> se_ubico_edificio(edificio_creado, fila, columna);
        this -> cargar_edificio_en_jugador(edificio_creado, jugador_1, jugador_2, convencion_jugador);
        edificio_creado = nullptr;
    } 
    else
        mapa -> se_ubico_material(crear_material(nombre), fila, columna);
    jugador = nullptr;
}

void Cargar_ubicaciones::cargar_edificio_en_jugador(Edificio* edificio, Jugador* jugador_1, Jugador* jugador_2, string convencion) {
    Jugador* jugador = convencion == JUGADOR_1 ? jugador_1 : jugador_2;
    jugador -> cargar_edificio(edificio);
    jugador = nullptr;
}

void Cargar_ubicaciones::guardar_ubicaciones(Mapa* mapa, Jugador* jugador_1, Jugador* jugador_2) {
    int* coordenadas_jugador_1 = jugador_1 -> obtener_coordenadas();
    if (coordenadas_jugador_1[INDICE_FILA] >= 0) {
        ofstream archivo_ubicaciones(this -> archivo_ruta);
        this -> guardar_materiales_lluvia(archivo_ubicaciones, mapa);
        this -> guardar_jugador(archivo_ubicaciones, jugador_1);
        this -> guardar_jugador(archivo_ubicaciones, jugador_2);
        archivo_ubicaciones.close();
    }
    coordenadas_jugador_1 = nullptr;
}

void Cargar_ubicaciones::guardar_materiales_lluvia(ofstream & archivo_ubicaciones, Mapa* mapa) {
    int* dimensiones_mapa = mapa -> obtener_dimensiones();
    Material* material = nullptr;
    for (int fila = 0; fila < dimensiones_mapa[INDICE_FILA]; fila++) {
        for (int columna = 0; columna < dimensiones_mapa[INDICE_COLUMNA]; columna++) {
            material = mapa -> obtener_material(fila, columna);
            if (material)
                archivo_ubicaciones << material -> obtener_nombre_material() << VACIO << '(' << fila << ", " << columna << ')' << endl;
        }
    }
    dimensiones_mapa = nullptr;
}

void Cargar_ubicaciones::guardar_jugador(ofstream & archivo_ubicaciones, Jugador* jugador) {
    int* coordenadas_jugador = jugador -> obtener_coordenadas();
    archivo_ubicaciones << jugador -> obtener_nombre() << VACIO << '(' << coordenadas_jugador[INDICE_FILA] << ", " << coordenadas_jugador[INDICE_COLUMNA] << ')' << endl;

    int cantidad_edificios = jugador -> obtener_construidos();
    Edificio** edificios = jugador -> obtener_edificios_construidos();
    string nombre_edificio;
    int* coordenadas_edificio = 0;
    for (int i = 0; i < cantidad_edificios; i++) {
        nombre_edificio = edificios[i] -> obtener_nombre();
        coordenadas_edificio = edificios[i] -> obtener_coordenadas();
        archivo_ubicaciones << nombre_edificio << VACIO << '(' << coordenadas_edificio[INDICE_FILA] << ", " << coordenadas_edificio[INDICE_COLUMNA] << ')' << endl;
    }
    coordenadas_jugador = nullptr;
    edificios = nullptr;
}

Edificio* Cargar_ubicaciones::crear_edificio(string nombre, int fila, int columna) {
    Edificio* edificio_creado = nullptr;
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
    else if (nombre == PLANTA_ELECTRICA) 
        edificio_creado = new Planta_electrica(fila, columna);
    else if (nombre == NOMBRE_MINA_ORO) 
        edificio_creado = new Mina_oro(fila, columna);
    return edificio_creado;
}

Material* Cargar_ubicaciones::crear_material(string nombre) {
    Material* material_creado = nullptr;
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