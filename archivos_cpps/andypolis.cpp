#include "../archivos_h/juego/andypolis.h"

Mapa* Andypolis::devolver_mapa() {
    return this -> mapa;
}

void Andypolis::determinar_turno() {
    // Creo que directamente se puede hacer this -> jugador_actual == this -> jugador_1 (osea comparar los punteros)
    if (this -> jugador_actual -> obtener_nombre() == JUGADOR_1) {
        this -> jugador_actual = this -> jugador_2;
    }
    else {
        this -> jugador_actual = this -> jugador_1;
    }
    /*
    La idea sería que al iniciar el juego se le asigne uno que empiece por defecto,
    (creo que hay que hacerlo de forma aleatoria con el rand), osea:
    int empieza = 1 + (rand() % 2);
    if (empieza == 1) {
        this -> jugador_actual = this -> jugador_1
    }
    else {
        this -> jugador_actual = this -> jugador_2
    }
    jugador_actual, jugador_1 y jugador_2 son atributos de Andypolis (Lo aclaro por si están despistados)
    podría hacerse un método para esto o hacerlo en el método comenzar_partida que ya definieron en andypolis.h
    */
}