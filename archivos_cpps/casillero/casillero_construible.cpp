#include "../../archivos_h/casilleros/casillero_construible.h"

using namespace std;

Casillero_construible::Casillero_construible() {
    edificio = nullptr;
    tipo_terreno = TERRENO;
}

Casillero_construible::Casillero_construible(Edificio* edificio) {
    this -> edificio = edificio;
}

void Casillero_construible::mostrar() {
    if(edificio == nullptr) {
        cout << COLOR_DORADO << LINEA_DIVISORIA_DISENIO << COLOR_POR_DEFECTO << endl;
        cout << "Soy un terreno " << EMOJI_TERRENO << ",  un casillero construible y me encuentro vacío." << endl;
        cout << COLOR_DORADO << LINEA_DIVISORIA_DISENIO << COLOR_POR_DEFECTO;

    }
    else{
        cout << COLOR_DORADO << LINEA_DIVISORIA_DISENIO << COLOR_POR_DEFECTO << endl;
        cout << "Soy un terreno " << EMOJI_TERRENO << ", un casillero construible y no me encuentro vacío." << endl;
        this -> edificio -> mostrar_saludo();
        cout << COLOR_DORADO << LINEA_DIVISORIA_DISENIO << COLOR_POR_DEFECTO << endl;
    }
}

void Casillero_construible::agregar_edificio(Edificio* edificio_a_construir) {
    edificio = edificio_a_construir;
}

Edificio* Casillero_construible::obtener_edificio() {
    return edificio;
}

void Casillero_construible::limpiar_casillero() {
    edificio = nullptr;
}

bool Casillero_construible::esta_ocupado() {
    return (bool) this -> edificio;
}

Casillero_construible::~Casillero_construible() {
    delete this -> edificio;
}