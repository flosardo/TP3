#include "../../archivos_h/objetivos/objetivo_cansado.h"

using namespace std;

Objetivo_cansado::Objetivo_cansado() {
    this -> nombre = NOMBRE_OBJETIVO_CANSADO;
    this -> cantidad_energia = 0;
    this -> se_cumplio = false;
}

bool Objetivo_cansado::se_cumplio_objetivo(Jugador* jugador) {
    if (!this -> se_cumplio) {
        this -> cantidad_energia = jugador -> obtener_energia_actual();
        this -> se_cumplio = this -> cantidad_energia == OBJETIVO_CANSADO;
    }
    return this -> se_cumplio;
}

void Objetivo_cansado::mostrar_progreso() {
    cout << this -> nombre;
    if (!this -> se_cumplio) {
        cout << endl;
        cout << COLOR_DORADO << setw(3) << "|-> " << COLOR_POR_DEFECTO << EMOJI_ENERGIA << VACIO
        << OBJETIVO_CANSADO - this -> cantidad_energia << VACIO << " energía sobrante, ya te queda poco para dormir pa" << endl;
    }
    else
        cout << VACIO << EMOJI_CHECK << endl;
    cout << endl;
}