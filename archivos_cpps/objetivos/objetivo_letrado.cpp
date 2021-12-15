#include "../../archivos_h/objetivos/objetivo_letrado.h"

using namespace std;

Objetivo_letrado::Objetivo_letrado(int cantidad_maxima_escuelas) {
    this -> nombre = NOMBRE_OBJETIVO_LETRADO;
    this -> se_cumplio = false;
    this -> cantidad_escuelas_construidas = 0;
    this -> cantidad_maxima_escuelas = cantidad_maxima_escuelas;
}

bool Objetivo_letrado::se_cumplio_objetivo(Jugador* jugador) {
    if (!this -> se_cumplio) {
        Edificio** edificios_construidos = jugador -> obtener_edificios_construidos();
        int cantidad_edificios_construidos = jugador -> obtener_construidos();
        int cantidad_escuelas = 0;
        int i = 0;
        while(cantidad_escuelas < this -> cantidad_maxima_escuelas && i < cantidad_edificios_construidos) {
            if (edificios_construidos[i] -> obtener_nombre() == NOMBRE_ESCUELA)
                cantidad_escuelas++;
            i++;
        }
        this -> cantidad_escuelas_construidas = cantidad_escuelas;
        edificios_construidos = nullptr;
        this -> se_cumplio = this -> cantidad_escuelas_construidas == this -> cantidad_maxima_escuelas;
    }
    return this -> se_cumplio;
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