#include "../../archivos_h/objetivos/objetivo_armado.h"

using namespace std;

Objetivo_armado::Objetivo_armado() {
    this -> nombre = NOMBRE_OBJETIVO_ARMADO;
    this -> cantidad_bombas = 0;
    this -> se_cumplio = false;
}

bool Objetivo_armado::se_cumplio_objetivo(Jugador* jugador) {
    if (!this -> se_cumplio) {
        this -> cantidad_bombas = jugador -> obtener_inventario() -> obtener_material(BOMBA) -> obtener_cantidad();
        this -> se_cumplio = this -> cantidad_bombas >= OBJETIVO_ARMADO;
    }
    return this -> se_cumplio;
}

void Objetivo_armado::mostrar_progreso() {
    cout << this -> nombre;
    if (!this -> se_cumplio) {
        cout << endl;
        cout << COLOR_DORADO << setw(3) << "|-> " << COLOR_POR_DEFECTO << EMOJI_BOMBA << VACIO
        << OBJETIVO_ARMADO - this -> cantidad_bombas << VACIO << "Bombas faltantes por comprar, para ser un verdadero TALIBAN." << endl;
    }
    else
        cout << VACIO << EMOJI_CHECK << endl;
    cout << endl;
}
