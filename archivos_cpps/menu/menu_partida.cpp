#include "../../archivos_h/menu/menu_partida.h"

using namespace std;

Menu_partida::Menu_partida() {}

void Menu_partida::mostrar_mensaje_bienvenida() {
    string mensaje = COLOR_POR_DEFECTO + "      Hola! Bienvenido a Andypolis (:      " + COLOR_DORADO;

    cout << COLOR_DORADO;
    cout << "┌───────────────────────────────────────────┐" << endl;
    cout << "│" <<              mensaje              << "│" << endl;
    cout << "└───────────────────────────────────────────┘" << COLOR_POR_DEFECTO << endl;
}

void Menu_partida::mostrar_menu() {
    cout << endl;
    cout << "╔═══════════════════════════════════════════╗" << endl;
    cout << "║ 1. Construir edificio por nombre "           << EMOJI_CONSTRUIR_EDIFICIO_POR_NOMBRE  << setw(11) << "║" << endl;
    cout << "║"                                                                                     << setw(46) << "║" << endl;
    cout << "║ 2. Listar mis edificios construidos "        << EMOJI_LISTAR_CONSTRUIDOS             << setw(7)  << "║" << endl;
    cout << "║"                                                                                     << setw(46) << "║" << endl;
    cout << "║ 3. Demoler un edificio por coordenada "      << EMOJI_DEMOLER_POR_COORDENADA         << setw(5)  << "║" << endl;
    cout << "║"                                                                                     << setw(46) << "║" << endl;
    cout << "║ 4. Atacar un edificio por coordenada "       << EMOJI_ATACAR_POR_COORDENADA          << setw(6)  << "║" << endl;
    cout << "║"                                                                                     << setw(46) << "║" << endl;
    cout << "║ 5. Reparar un edificio por coordenada "      << EMOJI_REPARAR_POR_COORDENADA         << setw(5)  << "║" << endl;
    cout << "║"                                                                                     << setw(46) << "║" << endl;
    cout << "║ 6. Comprar bombas "                          << EMOJI_COMPRAR_BOMBAS                 << setw(25) << "║" << endl;
    cout << "║"                                                                                     << setw(46) << "║" << endl;
    cout << "║ 7. Consultar coordenada "                    << EMOJI_CONSULTAR_COORDENADAS          << setw(20) << "║" << endl;
    cout << "║"                                                                                     << setw(46) << "║" << endl;
    cout << "║ 8. Mostrar inventario "                      << EMOJI_INVENTARIO                     << setw(21) << "║" << endl;
    cout << "║"                                                                                     << setw(46) << "║" << endl;
    cout << "║ 9. Mostrar objetivos "                       << EMOJI_OBJETIVOS                      << setw(22) << "║" << endl;
    cout << "║"                                                                                     << setw(46) << "║" << endl;
    cout << "║ 10.Recolectar recursos producidos "          << EMOJI_RECURSOS_PRODUCIDOS            << setw(10) << "║" << endl;
    cout << "║"                                                                                     << setw(46) << "║" << endl;
    cout << "║ 11.Moverse a una coordenada "                << EMOJI_MOVERSE_A_UNA_COORDENADA       << setw(15) << "║" << endl;
    cout << "║"                                                                                     << setw(46) << "║" << endl;
    cout << "║ 12.Finalizar turno "                         << EMOJI_FINALIZAR_TURNO                << setw(24) << "║" << endl;
    cout << "║"                                                                                     << setw(46) << "║" << endl;
    cout << "║ 13.Guardar y salir "                         << EMOJI_GUARDAR_Y_SALIR                << setw(24) << "║" << endl;
    cout << "╚═══════════════════════════════════════════╝" << endl;
}

void Menu_partida::procesar_opcion(int opcion, Andypolis juego) {
        switch (opcion_ingresada) {
        case 1:
            juego.construir_edificio();
            break;
        case 2:
            juego.listar_mis_edificios();
            break;
        case 3:
            juego.demoler_edificio();
            break;
        case 4:
            juego.atacar_edificio();
            break;
        case 5:
            juego.reparar_edificio();
            break;
        case 6:
            juego.comprar_bombas();
            break;
        case 7:
            juego.consultar_coordenada();
            break;
        case 8:
            juego.mostrar_inventario();
            break;
        case 9:
            juego.mostrar_objetivos();
            break;
        case 10:
            juego.recolectar_recursos();
            break;
        case 11:
            juego.moverse();
            break;
        case 12:
            juego.finalizar_turno();
            break;
        case 13:
            juego.guardar_y_salir();
            break;
        default:
            cout << COLOR_ROJO << "Oops :(, opcion incorrecta. Intenta nuevamente" << COLOR_POR_DEFECTO << endl;
            break;
    }
}