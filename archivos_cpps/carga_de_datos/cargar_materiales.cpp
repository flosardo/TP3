#include "../../archivos_h/carga_de_datos/cargar_materiales.h"

using namespace std;

Cargar_materiales::Cargar_materiales(){
    this -> archivo_ruta = RUTA_MATERIALES;
}

void Cargar_materiales::carga_materiales(Jugador* jugador_1, Jugador* jugador_2){
    ifstream archivo_materiales(this -> archivo_ruta);
    if (!archivo_materiales) {
        cout << COLOR_ROJO << "El archivo_materiales de materiales no existe. Para continuar, crealo y volve a correr el programa." << COLOR_POR_DEFECTO << endl;
        exit(1);
    }

    string nombre;
    int cantidad_jugador_1;
    int cantidad_jugador_2;

    while(archivo_materiales >> nombre >> cantidad_jugador_1 >> cantidad_jugador_2)
        procesar_archivo(nombre, cantidad_jugador_1, cantidad_jugador_2, jugador_1, jugador_2);

    archivo_materiales.close();
}

void Cargar_materiales::procesar_archivo(string nombre, int cantidad_jugador_1, int cantidad_jugador_2, Jugador* jugador_1, Jugador* jugador_2){
    Material* material_jugador_1 = 0;
    Material* material_jugador_2 = 0;

    if (nombre == ANDYCOINS) {
        material_jugador_1 = new Andycoins(cantidad_jugador_1);
        material_jugador_2 = new Andycoins(cantidad_jugador_2);
    } else if (nombre == MADERA) {
        material_jugador_1 = new Madera(cantidad_jugador_1);
        material_jugador_2 = new Madera(cantidad_jugador_2);
    } else if (nombre == METAL) {
        material_jugador_1 = new Metal(cantidad_jugador_1);
        material_jugador_2 = new Metal(cantidad_jugador_2);
    } else if (nombre == PIEDRA) {
        material_jugador_1 = new Piedra(cantidad_jugador_1);
        material_jugador_2 = new Piedra(cantidad_jugador_2);
    } else {
        material_jugador_1 = new Bomba(cantidad_jugador_1);
        material_jugador_2 = new Bomba(cantidad_jugador_2);
    }

    jugador_1 -> cargar_material(material_jugador_1);
    jugador_2 -> cargar_material(material_jugador_2);
}