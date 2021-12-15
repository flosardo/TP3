#include "../../archivos_h/objetivos/objetivo_piedra.h"

using namespace std;

Objetivo_piedra::Objetivo_piedra() {
    this -> nombre = NOMBRE_OBJETIVO_PIEDRA;
    this -> cantidad_piedras = 0;
}

bool Objetivo_piedra::se_cumplio_objetivo(Jugador* jugador) {
    if (!this -> se_cumplio) {
        this -> cantidad_piedras = jugador -> obtener_inventario() -> obtener_material(PIEDRA) -> obtener_cantidad();
        this -> se_cumplio = this -> cantidad_piedras >= OBJETIVO_PIEDRA;
    }
    return this -> se_cumplio;
}

void Objetivo_piedra::mostrar_progreso() {
    cout << this -> nombre;
    if (!this -> se_cumplio) {
        cout << endl;
        cout << COLOR_DORADO << setw(3) << "|-> " << COLOR_POR_DEFECTO << EMOJI_PIEDRA << VACIO <<
        OBJETIVO_PIEDRA - this -> cantidad_piedras << " Piedras faltantes por recolectar, para ser Pablo Marmol." << endl;
    }
    else
        cout << VACIO << EMOJI_CHECK << endl;
    cout << endl;
    
}