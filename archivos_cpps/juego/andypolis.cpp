#include "../../archivos_h/juego/andypolis.h"

using namespace std;

Andypolis::Andypolis() {
    this -> edificios_disponibles = new Abb();
    this -> mapa = new Mapa();
    this -> jugador_1 = new Jugador();
    this -> jugador_2 = new Jugador();
    this -> objetivos_1 = new Objetivo*[CANTIDAD_OBJETIVOS_POR_JUGADOR]; 
    this -> objetivos_2 = new Objetivo*[CANTIDAD_OBJETIVOS_POR_JUGADOR]; 
    this -> jugador_actual = this -> jugador_1;
    this -> funciones_auxiliares = Auxiliares_andypolis();
}

void Andypolis::cargar_grafo(Grafo* grafo) {
    this -> funciones_auxiliares.cargar_grafo_auxiliar(grafo, this -> mapa);
}

void Andypolis::inicializar_objetivos() {
    this -> funciones_auxiliares.inicializar_arreglo_objetivos(this -> objetivos_1);
    this -> funciones_auxiliares.inicializar_arreglo_objetivos(this -> objetivos_2);
    this -> funciones_auxiliares.cargar_objetivos(this -> objetivos_1, this -> edificios_disponibles -> buscar_edificio(NOMBRE_ESCUELA) -> obtener_permitidos());
    this -> funciones_auxiliares.cargar_objetivos(this -> objetivos_2, this -> edificios_disponibles -> buscar_edificio(NOMBRE_ESCUELA) -> obtener_permitidos());
}

void Andypolis::asignar_objetivo(Objetivo** objetivos, Objetivo* objetivo, int indice) {
    objetivos[indice] = objetivo;
}

Objetivo** Andypolis::obtener_objetivos() {
    return this -> jugador_actual -> obtener_nombre() == JUGADOR_1 ? this -> objetivos_1 : this -> objetivos_2;
}

bool Andypolis::gano_la_partida() {
    return this -> funciones_auxiliares.gano_la_partida(this -> jugador_actual, this -> obtener_objetivos());
}

void Andypolis::verificar_energia(int & opcion_ingresada) {
    if (!this -> funciones_auxiliares.tiene_energia(this -> jugador_actual))
        opcion_ingresada = OPCION_FINALIZAR_TURNO;
}

Mapa* Andypolis::obtener_mapa() {
    return this -> mapa;
}

Abb* Andypolis::obtener_arbol() {
    return this -> edificios_disponibles;
}

Jugador* Andypolis::obtener_jugador_actual() {
    return this -> jugador_actual;
}

void Andypolis::listar_edificios() {
    this -> edificios_disponibles -> mostrar_arbol(this -> jugador_actual);
}

void Andypolis::modificar_edificio_nombre() {
    string nombre = funciones_auxiliares.pedir_nombre_edificio();
    Edificio* edificio_a_modificar = this -> edificios_disponibles -> buscar_edificio(nombre);
   
    if (!edificio_a_modificar)
        cout << COLOR_ROJO << "El edificio que desea modificar, no existe :( " << COLOR_POR_DEFECTO << endl;
    else {
        funciones_auxiliares.modificar_materiales_necesarios(edificio_a_modificar);
        cout << COLOR_VERDE << "Se modificaron los materiales necesarios satisfactoriamente" << COLOR_POR_DEFECTO << endl;
    }
}

