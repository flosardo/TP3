#include "../../archivos_h/menu/menu_configuracion.h"

using namespace std;

Menu_configuracion::Menu_configuracion() {}

void Menu_configuracion::mostrar_mensaje_bienvenida(){
    cout << COLOR_DORADO << "        ┌───────────────────────────────────────────────────────────┐" << endl;
    cout << "        │" << COLOR_ROJO << "                No se encontro una partida guardada :(" << COLOR_DORADO << "            │" << endl;
    cout << "        └───────────────────────────────────────────────────────────┘"  << COLOR_POR_DEFECTO << endl;
}

void Menu_configuracion::mostrar_menu() {
    cout << endl;
    cout << COLOR_DORADO << "╔═══════════════════════════════════════════╗" << endl;
    cout << "║ " << COLOR_POR_DEFECTO << "1. Modificar edificio por nombre "  << COLOR_DORADO <<  EMOJI_MODIFICAR_EDIFICIO_POR_NOMBRE  << "        ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ " << COLOR_POR_DEFECTO << "2. Listar los edificios " << COLOR_DORADO << EMOJI_LISTAR_TODOS_LOS_EDIFICIOS << "                 ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ " << COLOR_POR_DEFECTO << "3. Mostrar mapa " <<  COLOR_DORADO << EMOJI_MOSTRAR_MAPA << "                        ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ " << COLOR_POR_DEFECTO << "4. Comenzar partida " << COLOR_DORADO << EMOJI_COMENZAR_PARTIDA <<  "                    ║" << endl;
    cout << "║                                           ║" << endl;
    cout << "║ " << COLOR_POR_DEFECTO << "5. Guardar y salir " << COLOR_DORADO << EMOJI_GUARDAR_Y_SALIR << "                     ║" << endl;
    cout << "╚═══════════════════════════════════════════╝" << COLOR_POR_DEFECTO << endl;
} 

void Menu_configuracion::procesar_opcion(int opcion, Andypolis juego) {
    switch (opcion_ingresada) {
        case 1:
            juego.modificar_edificio_nombre();
            break;
        case 2:
            juego.listar_edificios(juego.devolver_jugador_actual());
            break;
        case 3:
            juego.mostrar_mapa();
            break;
        case 4:
            juego.comenzar_partida();
            break;
        case 5:
            juego.guardar_y_salir();
            break;
        default:
            cout << COLOR_ROJO << "Oops :(, opcion incorrecta. Intenta nuevamente" << COLOR_POR_DEFECTO << endl;
            break;
    }
}