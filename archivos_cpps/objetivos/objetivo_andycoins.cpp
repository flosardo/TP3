#include "../../archivos_h/objetivos/objetivo_andycoins.h"

using namespace std;

Objetivo_andycoins::Objetivo_andycoins() {
    this -> nombre = NOMBRE_OBJETIVO_ANDYCOINS;
}

bool Objetivo_andycoins::se_cumplio_el_objetivo(int cantidad) {
    return (cantidad >= OBJETIVO_ANDYCOINS);
}

void Objetivo_andycoins::mostrar_progreso(int cantidad) {
    cout << "Faltan: " << OBJETIVO_ANDYCOINS - cantidad << " andycoins para lograr el objetivo" << endl;
}
