#include "../../archivos_h/construcciones/mina_oro.h"

using namespace std;

Mina_oro::Mina_oro() : Edificio() {
    this -> inicializar_atributos();
}

Mina_oro::Mina_oro(int piedra_necesaria, int madera_necesaria, int metal_necesario, int permitidos) : Edificio(piedra_necesaria, madera_necesaria, metal_necesario, permitidos) {
    this -> inicializar_atributos();
}

Mina_oro::Mina_oro(int fila, int columna) : Edificio(fila, columna) {
    this -> inicializar_atributos();
}

void Mina_oro::inicializar_atributos() {
    this -> nombre_del_edificio = NOMBRE_MINA_ORO;
    this -> nombre_material = ANDYCOINS;
    this -> cantidad_material_producido = BRINDAR_MATERIALES_MINA_ORO;
    this -> codigo_emoji = EMOJI_MINA_ORO;
}

void Mina_oro::aumentar_material_producido() {
    this -> cantidad_material_producido += BRINDAR_MATERIALES_MINA_ORO;
}

void Mina_oro::mostrar_caracteristicas(int construidos) {
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

void Mina_oro::mostrar_saludo() {
    cout << COLOR_MARRON << "Soy una mina de oro y me encuentro en el casillero consultado" << COLOR_POR_DEFECTO << endl;
}