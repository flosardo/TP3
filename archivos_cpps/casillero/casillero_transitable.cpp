#include "../../archivos_h/casilleros/casillero_transitable.h"

using namespace std;

Casillero_transitable::Casillero_transitable() {
    this -> material = nullptr;
    this -> tipo_terreno = CAMINO;
}

Casillero_transitable::Casillero_transitable(Material* material) {
    this -> material = material;
}

void Casillero_transitable::mostrar() {
    if (!material) {
        cout << COLOR_DORADO << LINEA_DIVISORIA_DISENIO << COLOR_POR_DEFECTO;
        cout << COLOR_VERDE << "Soy un casillero transitable " << EMOJI_CAMINO << " y me encuentro vacío." << COLOR_POR_DEFECTO << endl;
        cout << COLOR_DORADO << LINEA_DIVISORIA_DISENIO << COLOR_POR_DEFECTO;
    }
    else {
        cout << COLOR_VERDE_AGUA << "Soy un casillero transitable y no me encuentro vacio" << COLOR_POR_DEFECTO << endl;
        cout << endl;
        this -> material -> saludar();
    }
}

Material* Casillero_transitable::obtener_material() {
    return this -> material;
}

void Casillero_transitable::agregar_material(Material* material_a_agregar) {
    this -> material = material_a_agregar;
}

bool Casillero_transitable::esta_ocupado() {
    return (bool) this -> material;
}

void Casillero_transitable::limpiar_casillero() {
    this -> material = nullptr;
}

char Casillero_transitable::nombre_casillero() {
    return this -> material -> obtener_nombre_material();
} // HAY QUE SACAR, si ya hay una que devuelve el puntero al material ¿para que queremos este? o
  // sino cambiar el nombre, no tiene sentido nombre_casillero porque devuelve el nombre del material

Casillero_transitable::~Casillero_transitable() {
    delete this -> material;
}