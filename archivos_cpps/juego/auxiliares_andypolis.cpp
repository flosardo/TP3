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
    cin >> coordenadas[POSICION_FILA];
    cout << "Ingrese la columna: " << endl;
    cin >> coordenadas[POSICION_COLUMNA];
    return coordenadas;
}

void Auxiliares_andypolis::seleccionar_jugador(string& nombre1, string& nombre2) {
    cout << "¿Que jugador quiere ser? Ingrese 1 para ser el primer jugador, 2 para el segundo: " << endl;
    cin >> nombre1;
    if(nombre1 != NUMERO_JUGADOR_2)
        nombre2 = NUMERO_JUGADOR_2;
    else
        nombre2 = NUMERO_JUGADOR_1;
}

bool Auxiliares_andypolis::validar_coordenadas(int fila, int columna) {
    return this -> mapa -> coordenadas_fuera_de_rango(fila, columna);
}