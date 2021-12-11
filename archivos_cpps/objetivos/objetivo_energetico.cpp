#include "../../archivos_h/objetivos/objetivo_energetico.h"

using namespace std;

Objetivo_energetico::Objetivo_energetico() {
    this -> nombre = NOMBRE_OBJETIVO_ENERGETICO;
    this -> cantidad_energia = 0;
}

bool Objetivo_energetico::se_cumplio_el_objetivo(Jugador* jugador) {
    this -> cantidad_energia = jugador -> obtener_energia_actual();
    return this -> cantidad_energia == OBJETIVO_ENERGETICO;
}

void Objetivo_energetico::mostrar_progreso() {
    cout << "Faltan: " << OBJETIVO_ENERGETICO - this -> cantidad_energia << " de energía para lograr el objetivo" << endl;
}