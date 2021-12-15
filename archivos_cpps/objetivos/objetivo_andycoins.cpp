#include "../../archivos_h/objetivos/objetivo_andycoins.h"

using namespace std;

Objetivo_andycoins::Objetivo_andycoins() {
    this -> nombre = NOMBRE_OBJETIVO_ANDYCOINS;
    this -> cantidad_andycoins = 0;
    this -> se_cumplio = false;
}

bool Objetivo_andycoins::se_cumplio_objetivo(Jugador* jugador) {
    if (!this -> se_cumplio) {
        this -> cantidad_andycoins += jugador -> obtener_inventario() -> obtener_material(ANDYCOINS) -> obtener_cantidad();
        this -> se_cumplio = this -> cantidad_andycoins >= OBJETIVO_ANDYCOINS;
    }
    return this -> se_cumplio;
}

void Objetivo_andycoins::mostrar_progreso() {
    cout << this -> nombre;
    if (!this -> se_cumplio) {
        cout << endl;
        cout << COLOR_DORADO << setw(3) << "|-> " << COLOR_POR_DEFECTO << EMOJI_ANDYCOINS << VACIO << OBJETIVO_ANDYCOINS - this -> cantidad_andycoins 
        << VACIO << "Andycoins faltantes para que te pagues la UADE " << endl;
    }
    else
        cout << VACIO << EMOJI_CHECK;
    cout << endl;
}