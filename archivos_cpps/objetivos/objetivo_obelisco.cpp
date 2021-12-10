#include "../../archivos_h/objetivos/objetivo_obelisco.h"

using namespace std;

Objetivo_obelisco::Objetivo_obelisco() {
    this -> nombre = NOMBRE_OBJETIVO_OBELISCO;
    this -> obelisco_construido = false;
}


void Objetivo_obelisco::mostrar_progreso() {
    cout << "Falta un " << NOMBRE_OBELISCO << " por construir" << endl;
}