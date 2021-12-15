#include "../../archivos_h/objetivos/objetivo_extremista.h"

using namespace std;

Objetivo_extremista::Objetivo_extremista() {
    this -> nombre = NOMBRE_OBJETIVO_EXTREMISTA;
    this -> se_cumplio = false;
    this -> cantidad_bombas_compradas = 0;
}

bool Objetivo_extremista::se_cumplio_objetivo(Jugador* jugador) {
    if (!this -> se_cumplio) {
        this -> cantidad_bombas_compradas += jugador -> obtener_cantidad_bombas_compradas();
        this -> se_cumplio = this -> cantidad_bombas_compradas >= OBJETIVO_EXTREMISTA;
    }
    return this -> se_cumplio;
}

void Objetivo_extremista::mostrar_progreso() {
    cout << this -> nombre;
    if (!this -> se_cumplio) {
        cout << endl;
        cout << COLOR_DORADO << setw(3) << "|-> " << COLOR_POR_DEFECTO << EMOJI_BOMBA << VACIO
        << OBJETIVO_EXTREMISTA - this -> cantidad_bombas_compradas << " bombas faltantes por comprar, Acaso eres familia de Osama bin Laden ?" << endl;
    }
    else
        cout << VACIO << EMOJI_CHECK << endl;
    cout << endl;
}