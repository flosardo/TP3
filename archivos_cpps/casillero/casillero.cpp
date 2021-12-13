#include "../../archivos_h/casilleros/casillero.h"

using namespace std;

Casillero::Casillero() {
    this -> tipo_terreno = VACIO;
    this -> codigo_color = VACIO;
}

char Casillero::obtener_tipo_de_terreno() {
    return this -> tipo_terreno;
}

string Casillero::obtener_color() {
    return this -> codigo_color;
}

Jugador* Casillero::obtener_puntero_jugador() {
    return nullptr;
}

Material* Casillero::obtener_puntero_material() {
    return nullptr;
}

Edificio* Casillero::obtener_puntero_edificio() {
    return nullptr;
}

void Casillero::agregar_jugador(Jugador* jugador) {}

void Casillero::agregar_material(Material* material_a_agregar) {}

void Casillero::agregar_edificio(Edificio* edificio_a_agregar) {}

bool Casillero::esta_ocupado() {
    return false;
}

void Casillero::limpiar_casillero() {}

Casillero::~Casillero() {}