#include "../../archivos_h/objetivos/objetivo.h"

using namespace std;

Objetivo::Objetivo() {
    this -> nombre = VACIO;
    this -> se_cumplio = false;
}

bool Objetivo::obtener_estado_objetivo(Jugador* jugador) {
    if(!this -> se_cumplio) 
        this -> se_cumplio = this -> se_cumplio_el_objetivo(jugador);
    return this -> se_cumplio;
}


string Objetivo::obtener_nombre() {
    return (this -> nombre);
}

void Objetivo::cambiar_estado_construido(string nombre) {}