void Andypolis::comenzar_partida() {
    Jugador* jugador = nullptr;
    string nombre_jugador_1;
    string nombre_jugador_2;
    string convencion_jugador;
    int* coordenadas = 0;
    bool jugador_1_ubicado = false;
    bool jugador_2_ubicado = false;
    funciones_auxiliares.seleccionar_jugador(nombre_jugador_1, nombre_jugador_2);
    while (!jugador_1_ubicado || !jugador_2_ubicado) {
        convencion_jugador = nombre_jugador_1 == NUMERO_JUGADOR_1 ? JUGADOR_1 : JUGADOR_2;
        coordenadas = funciones_auxiliares.pedir_coordenadas(this -> mapa);
        int fila = coordenadas[INDICE_FILA];
        int columna = coordenadas[INDICE_COLUMNA];
        if (!jugador_1_ubicado) {
            jugador = jugador_1;
            jugador -> establecer_nombre(nombre_jugador_1);
            jugador_1_ubicado = true;
        }
        else if(!jugador_2_ubicado) {
            convencion_jugador = convencion_jugador == JUGADOR_1 ? JUGADOR_2 : JUGADOR_1;
            jugador = jugador_2;
            jugador -> establecer_nombre(nombre_jugador_2);
            jugador_2_ubicado = true;
        }
        jugador -> establecer_coordenadas(fila, columna);
        jugador -> establecer_codigo_emoji(convencion_jugador);
        jugador_1_ubicado = this -> mapa -> se_ubico_jugador(jugador, fila, columna);
        if(jugador_1_ubicado)
            cout << "Siguiente jugador" << endl;
        delete [] coordenadas;
    }
}

void Andypolis::mostrar_mapa() {
    this -> mapa -> mostrar_mapa();
}

void Andypolis::construir_edificio() {
    if (funciones_auxiliares.hay_energia_suficiente(ENERGIA_CONSTRUIR_EDIFICIO, this -> jugador_actual -> obtener_energia_actual())) {
        string edificio_a_construir = funciones_auxiliares.pedir_nombre_edificio();
        funciones_auxiliares.construir_edificio_auxiliar(this -> edificios_disponibles, this -> mapa, this -> jugador_actual, edificio_a_construir);
    }
}

void Andypolis::listar_mis_edificios() {
    this -> jugador_actual -> listar_construidos();
}

void Andypolis::comprar_bombas() {
    if (funciones_auxiliares.hay_energia_suficiente(ENERGIA_COMPRAR_BOMBA, this -> jugador_actual -> obtener_energia_actual())) {
        int bombas_a_comprar;
        cout << "Ingrese la cantidad de bombas que quiere comprar: " << endl;
        cin >> bombas_a_comprar;

        Inventario* inventario = this -> jugador_actual -> obtener_inventario();
        Material* andycoins = inventario -> obtener_material(ANDYCOINS);
        if (funciones_auxiliares.es_posible_comprar_bombas(bombas_a_comprar, andycoins -> obtener_cantidad()) && bombas_a_comprar > 0) {
            
            inventario -> modificar_cantidad_material(ANDYCOINS, - COSTO_ANDYCOINS_BOMBA);
            inventario -> modificar_cantidad_material(BOMBA, bombas_a_comprar);
            this -> jugador_actual -> modificar_energia(-ENERGIA_COMPRAR_BOMBA);
            cout << "Compro " << bombas_a_comprar << " bomba(s) y le quedan " << andycoins -> obtener_cantidad() << " Andyconis" << endl;
        }
    }
}
 
void Andypolis::consultar_coordenada() {
    int* coordenadas = funciones_auxiliares.pedir_coordenadas(this -> mapa);
    this -> mapa -> consultar_coordenada(coordenadas[INDICE_FILA], coordenadas[INDICE_COLUMNA]);
    delete [] coordenadas;
    coordenadas = nullptr;
}

void Andypolis::mostrar_inventario() {
    this -> jugador_actual -> obtener_inventario() -> mostrar_inventario();
}

void Andypolis::finalizar_turno() {
    funciones_auxiliares.lluvia_materiales(this -> mapa);
    funciones_auxiliares.aumentar_materiales_producidos(this -> jugador_actual);
    this -> jugador_actual -> modificar_energia(ENERGIA_FINALIZAR_TURNO);
    this -> jugador_actual = funciones_auxiliares.cambiar_turno(this -> jugador_actual, this -> jugador_1, this -> jugador_2);
}

Jugador* Andypolis::obtener_jugador(string numero_jugador) {
    return numero_jugador == NUMERO_JUGADOR_1 ? this -> jugador_1 : this -> jugador_2;
}

