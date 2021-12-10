#include "../../archivos_h/objetivos/objetivo_extremista.h"

using namespace std;

Objetivo_extremista::Objetivo_extremista() {
    this -> nombre = NOMBRE_OBJETIVO_EXTREMISTA;
}

bool Objetivo_extremista::se_cumplio_el_objetivo(int cantidad) {
    return cantidad >= OBJETIVO_EXTREMISTA;
}

void Objetivo_extremista::mostrar_progreso(int cantidad) {
    cout << "Faltan: " << OBJETIVO_EXTREMISTA - cantidad << " bombas para lograr el objetivo" << endl;
}