#include "../../archivos_h/objetivos/objetivo_letrado.h"

using namespace std;

Objetivo_letrado::Objetivo_letrado(int cantidad_maxima_escuelas) {
    this -> nombre = NOMBRE_OBJETIVO_LETRADO;
    this -> cantidad_maxima_escuelas = cantidad_maxima_escuelas;
}

bool Objetivo_letrado::se_cumplio_el_objetivo(Jugador* jugador) {
    Edificio** edificios_construidos = jugador -> obtener_edificios_construidos();
    int cantidad_escuela = 0;
    int cantidad_edificios_construidos = jugador -> obtener_construidos();
    int i = 0;
    while(cantidad_escuela < this -> cantidad_maxima_escuelas && i < cantidad_edificios_construidos) {
        if(edificios_construidos[i] -> obtener_nombre() == NOMBRE_ESCUELA){
            cantidad_escuela++;
        }
        i++;
    }
    return this -> cantidad_escuelas_construidas == cantidad_maxima_escuelas;
}

void Objetivo_letrado::mostrar_progreso() {
    cout << "Faltan: " << this -> cantidad_maxima_escuelas - this -> cantidad_escuelas_construidas << " escuelas para lograr el objetivo" << endl;
}