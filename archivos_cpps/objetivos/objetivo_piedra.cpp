#include "../../archivos_h/objetivos/objetivo_piedra.h"

using namespace std;

Objetivo_piedra::Objetivo_piedra() {
    this -> nombre = NOMBRE_OBJETIVO_PIEDRA;
}

bool Objetivo_piedra::se_cumplio_el_objetivo(int cantidad) {
    return cantidad >= OBJETIVO_PIEDRA;
}

void Objetivo_piedra::mostrar_progreso(int cantidad) {
    cout << "Faltan: " << OBJETIVO_PIEDRA - cantidad << " piedras para lograr el objetivo." << endl;
}