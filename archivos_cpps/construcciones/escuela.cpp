#include "../../archivos_h/construcciones/escuela.h"

using namespace std;

Escuela::Escuela() : Edificio() {
    this -> inicializar_atributos();
}

Escuela::Escuela(int piedra_necesaria, int madera_necesaria, int metal_necesario, int permitidos) : Edificio(piedra_necesaria, madera_necesaria, metal_necesario, permitidos) {
    this -> inicializar_atributos();
}

Escuela::Escuela(int fila, int columna) : Edificio(fila, columna) {
    this -> inicializar_atributos();
}

void Escuela::inicializar_atributos() {
    this -> nombre_del_edificio = NOMBRE_ESCUELA;
    this -> nombre_material = ANDYCOINS;
    this -> cantidad_material_producido = BRINDAR_MATERIALES_ESCUELA;
    this -> codigo_emoji = EMOJI_ESCUELA;
}

void Escuela::aumentar_material_producido() {
    this -> cantidad_material_producido += BRINDAR_MATERIALES_ESCUELA;
}

void Escuela::mostrar_caracteristicas(int construidos) {
    string brinda_material = this -> nombre_del_edificio != NOMBRE_OBELISCO ? "SI" : "NO";
    cout << "--> " << COLOR_VERDE_AGUA << this -> nombre_del_edificio << COLOR_POR_DEFECTO << endl;
    cout << "Piedra requerida: " << this -> materiales_necesarios[POS_PIEDRA] << endl;
    cout << "Madera requerida: " << this -> materiales_necesarios[POS_MADERA] << endl;
    cout << "Metal requerido: " << this -> materiales_necesarios[POS_METAL] << endl;
    cout << "Construidos hasta el momento: " << construidos << endl;
    cout << "Puede construir " << this -> permitidos - construidos << " más" << endl;
    cout << "Brinda material: " << brinda_material << endl;
    cout << COLOR_MARRON << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
}

void Escuela::mostrar_saludo() {
    cout << COLOR_MARRON << "Soy una escuela y me encuentro en el casillero consultado" << COLOR_POR_DEFECTO << endl;
}