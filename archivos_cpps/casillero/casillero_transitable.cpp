#include "../../archivos_h/casilleros/casillero_transitable.h"

using namespace std;

Casillero_transitable::Casillero_transitable(string color) {
    this -> material = nullptr;
    this -> jugador = nullptr;
    this -> tipo_terreno = CAMINO;
    this -> codigo_color = color;
}

Jugador* Casillero_transitable::obtener_puntero_jugador() {
    return this -> jugador;
}

void Casillero_transitable::mostrar() {
    if (!this -> material && !this -> jugador) {
        cout << COLOR_DORADO << LINEA_DIVISORIA_DISENIO << COLOR_POR_DEFECTO;
        cout << COLOR_VERDE << "Soy un casillero transitable " << EMOJI_CAMINO << " y me encuentro vacío." << COLOR_POR_DEFECTO << endl;
        cout << COLOR_DORADO << LINEA_DIVISORIA_DISENIO << COLOR_POR_DEFECTO;
    } else if (this -> jugador) {
        cout << COLOR_VERDE_AGUA << "Soy un casillero transitable y no me encuentro vacio" << COLOR_POR_DEFECTO << endl << endl;
    } else {
        cout << COLOR_VERDE_AGUA << "Soy un casillero transitable y no me encuentro vacio" << COLOR_POR_DEFECTO << endl << endl;
        this -> material -> saludar();
    }
}

Material* Casillero_transitable::obtener_puntero_material() {
    return this -> material;
}

void Casillero_transitable::agregar_material(Material* material_a_agregar) {
    this -> material = material_a_agregar;
}

void Casillero_transitable::agregar_jugador(Jugador* jugador) {
    this -> jugador = jugador;
}

bool Casillero_transitable::esta_ocupado() {
    return (bool) this -> material || (bool) this -> jugador;
}

void Casillero_transitable::limpiar_casillero() {
    this -> material = nullptr;
}

Casillero_transitable::~Casillero_transitable() {
    if (this -> material)
        delete this -> material;
    else if (this -> jugador)
        delete this -> jugador;
    this -> material = nullptr;
    this -> jugador = nullptr;
}