#include "../../archivos_h/objetivos/objetivo_letrado.h"

using namespace std;

Objetivo_letrado::Objetivo_letrado(int cantidad_maxima_escuelas) {
    this -> nombre = NOMBRE_OBJETIVO_LETRADO;
    this -> cantidad_maxima_escuelas = cantidad_maxima_escuelas;
}

bool Objetivo_letrado::se_cumplio_el_objetivo(int cantidad) {
    this -> cantidad_escuelas_construidas = cantidad;
    return this -> cantidad_escuelas_construidas == cantidad_maxima_escuelas;
}

void Objetivo_letrado::mostrar_progreso() {
    cout << "Faltan: " << this -> cantidad_maxima_escuelas - this -> cantidad_escuelas_construidas << " escuelas para lograr el objetivo" << endl;
}