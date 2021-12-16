#include "../../archivos_h/menu/menu.h"

using namespace std;

int Menu::pedir_opcion() {
    cout << "Ingrese la opcion deseada: ";
    cin >> this -> opcion_ingresada;
    system(CLR_SCREEN);
    return this -> opcion_ingresada;
}

void Menu::mostrar_mensaje(string mensaje, int espacios) {
    cout << COLOR_DORADO << LINEA_DIVISORIA_MENSAJE_MENU << COLOR_POR_DEFECTO << endl;
    cout << setw(espacios) << mensaje << endl;
    cout << COLOR_DORADO << LINEA_DIVISORIA_MENSAJE_MENU << COLOR_POR_DEFECTO << endl << endl;
}

void Menu::mostrar_mensaje_volver_menu(int segundos) {
    cout << endl;
    cout << COLOR_VERDE << "Dentro de " << segundos << " segundos " << EMOJI_CRONOMETRO << "  se volvera al menú (:"
    << COLOR_POR_DEFECTO << endl;
    sleep((unsigned int)segundos);
}

Menu::~Menu() {}