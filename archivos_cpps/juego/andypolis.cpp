#include "../../archivos_h/juego/andypolis.h"

using namespace std;

Andypolis::Andypolis() {
    this -> edificios_disponibles = new Abb();
    this -> mapa = new Mapa();
    this -> jugador_1 = new Jugador();
    this -> jugador_2 = new Jugador();
    this -> jugador_actual = this -> jugador_1;
    this -> funciones_auxiliares = Auxiliares_andypolis(this -> edificios_disponibles, this -> mapa);
}

Mapa* Andypolis::devolver_mapa() {
    return this -> mapa;
}

Abb* Andypolis::devolver_arbol() {
    return this -> edificios_disponibles;
}

void Andypolis::listar_edificios(Jugador* jugador) {
    this -> edificios_disponibles -> mostrar_arbol(jugador);
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
    else {
        this -> funciones_auxiliares.modificar_materiales_necesarios(edificio_a_modificar);
        cout << COLOR_VERDE << "Se modificaron los materiales necesarios satisfactoriamente" << COLOR_POR_DEFECTO << endl;
    }
}

Jugador* Andypolis::devolver_jugador_actual() {
    return this -> jugador_actual;
}

void Andypolis::comenzar_partida(){}

void Andypolis::mostrar_mapa(){
    this -> mapa -> mostrar_mapa();
}

void Andypolis::construir_edificio(string edificio, Jugador* jugadors){}

void Andypolis::listar_mis_edificios(Jugador* jugador){}

void Andypolis::demoler_edificio(std::string edificio, Jugador* jugador){}

void Andypolis::atacar_edificio(Jugador* jugador){}

void Andypolis::reparar_edificio(Jugador* jugador){}

void Andypolis::comprar_bombas(Jugador* jugador){}

void Andypolis::consultar_coordenada(Jugador* jugador){}

void Andypolis::mostrar_inventario(Jugador* jugador){}

void Andypolis::mostrar_objetivos(Jugador* jugador){}

void Andypolis::recolectar_recursos(Jugador* jugador){}

void Andypolis::moverse(Jugador* jugador){}

void Andypolis::finalizar_turno(){}

void Andypolis::guardar_y_salir(){}

Jugador* Andypolis::devolver_jugador(string numero_jugador) {
    return numero_jugador == NUMERO_JUGADOR_1 ? this -> jugador_1 : this -> jugador_2;
}

Andypolis::~Andypolis() {}