#include "../../archivos_h/objetivos/objetivo_bombardero.h"

using namespace std;

Objetivo_bombardero::Objetivo_bombardero() {
    this -> nombre = NOMBRE_OBJETIVO_BOMBARDERO;
    
}

bool Objetivo_bombardero::se_cumplio_el_objetivo(int cantidad) {
    return cantidad >= OBJETIVO_BOMBARDERO;
}

void Objetivo_bombardero::mostrar_progreso(int cantidad) {
    cout << "Faltan: " << OBJETIVO_BOMBARDERO - cantidad << " bombas para lograr el objetivo" << endl;
}
