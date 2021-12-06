#include "../../archivos_h/juego/andypolis.h"

using namespace std;

Andypolis::Andypolis() {
    this -> edificios_disponibles = new Abb();
    this -> mapa = new Mapa();
    this -> jugador_1 = new Jugador();
    this -> jugador_2 = new Jugador();
    this -> jugador_actual = this -> jugador_1;
    this -> funciones_auxiliares = Auxiliares_andypolis(this -> edificios_disponibles, this -> mapa, this -> jugador_actual, this -> jugador_1, this -> jugador_2);
}

Mapa* Andypolis::devolver_mapa() {
    return this -> mapa;
}

Abb* Andypolis::devolver_arbol() {
    return this -> edificios_disponibles;
}

void Andypolis::verificar_energia(int & opcion_ingresada) {
    if (this -> jugador_actual -> obtener_energia_actual() == 0) {
        opcion_ingresada = 12;
        cout << this -> jugador_actual -> obtener_codigo_emoji() << COLOR_ROJO << "Te quedaste sin energia :( Ahora es turno del siguiente jugador" << COLOR_POR_DEFECTO << endl;
        sleep(3);
    }
}

void Andypolis::listar_edificios() {
    this -> edificios_disponibles -> mostrar_arbol(this -> jugador_actual);
}

void Andypolis::cambiar_turno() {
    this -> jugador_actual = this -> jugador_actual == this -> jugador_1 ? this -> jugador_2 : this -> jugador_1;
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
    Jugador* jugador = nullptr;
    string nombre_jugador_1;
    string nombre_jugador_2;
    string convencion_jugador;
    int* coordenadas = 0;
    bool jugador_1_ubicado = false;
    bool jugador_2_ubicado = false;
    this -> funciones_auxiliares.seleccionar_jugador(nombre_jugador_1, nombre_jugador_2);
    while (!jugador_1_ubicado || !jugador_2_ubicado) {
        convencion_jugador = nombre_jugador_1 == NUMERO_JUGADOR_1 ? JUGADOR_1 : JUGADOR_2;
        coordenadas = this -> funciones_auxiliares.pedir_coordenadas();
        int fila = coordenadas[INDICE_FILA];
        int columna = coordenadas[INDICE_COLUMNA];
        if (!jugador_1_ubicado) {
            jugador = jugador_1;
            jugador -> establecer_nombre(nombre_jugador_1);
            jugador_1_ubicado = true;
        }else if(!jugador_2_ubicado) {
            convencion_jugador = convencion_jugador == JUGADOR_1 ? JUGADOR_2 : JUGADOR_1;
            jugador = jugador_2;
            jugador -> establecer_nombre(nombre_jugador_2);
            jugador_2_ubicado = true;
        }
        jugador -> establecer_coordenadas(fila, columna);
        jugador -> establecer_codigo_emoji(convencion_jugador);
        jugador_1_ubicado = this -> mapa -> ubicar_jugador(jugador, fila, columna);
        if(jugador_1_ubicado)
            cout << "Siguiente jugador" << endl;
        
    }
}

void Andypolis::mostrar_mapa() {
    this -> mapa -> mostrar_mapa();
}

void Andypolis::construir_edificio() {
    if (this -> funciones_auxiliares.hay_energia_suficiente(ENERGIA_CONSTRUIR_EDIFICIO, this -> jugador_actual -> obtener_energia_actual())) {
        string edificio_a_construir = this -> funciones_auxiliares.pedir_nombre_edificio();
        this -> funciones_auxiliares.construir_edificio_auxiliar(edificio_a_construir);
    }
}

void Andypolis::listar_mis_edificios() {
    this -> jugador_actual -> listar_construidos();
}

void Andypolis::comprar_bombas() {
    if (this -> funciones_auxiliares.hay_energia_suficiente(ENERGIA_COMPRAR_BOMBA, this -> jugador_actual -> obtener_energia_actual())) {
        int bombas_a_comprar;
        cout << "Ingrese la cantidad de bombas que quiere comprar: " << endl;
        cin >> bombas_a_comprar;

        Inventario* inventario = this -> jugador_actual -> obtener_inventario();
        Material* andycoins = inventario -> obtener_material(ANDYCOINS);
        if (this -> funciones_auxiliares.es_posible_comprar_bombas(bombas_a_comprar, andycoins -> obtener_cantidad())) {
            inventario -> modificar_cantidad_material(ANDYCOINS, - COSTO_ANDYCOINS_BOMBA);
            inventario -> modificar_cantidad_material(BOMBA, bombas_a_comprar);
            this -> jugador_actual -> modificar_energia(-ENERGIA_COMPRAR_BOMBA);
            cout << "Compro " << bombas_a_comprar << " bomba(s) y le quedan " << andycoins -> obtener_cantidad() << " Andyconis" << endl;
        }
    }
}
 
void Andypolis::consultar_coordenada() {
    int* coordenadas = this -> funciones_auxiliares.pedir_coordenadas();
    this -> mapa -> consultar_coordenada(coordenadas[INDICE_FILA], coordenadas[INDICE_COLUMNA]);
}

void Andypolis::mostrar_inventario() {
    this -> jugador_actual -> obtener_inventario() -> mostrar_inventario();
}

void Andypolis::finalizar_turno() {
    this -> jugador_actual -> modificar_energia(ENERGIA_FINALIZAR_TURNO);
    this -> cambiar_turno();
}

Jugador* Andypolis::devolver_jugador(string numero_jugador) {
    return numero_jugador == NUMERO_JUGADOR_1 ? this -> jugador_1 : this -> jugador_2;
}

//Pendientes por implementar.

void Andypolis::mostrar_objetivos() {}

void Andypolis::recolectar_recursos() {}

void Andypolis::moverse() {}

void Andypolis::guardar_y_salir() {}

void Andypolis::demoler_edificio() {}

void Andypolis::atacar_edificio() {}

void Andypolis::reparar_edificio() {}

Andypolis::~Andypolis() {}