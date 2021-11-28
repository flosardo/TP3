#include "../../archivos_h/carga_de_datos/cargar_edificios.h"

using namespace std;

Cargar_edificios::Cargar_edificios(){
    this -> archivo_ruta = RUTA_EDIFICIOS;
}

void Cargar_edificios::carga_edificios(Abb* arbol){
    ifstream archivo_edificios(this -> archivo_ruta);
    if (!archivo_edificios) {
        cout << COLOR_ROJO << "El archivo de edificios no existe. Para continuar, crealo y volve a correr el programa." << COLOR_POR_DEFECTO << endl;
        exit(1);
    }

    string nombre;
    while (archivo_edificios >> nombre) {

    }
    archivo_edificios.close();
}

void Cargar_edificios::procesar_archivo(std::ifstream & archivo_edificios, Abb* arbol, string nombre_edificio){
    int piedra_necesaria;
    int madera_necesaria;
    int metal_necesario;
    int permitidos;
    archivo_edificios >> piedra_necesaria;
    archivo_edificios >> madera_necesaria;
    archivo_edificios >> metal_necesario;
    archivo_edificios >> permitidos;

    Edificio* nuevo_edificio = 0;
    if (nombre_edificio == NOMBRE_ASERRADERO)
        nuevo_edificio = new Aserradero(piedra_necesaria, madera_necesaria, metal_necesario, permitidos);
    else if (nombre_edificio == NOMBRE_ESCUELA)
        nuevo_edificio = new Escuela(piedra_necesaria, madera_necesaria, metal_necesario, permitidos);
    else if (nombre_edificio == NOMBRE_MINA)
        nuevo_edificio = new Mina(piedra_necesaria, madera_necesaria, metal_necesario, permitidos);
    else if (nombre_edificio == NOMBRE_MINA_ORO)
        nuevo_edificio = new Mina_oro(piedra_necesaria, madera_necesaria, metal_necesario, permitidos);
    else if (nombre_edificio == NOMBRE_FABRICA)
        nuevo_edificio = new Fabrica(piedra_necesaria, madera_necesaria, metal_necesario, permitidos);
    else if (nombre_edificio == NOMBRE_OBELISCO)
        nuevo_edificio = new Obelisco(piedra_necesaria, madera_necesaria, metal_necesario, permitidos);
    else if (nombre_edificio == NOMBRE_PLANTA_ELECTRICA)
        nuevo_edificio = new Planta_electrica(piedra_necesaria, madera_necesaria, metal_necesario, permitidos);

    arbol -> agregar_nodo(nuevo_edificio);
}