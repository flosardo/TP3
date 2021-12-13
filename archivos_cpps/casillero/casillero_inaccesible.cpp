#include "../../archivos_h/casilleros/casillero_inaccesible.h"

using namespace std;

Casillero_inaccesible::Casillero_inaccesible() {
    this -> tipo_terreno = LAGO;
    this -> codigo_color = FONDO_AZUL;
}

void Casillero_inaccesible::Casillero_inaccesible::mostrar() {
    cout << COLOR_DORADO << LINEA_DIVISORIA_DISENIO << COLOR_POR_DEFECTO;
    cout << COLOR_ROJO << "Soy un casillero inaccesible y no es posible construir aqui." << COLOR_POR_DEFECTO << endl;
    cout << COLOR_DORADO << LINEA_DIVISORIA_DISENIO << COLOR_POR_DEFECTO;
}