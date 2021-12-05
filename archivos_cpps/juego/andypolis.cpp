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

void Andypolis::listar_edificios() {
    this -> edificios_disponibles -> mostrar_arbol(this -> jugador_actual);
}

void Andypolis::determinar_turno() {
    if (this -> jugador_actual == this -> jugador_1)
        this -> jugador_actual = this -> jugador_2;
    else 
        this -> jugador_actual = this -> jugador_1;
}

void Andypolis::modificar_edificio_nombre() {
    string nombre = this -> funciones_auxiliares.pedir_nombre_edificio();
    Edificio* edificio_a_modificar = this -> edificios_disponibles -> buscar_edificio(nombre);
   
    if (!edificio_a_modificar)
        cout << COLOR_ROJO << "El edificio que desea modificar, no existe :( " << COLOR_POR_DEFECTO << endl;
    else {
        this -> funciones_auxiliares.modificar_materiales_necesarios(edificio_a_modificar);
        cout << COLOR_VERDE << "Se modificaron los materiales necesarios satisfactoriamente" << COLOR_POR_DEFECTO << endl;
    }
}

Jugador* Andypolis::devolver_jugador_actual() {
    return this -> jugador_actual;
}

void Andypolis::comenzar_partida() {
    string nombre_jugador_1; // TAL VEZ HAYA QUE PONERLAS EN PROGRAMA
    string nombre_jugador_2;
    int* coordenadas = 0;
    bool jugador_1_ubicado = false;
    bool jugador_2_ubicado = false;
    this -> funciones_auxiliares.seleccionar_jugador(nombre_jugador_1, nombre_jugador_2);
    while (!jugador_1_ubicado || !jugador_2_ubicado) {
        coordenadas = this -> funciones_auxiliares.pedir_coordenadas();
        int fila = coordenadas[INDICE_FILA];
        int columna = coordenadas[INDICE_COLUMNA];
        if (!jugador_1_ubicado) {
            this -> jugador_1 = new Jugador(JUGADOR_1, fila, columna);
            this -> jugador_1 -> establecer_nombre(nombre_jugador_1);
            this -> mapa -> ubicar_jugador(this -> jugador_1, fila, columna);
            jugador_1_ubicado = true;
            cout << "Siguiente jugador" << endl;
        }
        else {
            this -> jugador_2 = new Jugador(JUGADOR_2, fila, columna);
            this -> jugador_2 -> establecer_nombre(nombre_jugador_2);
            this -> mapa -> ubicar_jugador(this -> jugador_2, fila, columna);
            jugador_2_ubicado = true;
        }
    }
}

void Andypolis::mostrar_mapa() {
    this -> mapa -> mostrar_mapa();
}

void Andypolis::construir_edificio() {
    if (this -> funciones_auxiliares.hay_energia_suficiente(ENERGIA_CONSTRUIR_EDIFICIO, jugador_actual -> devolver_energia_actual())) {
        string edificio_a_construir = this -> funciones_auxiliares.pedir_nombre_edificio();
        this -> funciones_auxiliares.validar_construccion(this -> jugador_actual, edificio_a_construir);
    }
}

void Andypolis::listar_mis_edificios() {}

void Andypolis::demoler_edificio() {}

void Andypolis::atacar_edificio() {}

void Andypolis::reparar_edificio() {}

void Andypolis::comprar_bombas() {}

void Andypolis::consultar_coordenada() {}

void Andypolis::mostrar_inventario() {}

void Andypolis::mostrar_objetivos() {}

void Andypolis::recolectar_recursos() {}

void Andypolis::moverse() {}

void Andypolis::finalizar_turno() {}

void Andypolis::guardar_y_salir() {}

Jugador* Andypolis::devolver_jugador(string numero_jugador) {
    return numero_jugador == NUMERO_JUGADOR_1 ? this -> jugador_1 : this -> jugador_2;
}

Andypolis::~Andypolis() {}