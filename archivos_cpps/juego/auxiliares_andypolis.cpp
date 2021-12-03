#include "../../archivos_h/juego/auxiliares_andypolis.h"

using namespace std;

Auxiliares_andypolis::Auxiliares_andypolis() {
    this -> edificios_disponibles = nullptr;
    this -> mapa = nullptr;
}

Auxiliares_andypolis::Auxiliares_andypolis(Abb* edificios_disponibles, Mapa* mapa) {
    this -> edificios_disponibles = edificios_disponibles;
    this -> mapa = mapa;
}

bool Auxiliares_andypolis::es_edificio_valido(string nombre) {
    return (bool) this -> edificios_disponibles -> buscar_edificio(nombre);
}

bool Auxiliares_andypolis::es_posible_comprar_bombas(int & cantidad_de_bombas, int cantidad_andycoins) {
    return cantidad_andycoins >= (cantidad_de_bombas * COSTO_ANDYCOINS_BOMBA);
}

int* Auxiliares_andypolis::pedir_coordenadas() {
    int* coordenadas = new int[MAX_COORDENADAS];
    bool ubicado = false;
    while (!ubicado) {
        cout << "Ingrese la fila" << endl;
        cout << COLOR_DORADO << ">> " << COLOR_POR_DEFECTO;
        cin >> coordenadas[POSICION_FILA];
        cout << "Ingrese la columna" << endl;
        cout << COLOR_DORADO << ">> " << COLOR_POR_DEFECTO;
        cin >> coordenadas[POSICION_COLUMNA];
        ubicado = this -> validar_coordenadas(coordenadas[POSICION_FILA], coordenadas[POSICION_COLUMNA]);
    }
    return coordenadas;
}

bool Auxiliares_andypolis::validar_coordenadas(int fila, int columna) {
    return !this -> mapa -> coordenadas_fuera_de_rango(fila, columna) && this -> es_casillero_valido(fila, columna);
}

bool Auxiliares_andypolis::es_casillero_valido(int fila, int columna) {
    bool es_valido = !this -> mapa -> esta_ocupado(fila, columna) && this -> mapa -> obtener_tipo_casillero(fila, columna) != LAGO;
    if (!es_valido)
        cout << COLOR_ROJO << "Las coordenadas que ingresaste no pertenecen a un casillero válido" << COLOR_POR_DEFECTO << endl;
    return es_valido;
}

void Auxiliares_andypolis::seleccionar_jugador(string & nombre_jugador_1, string & nombre_jugador_2) {
    cout << "¿Que jugador quiere ser? Ingrese 1 para ser el primer jugador, 2 para el segundo" << endl;
    cout << COLOR_DORADO << ">> " << COLOR_POR_DEFECTO;
    cin >> nombre_jugador_1;
    if (nombre_jugador_1 != NUMERO_JUGADOR_2)
        nombre_jugador_2 = NUMERO_JUGADOR_2;
    else
        nombre_jugador_2 = NUMERO_JUGADOR_1;
}

bool Auxiliares_andypolis::hay_energia_suficiente(int energia_necesaria, int energia_del_jugador) {
    return energia_del_jugador >= energia_necesaria;
}

int Auxiliares_andypolis::pedir_nueva_cantidad_material(string material) {
    int cantidad = -1;
    while (cantidad < MIN_VALOR_MATERIAL || cantidad > MAX_VALOR_MATERIALES) {
        cout << "Ingrese la nueva cantidad de " << material << " >> " << COLOR_DORADO << COLOR_POR_DEFECTO;
        cin >> cantidad;
    }
    return cantidad;
}

void Auxiliares_andypolis::modificar_materiales_necesarios(Edificio* edificio) {
    int nueva_cantidad_piedra = this -> pedir_nueva_cantidad_material(PIEDRA);
    int nueva_cantidad_madera = this -> pedir_nueva_cantidad_material(MADERA);
    int nueva_cantidad_metal = this -> pedir_nueva_cantidad_material(METAL);
    edificio -> establecer_nuevos_materiales(nueva_cantidad_piedra, nueva_cantidad_madera, nueva_cantidad_metal);
}

