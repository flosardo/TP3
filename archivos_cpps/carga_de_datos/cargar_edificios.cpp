#include "../../archivos_h/carga_de_datos/cargar_edificios.h"

using namespace std;

Cargar_edificios::Cargar_edificios() {
    this -> archivo_ruta = RUTA_EDIFICIOS;
}

void Cargar_edificios::carga_edificios(Abb* arbol) {
    ifstream archivo_edificios(this -> archivo_ruta);
    if (!archivo_edificios) {
        cout << COLOR_ROJO << "El archivo de edificios no existe. Para continuar, crealo y volve a correr el programa." << COLOR_POR_DEFECTO << endl;
        exit(1);
    }

    string nombre_edificio;
    string segunda_palabra;
    int piedra_necesaria = 0;
    int madera_necesaria = 0;
    int metal_necesario = 0;
    int permitidos = 0;

    while (archivo_edificios >> nombre_edificio >> segunda_palabra) {
        if (segunda_palabra == NOMBRE_ORO || nombre_edificio == NOMBRE_PLANTA) {
            nombre_edificio += " " + segunda_palabra;
            archivo_edificios >> piedra_necesaria;
        }
        else
            piedra_necesaria =  stoi(segunda_palabra);

        archivo_edificios >> madera_necesaria >> metal_necesario >> permitidos;
        this -> crear_edificio(arbol, nombre_edificio, piedra_necesaria, madera_necesaria, metal_necesario, permitidos);
    }
    archivo_edificios.close();
}

void Cargar_edificios::guardar_edificios(Abb* arbol) {
    ofstream archivo_edificios(this -> archivo_ruta);
    int cantidad_edificios = arbol -> obtener_cantidad_nodos();
    Edificio** edificios = new Edificio*[cantidad_edificios];
    arbol -> cargar_en_arreglo(edificios);

    editar_archivo_edificios(archivo_edificios, edificios, cantidad_edificios);

    archivo_edificios.close();
    delete [] edificios;
    edificios = nullptr;
}

void Cargar_edificios::editar_archivo_edificios(ofstream & archivo_edificios, Edificio** edificios, int cantidad_edificios) {
    for (int i = 0; i < cantidad_edificios; i++) {
        archivo_edificios << edificios[i] -> obtener_nombre() << VACIO
        << edificios[i] -> obtener_cantidad_necesaria(PIEDRA) << VACIO
        << edificios[i] -> obtener_cantidad_necesaria(MADERA) << VACIO
        << edificios[i] -> obtener_cantidad_necesaria(METAL) << VACIO
        << edificios[i] -> obtener_permitidos() << endl;
    }
}

void Cargar_edificios::crear_edificio(Abb* arbol , string nombre_edificio, int piedra, int madera, int metal, int permitidos) {
    Edificio* nuevo_edificio = nullptr;
    if (nombre_edificio == NOMBRE_ASERRADERO)
        nuevo_edificio = new Aserradero(piedra, madera, metal, permitidos);
    else if (nombre_edificio == NOMBRE_ESCUELA)
        nuevo_edificio = new Escuela(piedra, madera, metal, permitidos);
    else if (nombre_edificio == NOMBRE_MINA)
        nuevo_edificio = new Mina(piedra, madera, metal, permitidos);
    else if (nombre_edificio == NOMBRE_MINA_ORO)
        nuevo_edificio = new Mina_oro(piedra, madera, metal, permitidos);
    else if (nombre_edificio == NOMBRE_FABRICA)
        nuevo_edificio = new Fabrica(piedra, madera, metal, permitidos);
    else if (nombre_edificio == NOMBRE_OBELISCO)
        nuevo_edificio = new Obelisco(piedra, madera, metal, permitidos);
    else if (nombre_edificio == PLANTA_ELECTRICA)
        nuevo_edificio = new Planta_electrica(piedra, madera, metal, permitidos);
    
    arbol -> agregar_nodo(nuevo_edificio);
    nuevo_edificio = nullptr;
}