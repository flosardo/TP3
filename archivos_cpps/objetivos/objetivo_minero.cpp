#include "../../archivos_h/objetivos/objetivo_minero.h"

using namespace std;

Objetivo_minero::Objetivo_minero() {
    this -> nombre = NOMBRE_OBJETIVO_MINERO;
    this -> mina_oro_construida = false;
    this -> mina_construida = false;
}

bool Objetivo_minero::se_cumplio_el_objetivo(Jugador* jugador) {
    Edificio** edificios_construidos = jugador -> obtener_edificios_construidos();
    int cantidad_edificios_construidos = jugador -> obtener_construidos();
    int i = 0;
    while(i < cantidad_edificios_construidos && (!this -> mina_oro_construida || !this -> mina_construida)) {
        if (edificios_construidos[i] -> obtener_nombre() == NOMBRE_MINA)
            this -> mina_construida = true;
        else if (edificios_construidos[i] -> obtener_nombre() == NOMBRE_MINA_ORO)
            this -> mina_oro_construida = true;
        i++;
    }
    edificios_construidos = nullptr;
    return this -> mina_oro_construida && this -> mina_construida;
}

void Objetivo_minero::mostrar_progreso() {
    cout << this -> nombre;
    if (!this -> se_cumplio) {
        cout << endl;
        if (!this -> mina_oro_construida) {
            cout << COLOR_DORADO << setw(3) << "|-> " << COLOR_POR_DEFECTO << EMOJI_MINA_ORO << VACIO
            << "Falta una mina de oro por construir sr Minecraft. " << endl;
        }
        if (!this -> mina_construida) {
            cout << COLOR_DORADO << setw(3) << "|-> " << COLOR_POR_DEFECTO << EMOJI_MINA << VACIO
            << "Falta una mina de piedra por construir sr Minecraft. " << endl;
        }
    }else
        cout << VACIO << EMOJI_CHECK << endl;
    cout << endl;
}