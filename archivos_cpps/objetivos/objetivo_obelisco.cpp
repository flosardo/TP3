#include "../../archivos_h/objetivos/objetivo_obelisco.h"

using namespace std;

Objetivo_obelisco::Objetivo_obelisco() {
    this -> nombre = NOMBRE_OBJETIVO_OBELISCO;
    this -> obelisco_construido = false;
}

bool Objetivo_obelisco::se_cumplio_el_objetivo(string nombre) {
    if (nombre == NOMBRE_OBELISCO)
        this -> obelisco_construido = true;

    return this -> obelisco_construido;
}

void Objetivo_obelisco::mostrar_progreso() {
    cout << "Falta un " << NOMBRE_OBELISCO << " por construir" << endl;
}