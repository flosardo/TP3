#include "../../archivos_h/juego/andypolis.h"

using namespace std;

Andypolis::Andypolis() {
    this -> edificios_disponibles = nullptr;
    this -> mapa = nullptr;
    this -> jugador_1 = nullptr;
    this -> jugador_2 = nullptr;
    this -> jugador_actual = this -> jugador_1;
    this -> funciones_auxiliares = Auxiliares_andypolis(this -> edificios_disponibles, this -> mapa);
}

Mapa* Andypolis::devolver_mapa() {
    return this -> mapa;
}

Abb* Andypolis::devolver_arbol() {
    return this -> edificios_disponibles;
}

void Andypolis::determinar_turno() {
    if (this -> jugador_actual == this -> jugador_1)
        this -> jugador_actual = this -> jugador_2;
    else 
        this -> jugador_actual = this -> jugador_1;
}

void Andypolis::modificar_edificio_nombre(){
    string nombre = this -> funciones_auxiliares.pedir_nombre_edificio();
    Edificio* edificio_a_modificar = this -> edificios_disponibles -> buscar_edificio(nombre);
    
    if(!edificio_a_modificar)
        cout << COLOR_ROJO << "El edificio que desea modificar, no existe :( " << COLOR_POR_DEFECTO << endl;
    else{
        this -> funciones_auxiliares.pedir_nueva_cantidad_material();
    }


}

// void Andypolis::comenzar_partida() {
//     string nombre_1;
//     string nombre_2;
//     this -> funciones_auxiliares.seleccionar_jugador(nombre_1, nombre_2);

// }