void Andypolis::demoler_edificio() {
    if (funciones_auxiliares.hay_energia_suficiente(ENERGIA_DEMOLER_EDIFICIO_COORDENADA, this -> jugador_actual -> obtener_energia_actual())) {
        int* coordenadas = funciones_auxiliares.pedir_coordenadas(this -> mapa);
        funciones_auxiliares.demoler_edificio_auxiliar(this -> edificios_disponibles, this -> mapa, this -> jugador_actual, coordenadas[INDICE_FILA], coordenadas[INDICE_COLUMNA]);
        delete [] coordenadas;
        coordenadas = nullptr;
    }
}

void Andypolis::recolectar_recursos() {
    if (funciones_auxiliares.hay_energia_suficiente(ENERGIA_RECOLECTAR_RECURSOS, this -> jugador_actual -> obtener_energia_actual())) {
        funciones_auxiliares.recolectar_recursos_auxiliares(this -> jugador_actual);
    }
}

void Andypolis::mostrar_objetivos() {
    Objetivo** objetivos = this -> jugador_actual -> obtener_nombre() == JUGADOR_1 ? objetivos_1 : objetivos_2;
    cout << "OBJETIVOS" << endl;
    cout << COLOR_DORADO << LINEA_DIVISORIA_DISENIO << COLOR_POR_DEFECTO;
    for (int i = 0; i < CANTIDAD_OBJETIVOS_POR_JUGADOR; i++)
        objetivos[i] -> mostrar_progreso();   
    cout << COLOR_DORADO << LINEA_DIVISORIA_DISENIO << COLOR_POR_DEFECTO;
}

void Andypolis::atacar_edificio() {
    if (funciones_auxiliares.hay_energia_suficiente(ENERGIA_ATACAR_EDIFICIO_COORDENADA, this -> jugador_actual -> obtener_energia_actual())) {
        int* coordenadas = funciones_auxiliares.pedir_coordenadas(this -> mapa);
        funciones_auxiliares.atacar_edificio_auxiliar(this -> mapa, this -> jugador_actual, this -> jugador_1, this -> jugador_2, coordenadas[INDICE_FILA], coordenadas[INDICE_COLUMNA]);
        delete [] coordenadas;
        coordenadas = nullptr;
    }
}

void Andypolis::reparar_edificio() {
    if (funciones_auxiliares.hay_energia_suficiente(ENERGIA_REPARAR_EDIFICIO, this -> jugador_actual -> obtener_energia_actual())) {
        int* coordenadas = funciones_auxiliares.pedir_coordenadas(this -> mapa);
        funciones_auxiliares.reparar_edificio_auxiliar(this -> edificios_disponibles, this -> mapa, this -> jugador_actual, coordenadas[INDICE_FILA], coordenadas[INDICE_COLUMNA]);
        delete [] coordenadas;
        coordenadas = nullptr;
    }
}

void Andypolis::moverse() {
    Grafo* grafo = new Grafo();
    this -> cargar_grafo(grafo);
    this -> funciones_auxiliares.cargar_caminos(grafo, this -> mapa, this -> jugador_actual);
    int* coordenadas = this -> funciones_auxiliares.pedir_coordenadas(this -> mapa);
    int* coordenadas_jugador = this -> jugador_actual -> obtener_coordenadas();
    string coordenadas_origen = to_string(coordenadas_jugador[INDICE_FILA]) + VACIO + to_string(coordenadas_jugador[INDICE_COLUMNA]);
    string coordenadas_destino = to_string(coordenadas[INDICE_FILA]) + VACIO + to_string(coordenadas[INDICE_COLUMNA]);
    //grafo -> usar_dijkstra();
    grafo -> usar_floyd();
    grafo -> camino_minimo(coordenadas_origen, coordenadas_destino);
    //this -> jugador_actual -> establecer_coordenadas(coordenadas[INDICE_FILA], coordenadas[INDICE_COLUMNA]);
    delete grafo;
    grafo = nullptr;
}

//PENDIENTES POR IMPLEMENTAR.

Andypolis::~Andypolis() {
    // delete this -> edificios_disponibles;
    // delete this -> mapa;
    // this -> edificios_disponibles = nullptr;
    // this -> mapa = nullptr;
    // this -> jugador_1 = nullptr;
    // this -> jugador_2 = nullptr;
    // this -> jugador_actual = nullptr;
}