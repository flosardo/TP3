#include "../archivos_h/juego/andypolis.h"

Mapa* Andypolis::devolver_mapa(){
    return this -> mapa;
}

void Andypolis::determinar_turno() {
    if (this -> jugador_actual -> obtener_nombre() == JUGADOR_1) {
        this -> jugador_actual = this -> jugador_2;
    }
    else {
        this -> jugador_actual = this -> jugador_1;
    }
}