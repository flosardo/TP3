#include "../../archivos_h/menu/menu_partida.h"

using namespace std;

Menu_partida::Menu_partida() {}

void Menu_partida::mostrar_menu() {
    cout << endl;
    //cout << MENU_PARTIDA << endl;
    cout << "╔═══════════════════════════════════════════╗" << endl;
    cout << "║ 1. Construir edificio por nombre  "  << EMOJI_CONSTRUIR_EDIFICIO_POR_NOMBRE  << "       ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 2. Listar mis edificios construidos  " << EMOJI_LISTAR_CONSTRUIDOS << "   ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 3. Demoler un edificio por coordenada  " << EMOJI_DEMOLER_POR_COORDENADA << " ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 4. Atacar un edificio por coordenada " << EMOJI_ATACAR_POR_COORDENADA << "   ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 5. Reparar un edificio por coordenada " << EMOJI_REPARAR_POR_COORDENADA << "  ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 6. Comprar bombas " << EMOJI_COMPRAR_BOMBAS << "                      ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 7. Consultar coordenada  " << EMOJI_CONSULTAR_COORDENADAS << "                ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 8. Mostrar inventario  " << EMOJI_INVENTARIO << "                 ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 9. Mostrar objetivos " << EMOJI_OBJETIVOS << "                   ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 10.Recolectar recursos producidos  " << EMOJI_RECURSOS_PRODUCIDOS << "      ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 11.Moverse a una coordenada " << EMOJI_MOVERSE_A_UNA_COORDENADA << "            ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 12.Finalizar turno " << EMOJI_FINALIZAR_TURNO << "                     ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 13.Guardar y salir  " << EMOJI_GUARDAR_Y_SALIR << "                    ║" << endl;
    cout << "╚═══════════════════════════════════════════╝" << endl;
}