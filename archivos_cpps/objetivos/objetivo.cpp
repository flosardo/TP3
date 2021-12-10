#include "../../archivos_h/objetivos/objetivo.h"
#include "../../archivos_h/jugador.h"

using namespace std;

Objetivo::Objetivo() {
    nombre = VACIO;
}

string Objetivo::obtener_nombre() {
    return (this -> nombre);
}

void Objetivo::cambiar_estado_construido(string nombre) {}