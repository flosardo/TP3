#include "../../archivos_h/menu/menu.h"

using namespace std;

int Menu::pedir_opcion() {
    cout << "Ingrese la opcion deseada: ";
    cin >> this -> opcion_ingresada;
    system(CLR_SCREEN);
    return this -> opcion_ingresada;
}

Menu::~Menu() {}