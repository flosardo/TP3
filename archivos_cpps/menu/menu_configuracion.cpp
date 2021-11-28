#include "../../archivos_h/menu/menu_configuracion.h"

using namespace std;

Menu_configuracion::Menu_configuracion() {}

void Menu_configuracion::mostrar_menu() {
    cout << endl;
    cout << "𝕄𝔼ℕ𝕌" << endl;
    cout << "╔═══════════════════════════════════════════╗" << endl;
    cout << "║ 1. Modificar edificio por nombre "  <<  EMOJI_MODIFICAR_EDIFICIO_POR_NOMBRE  << "        ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 2. Listar los edificios " << EMOJI_LISTAR_TODOS_LOS_EDIFICIOS << "                 ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 3. Mostrar mapa " << EMOJI_MOSTRAR_MAPA << "                        ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 4. Comenzar partida " << EMOJI_COMENZAR_PARTIDA <<  "                    ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ 5. Guardar y salir " << EMOJI_GUARDAR_Y_SALIR << "                     ║" << endl;
    cout << "╚═══════════════════════════════════════════╝" << endl;
} 