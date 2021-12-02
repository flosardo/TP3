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
    cout << "Ingrese la fila: " << endl;
    cout << ">> " << COLOR_DORADO << COLOR_POR_DEFECTO;
    cin >> coordenadas[POSICION_FILA];
    cout << "Ingrese la columna: " << endl;
    cout << ">> " << COLOR_DORADO << COLOR_POR_DEFECTO;
    cin >> coordenadas[POSICION_COLUMNA];
    return coordenadas;
}

void Auxiliares_andypolis::seleccionar_jugador(string & nombre_jugador_1, string & nombre_jugador_2) {
    cout << "¿Que jugador quiere ser? Ingrese 1 para ser el primer jugador, 2 para el segundo: " << endl;
    cout << ">> " << COLOR_DORADO << COLOR_POR_DEFECTO;
    cin >> nombre_jugador_1;
    if (nombre_jugador_1 != NUMERO_JUGADOR_2)
        nombre_jugador_2 = NUMERO_JUGADOR_2;
    else
        nombre_jugador_2 = NUMERO_JUGADOR_1;
}

bool Auxiliares_andypolis::validar_coordenadas(int fila, int columna) {
    return this -> mapa -> coordenadas_fuera_de_rango(fila, columna);
}

bool Auxiliares_andypolis::hay_energia_suficiente(int energia_necesaria, int energia_del_jugador) {
    return energia_del_jugador >= energia_necesaria;
}

int Auxiliares_andypolis::pedir_nueva_cantidad_material(string material){
    int cantidad = 0;
    cout << "Ingrese la nueva cantidad de " << material << " >> " << COLOR_DORADO << COLOR_POR_DEFECTO;
    cin >> cantidad;
    return cantidad;
}

void Auxiliares_andypolis::modificar_materiales_necesarios(Edificio* edificio){
    unsigned int nueva_cantidad_piedra = this -> pedir_nueva_cantidad_material(PIEDRA);
    unsigned int nueva_cantidad_madera = this -> pedir_nueva_cantidad_material(MADERA);
    unsigned int nueva_cantidad_metal = this -> pedir_nueva_cantidad_material(METAL);
    edificio -> establecer_nuevos_materiales(nueva_cantidad_piedra, nueva_cantidad_madera, nueva_cantidad_metal);
}

string Auxiliares_andypolis::pedir_nombre_edificio(){
    string nombre_edificio;
    cout << "Ingrese el nombre del edificio" << COLOR_DORADO << " >> " << COLOR_POR_DEFECTO;
    getline(cin, nombre_edificio, '\n');
    cout << nombre_edificio << endl;
    return nombre_edificio;
}