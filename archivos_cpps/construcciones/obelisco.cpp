#include "../../archivos_h/construcciones/obelisco.h"

using namespace std;

Obelisco::Obelisco() : Edificio(){}

Obelisco::Obelisco(unsigned int piedra_necesaria, unsigned int madera_necesaria, unsigned int metal_necesario, unsigned int permitidos) : Edificio(piedra_necesaria, madera_necesaria, metal_necesario, permitidos) {
    this -> nombre_material = VACIO;
    this -> cantidad_material_producido = 0;
    this -> nombre_del_edificio = NOMBRE_OBELISCO;
    this -> codigo_emoji = EMOJI_OBELISCO;
}

Obelisco::Obelisco(char jugador){

    this -> jugador = jugador;
    this -> afectado = false;
    this -> codigo_emoji = EMOJI_OBELISCO;
}

void Obelisco::mostrar_saludo() {
    cout << COLOR_MARRON << "Soy un obelisco y me encuentro en el casillero consultado" << COLOR_POR_DEFECTO << endl;
}

void Obelisco::mostrar_edificio(Mapa* mapa) {
    int cantidad_construidos = this -> jugador -> obtener_cantidad_construidos(this -> nombre_del_edificio, mapa);
    cout << "--> " << COLOR_VERDE_AGUA << this -> nombre_del_edificio << COLOR_POR_DEFECTO << endl;
    cout << endl;
    cout << "Piedra requerida: " << this -> materiales_necesarios[0] << endl;
    cout << "Madera requerida: " << this -> materiales_necesarios[1] << endl;
    cout << "Metal requerido: " << this -> materiales_necesarios[2] << endl;
    cout << "Construidos hasta el momento: " << cantidad_construidos << endl;
    cout << "Puede construir " << this -> permitidos - cantidad_construidos << " mas" << endl;
    cout << "Brinda material: NO" << endl;
    cout << COLOR_MARRON << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
}