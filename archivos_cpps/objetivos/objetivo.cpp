#include "../../archivos_h/objetivos/objetivo.h"

using namespace std;

Objetivo::Objetivo(){
    nombre = VACIO;
}

string Objetivo::devolver_nombre(){
    return (this -> nombre);
}

bool Objetivo::verificar(int cantidad){
    return false;
}

bool Objetivo::verificar(string nombre){
    return false;
}

void Objetivo::cambiar_estado_construido(string nombre){}