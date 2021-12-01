#include "../../archivos_h/construcciones/escuela.h"

using namespace std;

Escuela::Escuela() : Edificio() {}

Escuela::Escuela(unsigned int piedra_necesaria, unsigned int madera_necesaria, unsigned int metal_necesario, unsigned int permitidos) : Edificio(piedra_necesaria, madera_necesaria, metal_necesario, permitidos) {
    this -> nombre_material = VACIO;
    this -> cantidad_material_producido = BRINDAR_MATERIALES_ESCUELA;
    this -> nombre_del_edificio = NOMBRE_ESCUELA;
    this -> codigo_emoji = EMOJI_ESCUELA;
}

Escuela::Escuela(char jugador) {
    this -> jugador = jugador;
    this -> afectado = false;
    this -> codigo_emoji = EMOJI_ESCUELA;
}

void Escuela::mostrar_saludo() {
    cout << COLOR_MARRON << "Soy una escuela y me encuentro en el casillero consultado" << COLOR_POR_DEFECTO << endl;
}

void Escuela::mostrar_edificio(Mapa* mapa) {
    int cantidad_construidos = this -> jugador -> obtener_cantidad_construidos(this -> nombre_del_edificio, mapa);
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