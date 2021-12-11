#include "../../archivos_h/objetivos/objetivo_obelisco.h"

using namespace std;

Objetivo_obelisco::Objetivo_obelisco() {
    this -> nombre = NOMBRE_OBJETIVO_OBELISCO;
    this -> obelisco_construido = false;
}

bool Objetivo_obelisco::se_cumplio_el_objetivo(Jugador* jugador) {
    Edificio** edificios_construidos = jugador -> obtener_edificios_construidos();
    int cantidad_edificios_construidos = jugador -> obtener_construidos();
    int i = 0;
    while(i < cantidad_edificios_construidos && !this -> obelisco_construido) {
        this -> obelisco_construido = edificios_construidos[i] -> obtener_nombre() == NOMBRE_OBELISCO;
        i++;
    }
    return this -> obelisco_construido;
}

void Objetivo_obelisco::mostrar_progreso() {
    cout << "Falta un " << NOMBRE_OBELISCO << " por construir" << endl;
}