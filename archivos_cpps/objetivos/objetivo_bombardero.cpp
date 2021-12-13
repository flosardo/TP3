#include "../../archivos_h/objetivos/objetivo_bombardero.h"

using namespace std;

Objetivo_bombardero::Objetivo_bombardero() {
    this -> nombre = NOMBRE_OBJETIVO_BOMBARDERO;
    this -> cantidad_bombardero = 0;
}

bool Objetivo_bombardero::se_cumplio_el_objetivo(Jugador* jugador) {
    this -> cantidad_bombardero += jugador -> obtener_bombas_usadas();
    return this -> cantidad_bombardero >= OBJETIVO_BOMBARDERO;
}

void Objetivo_bombardero::mostrar_progreso() {
    cout << this -> nombre;
    if (!this -> se_cumplio) {
        cout << endl;
        cout << COLOR_DORADO << setw(3) << "|-> " << COLOR_POR_DEFECTO << EMOJI_BOMBA << VACIO
        << OBJETIVO_BOMBARDERO - this -> cantidad_bombardero << VACIO << " Bombas faltantes para tener un ADN explosivo" << endl;
    }else
        cout << VACIO << EMOJI_CHECK << endl;
    cout << endl;
}
