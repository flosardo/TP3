#include "../../archivos_h/construcciones/mina_oro.h"

using namespace std;

Mina_oro::Mina_oro() : Edificio() {}

Mina_oro::Mina_oro(unsigned int piedra_necesaria, unsigned int madera_necesaria, unsigned int metal_necesario, unsigned int permitidos) : Edificio(piedra_necesaria, madera_necesaria, metal_necesario, permitidos) {
    this -> nombre_material = PIEDRA;
    this -> cantidad_material_producido = BRINDAR_MATERIALES_MINA_ORO;
    this -> nombre_del_edificio = NOMBRE_MINA_ORO;
    this -> codigo_emoji = EMOJI_MINA_ORO;
}

Mina_oro::Mina_oro(char jugador) {
    this -> jugador = jugador;
    this -> afectado = false;
    this -> codigo_emoji = EMOJI_MINA_ORO;
}

void Mina_oro::mostrar_saludo() {
    cout << COLOR_MARRON << "Soy una mina de oro y me encuentro en el casillero consultado" << COLOR_POR_DEFECTO << endl;
}

void Mina_oro::mostrar_edificio(Mapa* mapa) {
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