#include "../../archivos_h/construcciones/obelisco.h"

using namespace std;

Obelisco::Obelisco() : Edificio() {
    this -> inicializar_atributos();
}

Obelisco::Obelisco(int piedra_necesaria, int madera_necesaria, int metal_necesario, int permitidos) : Edificio(piedra_necesaria, madera_necesaria, metal_necesario, permitidos) {
    this -> inicializar_atributos();
}

Obelisco::Obelisco(int fila, int columna) : Edificio(fila, columna) {
    this -> inicializar_atributos();
}

void Obelisco::inicializar_atributos() {
    this -> nombre_del_edificio = NOMBRE_OBELISCO;
    this -> nombre_material = VACIO;
    this -> cantidad_material_producido = 0;
    this -> codigo_emoji = EMOJI_OBELISCO;
}

void Obelisco::mostrar_caracteristicas(int construidos) {
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

void Obelisco::mostrar_saludo() {
    cout << COLOR_MARRON << "Soy un obelisco y me encuentro en el casillero consultado " << COLOR_POR_DEFECTO << endl;
}
