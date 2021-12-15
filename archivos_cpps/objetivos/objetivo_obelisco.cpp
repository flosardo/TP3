#include "../../archivos_h/objetivos/objetivo_obelisco.h"

using namespace std;

Objetivo_obelisco::Objetivo_obelisco() {
    this -> nombre = NOMBRE_OBJETIVO_OBELISCO;
    this -> se_cumplio = false;
}

bool Objetivo_obelisco::se_cumplio_objetivo(Jugador* jugador) {
    Edificio** edificios_construidos = jugador -> obtener_edificios_construidos();
    int cantidad_edificios_construidos = jugador -> obtener_construidos();
    int i = 0;
    while(i < cantidad_edificios_construidos && !this -> se_cumplio) {
        this -> se_cumplio = edificios_construidos[i] -> obtener_nombre() == NOMBRE_OBELISCO;
        i++;
    }
    edificios_construidos = nullptr;
    return this -> se_cumplio;
}

void Objetivo_obelisco::mostrar_progreso() {
    if (!this -> se_cumplio) {
        cout << this -> nombre << endl;
        cout << COLOR_DORADO << setw(3) << "|-> " << COLOR_POR_DEFECTO << EMOJI_OBELISCO << VACIO
        << "Falta construir un obelisco, para poder ganar y romper el MC Donald's " << endl;
    }
    cout << endl;
}