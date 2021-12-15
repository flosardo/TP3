#include "../../archivos_h/casilleros/casillero_transitable.h"

using namespace std;

Casillero_transitable::Casillero_transitable(string color, char tipo) {
    this -> tipo_terreno = tipo;
    this -> material = nullptr;
    this -> jugador = nullptr;
    this -> codigo_color = color;
}

Jugador* Casillero_transitable::obtener_puntero_jugador() {
    return this -> jugador;
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
    this -> jugador = nullptr;
    this -> material = nullptr;
}

void Casillero_transitable::mostrar() {
    cout << COLOR_DORADO << LINEA_DIVISORIA_DISENIO << COLOR_POR_DEFECTO;
    if (!this -> esta_ocupado())
        cout << COLOR_VERDE << "Soy un casillero transitable " << EMOJI_CAMINO << " y me encuentro vacío." << COLOR_POR_DEFECTO << endl;
    else {
        cout << COLOR_VERDE_AGUA << "Soy un casillero transitable y no me encuentro vacio" << COLOR_POR_DEFECTO << endl << endl;
        if (this -> material)
            this -> material -> saludar();
    }
    cout << COLOR_DORADO << LINEA_DIVISORIA_DISENIO << COLOR_POR_DEFECTO;
}

Casillero_transitable::~Casillero_transitable() {
    if (this -> material)
        delete this -> material;

    this -> limpiar_casillero();
}