#include "../../archivos_h/casilleros/casillero_inaccesible.h"

using namespace std;

CasilleroInaccesible::CasilleroInaccesible() {
    this -> tipo_terreno = LAGO;
}

void CasilleroInaccesible::CasilleroInaccesible::mostrar() {
    cout << COLOR_DORADO << LINEA_DIVISORIA_DISENIO << COLOR_POR_DEFECTO;
    cout << COLOR_ROJO << "Soy un casillero inaccesible y no es posible construir aqui" << COLOR_POR_DEFECTO << endl;
    cout << COLOR_DORADO << LINEA_DIVISORIA_DISENIO << COLOR_POR_DEFECTO;
}