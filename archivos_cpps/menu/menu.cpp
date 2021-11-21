#include "../../archivos_h/menu/menu.h"

using namespace std;

int Menu::pedir_opcion() {
    cout << "Ingrese la opcion deseada: ";
    cin >> this -> opcion_ingresada;
    return this -> opcion_ingresada;
}