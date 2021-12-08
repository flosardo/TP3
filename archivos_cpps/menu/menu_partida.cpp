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
    string borde = COLOR_DORADO + "║" + COLOR_POR_DEFECTO;
    cout << COLOR_DORADO;
    cout << "╔═══════════════════════════════════════════╗" << endl;
    cout << borde << " 1. Construir edificio por nombre "           << EMOJI_CONSTRUIR_EDIFICIO_POR_NOMBRE  << setw(20) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 2. Listar mis edificios construidos "        << EMOJI_LISTAR_CONSTRUIDOS             << setw(16) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 3. Demoler un edificio por coordenada "      << EMOJI_DEMOLER_POR_COORDENADA         << setw(14) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 4. Atacar un edificio por coordenada "       << EMOJI_ATACAR_POR_COORDENADA          << setw(15) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 5. Reparar un edificio por coordenada "      << EMOJI_REPARAR_POR_COORDENADA         << setw(14) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 6. Comprar bombas "                          << EMOJI_COMPRAR_BOMBAS                 << setw(34) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 7. Consultar coordenada "                    << EMOJI_CONSULTAR_COORDENADAS          << setw(29) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 8. Mostrar inventario "                      << EMOJI_INVENTARIO                     << setw(30) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 9. Mostrar objetivos "                       << EMOJI_OBJETIVOS                      << setw(31) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 10.Recolectar recursos producidos "          << EMOJI_RECURSOS_PRODUCIDOS            << setw(19) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 11.Moverse a una coordenada "                << EMOJI_MOVERSE_A_UNA_COORDENADA       << setw(24) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 12.Mostrar mapa "                            << EMOJI_MOSTRAR_MAPA                   << setw(36) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 13.Finalizar turno "                         << EMOJI_FINALIZAR_TURNO                << setw(33) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 14.Guardar y salir "                         << EMOJI_GUARDAR_Y_SALIR                << setw(33) << borde << endl << COLOR_DORADO;
    cout << "╚═══════════════════════════════════════════╝" << COLOR_POR_DEFECTO << endl;
}

void Menu_partida::procesar_opcion(int & opcion_ingresada, Andypolis & juego) {
    switch (opcion_ingresada) {
        case OPCION_CONSTRUIR_EDIFICIO:
            juego.construir_edificio();
            break;
        case OPCION_LISTAR_MIS_EDIFICIOS:
            juego.listar_mis_edificios();
            break;
        case OPCION_DEMOLER_EDIFICIO:
            juego.demoler_edificio();
            break;
        case OPCION_ATACAR_EDIFICIO_COORDENADA:
            juego.atacar_edificio();
            break;
        case OPCION_REPARAR_EDIFICO_COODENADA:
            juego.reparar_edificio();
            break;
        case OPCION_COMPRAR_BOMBAS:
            juego.comprar_bombas();
            break;
        case OPCION_CONSULTAR_COORDENADAS:
            juego.consultar_coordenada();
            break;
        case OPCION_MOSTRAR_INVENTARIO:
            juego.mostrar_inventario();
            break;
        case OPCION_MOSTRAR_OBJETIVOS:
            juego.mostrar_objetivos();
            break;
        case OPCION_RECOLECTAR_RECURSOS_PRODUCIOS:
            juego.recolectar_recursos();
            break;
        case OPCION_MOVERSE_UNA_COORDENADA:
            juego.moverse();
            break;
        case OPCION_MOSTRAR_MAPA_JUEGO:
            juego.mostrar_mapa();
            break;
        case OPCION_FINALIZAR_TURNO:
            opcion_ingresada = OPCION_SALIR;
            juego.finalizar_turno();
            break;
        case OPCION_GUARDAR_SALIR_PARTIDA:
            opcion_ingresada = OPCION_SALIR_JUEGO;
            juego.guardar_y_salir();
            break;
        default:
            cout << COLOR_ROJO << "Oops :(, opcion incorrecta. Intenta nuevamente" << COLOR_POR_DEFECTO << endl;
            break;
    }
}