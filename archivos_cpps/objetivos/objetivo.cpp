#include "../../archivos_h/objetivos/objetivo.h"

using namespace std;

Objetivo::Objetivo() {
    this -> nombre = VACIO;
    this -> se_cumplio = false;
}

string Objetivo::obtener_nombre() {
    return (this -> nombre);
}

void Objetivo::cambiar_estado_construido(string nombre) {}

Objetivo::~Objetivo() {}