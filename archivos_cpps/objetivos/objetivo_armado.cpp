#include "../../archivos_h/objetivos/objetivo_armado.h"

using namespace std;

Objetivo_armado::Objetivo_armado(){
    this -> nombre = NOMBRE_OBJETIVO_ARMADO;
    this -> cantidad_bombas = 0;
}

bool Objetivo_armado::se_cumplio_el_objetivo(int cantidad){
    this -> cantidad_bombas = cantidad;
    return this -> cantidad_bombas >= OBJETIVO_ARMADO;
}

void Objetivo_armado::mostrar_progreso(){
    cout << "Faltan: " << OBJETIVO_ARMADO - this -> cantidad_bombas << " bombas para lograr el objetivo." << endl;
}
