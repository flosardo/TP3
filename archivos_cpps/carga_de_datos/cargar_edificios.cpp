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

    string nombre_edificio;
    string piedra_necesaria;
    string madera_necesaria;
    string metal_necesario;
    string permitidos;
    while (!archivo_edificios.eof()) {
        getline(archivo_edificios, nombre_edificio, ' ');
        getline(archivo_edificios, piedra_necesaria, ' ');
        getline(archivo_edificios, madera_necesaria, ' ');
        getline(archivo_edificios, metal_necesario, ' ');
        getline(archivo_edificios, permitidos);
        if (nombre_edificio == "mina") {
            if (piedra_necesaria == "oro") {
                nombre_edificio = "mina oro";
                piedra_necesaria = madera_necesaria;
                madera_necesaria = metal_necesario;
                metal_necesario = permitidos;
                permitidos.clear();
            }
        }
        else if (nombre_edificio == "planta") {
            nombre_edificio = "planta electrica";
            piedra_necesaria = madera_necesaria;
            madera_necesaria = metal_necesario;
            metal_necesario = permitidos;
            permitidos.clear();
        }
        this -> crear_edificios(arbol, nombre_edificio, piedra_necesaria, madera_necesaria, metal_necesario, permitidos);
        //this -> procesar_archivo(archivo_edificios, arbol, nombre_edificio);
        
    }
    archivo_edificios.close();
}

void Cargar_edificios::crear_edificios(Abb* arbol ,string nombre_edificio, string piedra_necesaria, string madera_necesaria, string metal_necesario, string permitidos) {
    piedra_necesaria = stoi(piedra_necesaria);
    madera_necesaria = stoi(madera_necesaria);
    metal_necesario = stoi(metal_necesario);
    permitidos = stoi(permitidos);

    Edificio *nuevo_edificio = 0;
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
    
    arbol->agregar_nodo(nuevo_edificio);
}

void Cargar_edificios::procesar_archivo(std::ifstream & archivo_edificios, Abb* arbol, string nombre_edificio){
    unsigned int piedra_necesaria;
    unsigned int madera_necesaria;
    unsigned int metal_necesario;
    unsigned int permitidos;
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