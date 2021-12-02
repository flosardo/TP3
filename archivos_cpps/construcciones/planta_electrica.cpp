#include "../../archivos_h/construcciones/planta_electrica.h"

using namespace std;

Planta_electrica::Planta_electrica() : Edificio() {
    this -> inicializar_atributos();
}

Planta_electrica::Planta_electrica(unsigned int piedra_necesaria, unsigned int madera_necesaria, unsigned int metal_necesario, unsigned int permitidos) : Edificio(piedra_necesaria, madera_necesaria, metal_necesario, permitidos) {
    this -> inicializar_atributos();
}

Planta_electrica::Planta_electrica(unsigned int fila, unsigned int columna) : Edificio(fila, columna) {
    this -> inicializar_atributos();
}

void Planta_electrica::inicializar_atributos(){
    this -> nombre_material = VACIO;
    this -> cantidad_material_producido = BRINDAR_MATERIALES_PLANTA_ELECTRICA;
    this -> nombre_del_edificio = NOMBRE_PLANTA_ELECTRICA;
    this -> codigo_emoji = EMOJI_PLANTA_ELECTRICA;
}

void Planta_electrica::mostrar_caracteristicas(int construidos) {
    cout << "--> " << COLOR_VERDE_AGUA << this -> nombre_del_edificio << COLOR_POR_DEFECTO << endl;
    cout << "Piedra requerida: " << this -> materiales_necesarios[POS_PIEDRA] << endl;
    cout << "Madera requerida: " << this -> materiales_necesarios[POS_MADERA] << endl;
    cout << "Metal requerido: " << this -> materiales_necesarios[POS_METAL] << endl;
    cout << "Construidos hasta el momento: " << construidos << endl;
    cout << "Puede construir " << this -> permitidos - construidos << " más" << endl;
    cout << "Brinda material: SI" << endl;
    cout << COLOR_MARRON << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
}

void Planta_electrica::mostrar_saludo() {
    cout << COLOR_MARRON << "Soy una planta electrica y me encuentro en el casillero consultado" << COLOR_POR_DEFECTO << endl;
}