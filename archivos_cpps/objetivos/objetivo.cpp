#include "../../archivos_h/objetivos/objetivo.h"

using namespace std;

Objetivo::Objetivo() {
    nombre = VACIO;
}

string Objetivo::obtener_nombre() {
    return (this -> nombre);
}

bool Objetivo::se_cumplio_el_objetivo(int cantidad) {
    return false;
}

void Objetivo::mostrar_progreso(int cantidad) {}

void Objetivo::mostrar_progreso() {}

bool Objetivo::se_cumplio_el_objetivo(string nombre) {
    return false;
}

bool Objetivo::se_cumplio_el_objetivo(Edificio** edicificios_construidos){

}

void Objetivo::cambiar_estado_construido(string nombre) {}