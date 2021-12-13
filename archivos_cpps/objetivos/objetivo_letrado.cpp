#include "../../archivos_h/objetivos/objetivo_letrado.h"

using namespace std;

Objetivo_letrado::Objetivo_letrado(int cantidad_maxima_escuelas) {
    this -> nombre = NOMBRE_OBJETIVO_LETRADO;
    this -> cantidad_maxima_escuelas = cantidad_maxima_escuelas;
}

bool Objetivo_letrado::se_cumplio_el_objetivo(Jugador* jugador) {
    Edificio** edificios_construidos = jugador -> obtener_edificios_construidos();
    int cantidad_edificios_construidos = jugador -> obtener_construidos();
    int i = 0;
    while(this -> cantidad_escuelas_construidas < this -> cantidad_maxima_escuelas && i < cantidad_edificios_construidos) {
        if (edificios_construidos[i] -> obtener_nombre() == NOMBRE_ESCUELA) {
            this -> cantidad_escuelas_construidas++;
        }
        i++;
    }
    edificios_construidos = nullptr;
    return this -> cantidad_escuelas_construidas == cantidad_maxima_escuelas;
}

void Objetivo_letrado::mostrar_progreso() {
    cout << this -> nombre;
    if (!this -> se_cumplio) {
        cout << endl;
        cout << COLOR_DORADO << setw(3) << "|-> " << COLOR_POR_DEFECTO << EMOJI_ESCUELA << VACIO
        << this -> cantidad_maxima_escuelas - this -> cantidad_escuelas_construidas << " Escuelas faltantes por construir, mucha FIUBA" << endl;
    }
    else
        cout << VACIO << EMOJI_CHECK << endl;
    cout << endl;
}