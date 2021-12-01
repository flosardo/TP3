#include "../../archivos_h/construcciones/fabrica.h"

using namespace std;

Fabrica::Fabrica() : Edificio() {}

Fabrica::Fabrica(unsigned int piedra_necesaria, unsigned int madera_necesaria, unsigned int metal_necesario, unsigned int permitidos) : Edificio(piedra_necesaria, madera_necesaria, metal_necesario, permitidos) {
    this -> nombre_material = METAL;
    this -> cantidad_material_producido = BRINDAR_MATERIALES_FABRICA;
    this -> nombre_del_edificio = NOMBRE_FABRICA;
    this -> codigo_emoji = EMOJI_FABRICA;
}

Fabrica::Fabrica(char jugador) {
    this -> jugador = jugador;
    this -> afectado = false;
    this -> codigo_emoji = EMOJI_FABRICA;
}

void Fabrica::mostrar_saludo() {
    cout << COLOR_MARRON << "Soy una fabrica y me encuentro en el casillero consultado" << COLOR_POR_DEFECTO << endl;
}

void Fabrica::mostrar_edificio(Mapa* mapa, Jugador* jugador) {
    int cantidad_construidos = jugador -> obtener_cantidad_construidos(this -> nombre_del_edificio, mapa);
    cout << "--> " << COLOR_VERDE_AGUA << this-> nombre_del_edificio << COLOR_POR_DEFECTO << endl;
    cout << endl;
    cout << "Piedra requerida: " << this -> materiales_necesarios[0] << endl;
    cout << "Madera requerida: " << this -> materiales_necesarios[1] << endl;
    cout << "Metal requerido: " << this -> materiales_necesarios[2] << endl;
    cout << "Construidos hasta el momento: " << cantidad_construidos << endl;
    cout << "Puede construir " << this -> permitidos - cantidad_construidos << " mas" << endl;
    cout << "Brinda material: SI" << endl;
    cout << COLOR_MARRON << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
}