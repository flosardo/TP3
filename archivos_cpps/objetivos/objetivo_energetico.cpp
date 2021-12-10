#include "../../archivos_h/objetivos/objetivo_energetico.h"

using namespace std;

Objetivo_energetico::Objetivo_energetico() {
    this -> nombre = NOMBRE_OBJETIVO_ENERGETICO;
}

bool Objetivo_energetico::se_cumplio_el_objetivo(int cantidad) {
    return cantidad == OBJETIVO_ENERGETICO;
}

void Objetivo_energetico::mostrar_progreso(int cantidad) {
    cout << "Faltan: " << OBJETIVO_ENERGETICO - cantidad << " de energía para lograr el objetivo" << endl;
}