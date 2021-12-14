#include "../../archivos_h/menu/menu.h"

using namespace std;

int Menu::pedir_opcion() {
    cout << "Ingrese la opcion deseada: ";
    cin >> this -> opcion_ingresada;
    system(CLR_SCREEN);
    return this -> opcion_ingresada;
}

void Menu::mostrar_mensaje(string mensaje) {
    cout << COLOR_DORADO;
    cout << "───────────────────────────────────────────" << endl;
    cout <<  COLOR_POR_DEFECTO << mensaje << COLOR_DORADO << endl;
    cout << "───────────────────────────────────────────" << COLOR_POR_DEFECTO;
    cout << endl << endl;
}

void Menu::mostrar_mensaje_volver_menu(int segundos) {
    cout << endl;
    cout << COLOR_VERDE << "Dentro de " << segundos << " segundos " << EMOJI_CRONOMETRO << "  se volvera al menú (:"
    << COLOR_POR_DEFECTO << endl;
    sleep((unsigned int)segundos);
}

Menu::~Menu() {}