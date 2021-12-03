#include "../../archivos_h/objetivos/objetivo_minero.h"

using namespace std;

Objetivo_minero::Objetivo_minero() {
    this -> nombre = NOMBRE_OBJETIVO_MINERO;
    this -> mina_oro_construida = false;
    this -> mina_construida = false;
}

bool Objetivo_minero::se_cumplio_el_objetivo(string nombre) {
    if (nombre == NOMBRE_MINA)
        this -> mina_construida = true;
    else if (nombre == NOMBRE_MINA_ORO)
        this -> mina_oro_construida = true;

    return this -> mina_oro_construida && this -> mina_construida;
}

void Objetivo_minero::mostrar_progreso() {
    if (!this -> mina_oro_construida)
        cout << "Falta una " << NOMBRE_MINA_ORO << " por construir" << endl;
    if (!this -> mina_construida)
        cout << "Falta una " << NOMBRE_MINA << " por construir" << endl;
}