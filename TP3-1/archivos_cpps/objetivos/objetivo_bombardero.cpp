#include "../../archivos_h/objetivos/objetivo_bombardero.h"

using namespace std;

Objetivo_bombardero::Objetivo_bombardero(){
    this -> nombre = NOMBRE_OBJETIVO_BOMBARDERO;
    this -> cantidad_bombardero = 0;
}

bool Objetivo_bombardero::se_cumplio_el_objetivo(int cantidad){
    this -> cantidad_bombardero += cantidad;
    return this -> cantidad_bombardero >= OBJETIVO_BOMBARDERO;
}

void Objetivo_bombardero::mostrar_progreso(){
    cout << "Faltan: " << OBJETIVO_BOMBARDERO - this -> cantidad_bombardero << " bombas para lograr el objetivo" << endl;
}
