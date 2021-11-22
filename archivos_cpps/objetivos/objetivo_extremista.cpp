#include "../../archivos_h/objetivos/objetivo_extremista.h"

using namespace std;

Objetivo_extremista::Objetivo_extremista(){
    this -> nombre = NOMBRE_OBJETIVO_EXTREMISTA;
    this -> cantidad_bombas_compradas = 0;
}

bool Objetivo_extremista::verificar(int cantidad){
    this -> cantidad_bombas_compradas += cantidad;
    return this -> cantidad_bombas_compradas >= OBJETIVO_EXTREMISTA;
}

void Objetivo_extremista::mostrar_progreso(){
    cout << "Faltan: " << OBJETIVO_EXTREMISTA - this -> cantidad_bombas_compradas << " bombas para lograr el objetivo" << endl;
}