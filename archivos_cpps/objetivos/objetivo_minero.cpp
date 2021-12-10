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
    while(i < cantidad_edificios_construidos && !this -> mina_oro_construida && !this -> mina_construida) {
        if (edificios_construidos[i] -> obtener_nombre() == NOMBRE_MINA)
            this -> mina_construida = true;
        else if (edificios_construidos[i] -> obtener_nombre() == NOMBRE_MINA_ORO)
            this -> mina_oro_construida = true;
        i++;
    }
    return this -> mina_oro_construida && this -> mina_construida;
}

void Objetivo_minero::mostrar_progreso() {
    if (!this -> mina_oro_construida)
        cout << "Falta una " << NOMBRE_MINA_ORO << " por construir" << endl;
    if (!this -> mina_construida)
        cout << "Falta una " << NOMBRE_MINA << " por construir" << endl;
}