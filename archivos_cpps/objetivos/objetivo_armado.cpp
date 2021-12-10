#include "../../archivos_h/objetivos/objetivo_armado.h"

using namespace std;

Objetivo_armado::Objetivo_armado() {
    this -> nombre = NOMBRE_OBJETIVO_ARMADO;

}

bool Objetivo_armado::se_cumplio_el_objetivo(int cantidad) {
    return (cantidad >= OBJETIVO_ARMADO);
}

void Objetivo_armado::mostrar_progreso(int cantidad_bombas) {
    cout << "Faltan: " << OBJETIVO_ARMADO - cantidad_bombas << " bombas para lograr el objetivo." << endl;
}