string Auxiliares_andypolis::pedir_nombre_edificio() {
    string nombre_edificio;
    cout << "Ingrese el nombre del edificio" << COLOR_DORADO << " >> " << COLOR_POR_DEFECTO;
    getline(cin.ignore(), nombre_edificio);
    return nombre_edificio;
}

void Auxiliares_andypolis::asignar_turno(Jugador* jugador_actual, Jugador* jugador_1, Jugador* jugador_2) {
    int turno = rand() % 2 + 1;
    jugador_actual = turno == 1 ? jugador_1 : jugador_2;
}

void Auxiliares_andypolis::modificar_energia(Jugador* jugador_actual, int cantidad_a_modificar) {
    jugador_actual -> modificar_energia(cantidad_a_modificar);
}

bool Auxiliares_andypolis::hay_materiales_suficientes(Jugador* jugador_actual, string edificio_a_construir) {
    Edificio* edificio = this -> edificios_disponibles -> buscar_edificio(edificio_a_construir);
    int* materiales_necesarios = edificio -> obtener_materiales_necesarios();
    Inventario* inventario = jugador_actual -> obtener_inventario();
    bool hay_piedra_suficiente = materiales_necesarios[POS_PIEDRA] >= inventario[POS_PIEDRA].obtener_cantidad_materiales();
    bool hay_madera_suficiente = materiales_necesarios[POS_MADERA] >= inventario[POS_MADERA].obtener_cantidad_materiales();
    bool hay_metal_suficiente = materiales_necesarios[POS_METAL] >= inventario[POS_METAL].obtener_cantidad_materiales();
    return hay_piedra_suficiente && hay_madera_suficiente && hay_metal_suficiente;
}

bool Auxiliares_andypolis::se_alcanzo_maximo_permitido(Abb* arbol, Jugador* jugador_actual, string edificio_a_construir) {
    return arbol -> contar_construidos(jugador_actual, edificio_a_construir) == arbol -> buscar_edificio(edificio_a_construir) -> obtener_permitidos();
}


bool Auxiliares_andypolis::confirmar_construccion(string edificio_a_construir) {
    string decision;
    cout << "Está seguro que quiere construir un/a " << edificio_a_construir << " ?(s/n): ";
    cin >> decision;
    transform(decision.begin(), decision.end(), decision.begin(), ::tolower);
    return (decision == "s");
}

void Auxiliares_andypolis::validar_construccion(Jugador* jugador_actual, string edificio_a_construir) {
    if (!this -> energia_suficiente(ENERGIA_CONSTRUIR_EDIFICIO, jugador_actual -> devolver_energia_actual()))
        cout << COLOR_ROJO << "No hay energia suficiente para construir " << edificio_a_construir << COLOR_POR_DEFECTO << endl;
    else if (!this -> edificios_disponibles -> buscar_edificio(edificio_a_construir)) 
        cout << COLOR_ROJO << "El edificio ingresado no existe, intente nuevamente" << COLOR_POR_DEFECTO << endl;
    else if (this -> se_alcanzo_maximo_permitido(edificio_a_construir)) 
        cout << COLOR_ROJO << "Ya estan construidos la cantidad maxima de " << edificio_a_construir << " posibles" << COLOR_POR_DEFECTO << endl;
    else if (!this -> hay_materiales_suficientes(Jugador* jugador_actual, edificio_a_construir))
        cout << COLOR_ROJO << "No hay materiales suficientes para construir " << edificio_a_construir << COLOR_POR_DEFECTO << endl;
    else {
        if (!this -> confirmar_construccion(edificio_a_construir)) 
            cout << COLOR_VERDE << "Operacion cancelada" << COLOR_POR_DEFECTO << endl;
        int* coordenadas = pedir_coordenadas();



    }
}