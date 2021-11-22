#include "../../archivos_h/objetivos/objetivo_cansado.h"

using namespace std;

Objetivo_cansado::Objetivo_cansado(){
    this -> nombre = NOMBRE_OBJETIVO_CANSADO;
    this -> cantidad_energia = 0;
}

bool Objetivo_cansado::verificar(int cantidad){
    this -> cantidad_energia = cantidad;
    return this -> cantidad_energia == OBJETIVO_CANSADO;
}

void Objetivo_cansado::mostrar_progreso(){
    cout << "Faltan: " << OBJETIVO_CANSADO - this -> cantidad_energia << " de energía para lograr el objetivo" << endl;
}