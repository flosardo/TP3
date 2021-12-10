#include "../../archivos_h/objetivos/objetivo_cansado.h"

using namespace std;

Objetivo_cansado::Objetivo_cansado() {
    this -> nombre = NOMBRE_OBJETIVO_CANSADO;
}

bool Objetivo_cansado::se_cumplio_el_objetivo(int cantidad) {
    return cantidad == OBJETIVO_CANSADO;
}

void Objetivo_cansado::mostrar_progreso(int cantidad) {
    cout << "Faltan: " << OBJETIVO_CANSADO - cantidad << " de energía para lograr el objetivo" << endl;
}