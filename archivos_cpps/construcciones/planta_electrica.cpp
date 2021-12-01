#include "../../archivos_h/construcciones/planta_electrica.h"

using namespace std;

Planta_electrica::Planta_electrica() : Edificio() {}

Planta_electrica::Planta_electrica(unsigned int piedra_necesaria, unsigned int madera_necesaria, unsigned int metal_necesario, unsigned int permitidos) : Edificio(piedra_necesaria, madera_necesaria, metal_necesario, permitidos) {
    this -> nombre_material = VACIO;
    this -> cantidad_material_producido = BRINDAR_MATERIALES_PLANTA_ELECTRICA;
    this -> nombre_del_edificio = NOMBRE_PLANTA_ELECTRICA;
    this -> codigo_emoji = EMOJI_PLANTA_ELECTRICA;
}

Planta_electrica::Planta_electrica(char jugador) {
    this -> jugador = jugador;
    this -> afectado = false;
    this -> codigo_emoji = EMOJI_PLANTA_ELECTRICA;
}

void Planta_electrica::mostrar_saludo() {
    cout << COLOR_MARRON << "Soy una planta electrica y me encuentro en el casillero consultado" << COLOR_POR_DEFECTO << endl;
}

void Planta_electrica::mostrar_edificio(Mapa* mapa, Jugador* jugador) {
    int cantidad_construidos = jugador -> obtener_cantidad_construidos(this -> nombre_del_edificio, mapa);
    cout << "--> " << COLOR_VERDE_AGUA << this -> nombre_del_edificio << COLOR_POR_DEFECTO << endl;
    cout << endl;
    cout << "Piedra requerida: " << this -> materiales_necesarios[0] << endl;
    cout << "Madera requerida: " << this -> materiales_necesarios[1] << endl;
    cout << "Metal requerido: " << this -> materiales_necesarios[2] << endl;
    cout << "Construidos hasta el momento: " << cantidad_construidos << endl;
    cout << "Puede construir " << this -> permitidos - cantidad_construidos << " mas" << endl;
    cout << "Brinda material: SI" << endl;
    cout << COLOR_MARRON << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
}