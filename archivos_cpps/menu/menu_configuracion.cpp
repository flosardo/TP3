#include "../../archivos_h/menu/menu_configuracion.h"

using namespace std;

Menu_configuracion::Menu_configuracion() {}

void Menu_configuracion::mostrar_mensaje_bienvenida() {
    string mensaje = COLOR_ROJO + "   No se encontro una partida guardada :(  " + COLOR_DORADO;
    cout << COLOR_DORADO;
    cout << "┌───────────────────────────────────────────┐" << endl;
    cout << "│" <<              mensaje              << "│" << endl;
    cout << "└───────────────────────────────────────────┘" << COLOR_POR_DEFECTO;
    cout << endl << endl;
}

void Menu_configuracion::mostrar_menu() {
    string borde = COLOR_DORADO + "║" + COLOR_POR_DEFECTO;
    cout << COLOR_DORADO;
    cout << "╔═══════════════════════════════════════════╗" << endl;
    cout << borde << " 1. Modificar edificio por nombre "   << EMOJI_MODIFICAR_EDIFICIO_POR_NOMBRE  << setw(20) << borde << endl;
    cout << borde                                                                                   << setw(55) << borde << endl;
    cout << borde << " 2. Listar los edificios "            << EMOJI_LISTAR_TODOS_LOS_EDIFICIOS     << setw(29) << borde << endl;
    cout << borde                                                                                   << setw(55) << borde << endl;
    cout << borde << " 3. Mostrar mapa "                    << EMOJI_MOSTRAR_MAPA                   << setw(36) << borde << endl;
    cout << borde                                                                                   << setw(55) << borde << endl;
    cout << borde << " 4. Comenzar partida "                << EMOJI_COMENZAR_PARTIDA               << setw(33) << borde << endl;
    cout << borde                                                                                   << setw(55) << borde << endl;
    cout << borde << " 5. Guardar y salir "                 << EMOJI_GUARDAR_Y_SALIR                << setw(33) << borde << endl << COLOR_DORADO;
    cout << "╚═══════════════════════════════════════════╝" << COLOR_POR_DEFECTO;
    cout << endl;
} 

void Menu_configuracion::procesar_opcion(int opcion, Andypolis & juego) {
    switch (opcion_ingresada) {
        case OPCION_MODIFICAR_EDIFICIO_NOMBRE:
            juego.modificar_edificio_nombre();
            break;
        case OPCION_LISTAR_TOTAL_EDIFICIOS:
            juego.listar_edificios();
            break;
        case OPCION_MOSTRAR_MAPA:
            juego.mostrar_mapa();
            break;
        case OPCION_COMENZAR_PARTIDA:
            juego.comenzar_partida();
            break;
        case OPCION_GUARDAR_SALIR_CONFIGURACION:
            juego.guardar_y_salir();
            break;
        default:
            cout << COLOR_ROJO << "Oops :(, opcion incorrecta. Intenta nuevamente" << COLOR_POR_DEFECTO << endl;
            break;
    }
}