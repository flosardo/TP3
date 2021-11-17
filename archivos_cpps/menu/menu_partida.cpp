#include "../../archivos_h/menu/menu_partida.h"

using namespace std;

Menu_partida::Menu_partida() {}

void Menu_partida::mostrar_menu(){
    cout << endl;
    cout << "𝕄𝔼ℕ𝕌" << endl;
    cout << "╔═══════════════════════════════════════════╗" << endl;
    cout << "║ 1. Construir edificios por nombre         ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 2. Listar mis edificios construidos       ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 3. Demoler un edificio por coordenada     ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 4. Aatcar un edificio por coordenada      ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 5. Reparar un edificio por coordenada     ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 6. Comprar bombas                         ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 7. Consultar coordenadas                  ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 8. Mostrar inventario                     ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 9. Mostrar objetivos                      ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 10. Recolectar recursos producidos        ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 11. Moverse a una coordenada              ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 12. Finalizar turno                       ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 13. Guardar y salir                       ║" << endl;
    cout << "╚═══════════════════════════════════════════╝" << endl;
}

int Menu_partida::pedir_opcion(){
    cout << "Ingrese la opcion deseada: ";
    cin >> this -> opcion_ingresada;
    return this -> opcion_ingresada;
}