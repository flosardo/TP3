#include "../../archivos_h/objetivos/objetivo_andycoins.h"

using namespace std;

Objetivo_andycoins::Objetivo_andycoins() {
    this -> nombre = NOMBRE_OBJETIVO_ANDYCOINS;
    this -> cantidad_andycoins = 0;
}

bool Objetivo_andycoins::se_cumplio_el_objetivo(Jugador* jugador) {
    this -> cantidad_andycoins += jugador -> obtener_inventario() -> obtener_material(ANDYCOINS) -> obtener_cantidad();
    return (this -> cantidad_andycoins >= OBJETIVO_ANDYCOINS);
}

void Objetivo_andycoins::mostrar_progreso() {
    cout << "Faltan: " << OBJETIVO_ANDYCOINS - this -> cantidad_andycoins << " andycoins para lograr el objetivo" << endl;
}
