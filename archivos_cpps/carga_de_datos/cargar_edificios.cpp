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
    int piedra_necesaria;
    int madera_necesaria;
    int metal_necesario;
    int permitidos;

    while (archivo_edificios >> nombre_edificio >> segunda_palabra) {
        if ((nombre_edificio == NOMBRE_MINA && segunda_palabra == NOMBRE_ORO) || nombre_edificio == NOMBRE_PLANTA) {
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

void Cargar_edificios::crear_edificio(Abb* arbol , string nombre_edificio, int piedra, int madera, int metal, int permitidos) {
    Edificio* nuevo_edificio = 0;
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
    else if (nombre_edificio == NOMBRE_PLANTA_ELECTRICA)
        nuevo_edificio = new Planta_electrica(piedra, madera, metal, permitidos);
    
    arbol -> agregar_nodo(nuevo_edificio);
    nuevo_edificio = 0;
}