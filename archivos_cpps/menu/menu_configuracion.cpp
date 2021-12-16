#include "../../archivos_h/menu/menu_configuracion.h"

using namespace std;

Menu_configuracion::Menu_configuracion() {}

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

void Menu_configuracion::procesar_opcion(int & opcion, Andypolis* juego) {
    switch (opcion_ingresada) {
        case OPCION_MODIFICAR_EDIFICIO_NOMBRE:
            mostrar_mensaje("OPCION MODIFICAR EDIFICIO POR NOMBRE", 39);
            juego -> modificar_edificio_nombre();
            mostrar_mensaje_volver_menu(TIEMPO_MODIFICAR_EDIFICIO);
            break;
        case OPCION_LISTAR_TOTAL_EDIFICIOS:
            mostrar_mensaje("OPCION LISTAR TOTAL DE EDIFICIOS", 38);
            juego -> listar_edificios();
            mostrar_mensaje_volver_menu(TIEMPO_LISTAR_TOTAL_EDIFICIOS);
            break;
        case OPCION_MOSTRAR_MAPA_CONFIGURACION:
            mostrar_mensaje("MAPA", 22);
            juego -> mostrar_mapa();
            mostrar_mensaje_volver_menu(TIEMPO_MOSTRAR_MAPA);
            break;
        case OPCION_COMENZAR_PARTIDA:
            opcion = OPCION_SALIR;
            juego -> comenzar_partida();
            mostrar_mensaje_volver_menu(TIEMPO_COMENZAR_PARTIDA);
            break;
        case OPCION_GUARDAR_SALIR_CONFIGURACION:
            mostrar_mensaje("SE GUARDARON LOS CAMBIOS..", 35);
            opcion = OPCION_SALIR_JUEGO;
            mostrar_mensaje_volver_menu(TIEMPO_GUARDAR_SALIR);
            break;
        default:
            cout << COLOR_ROJO << "Oops :(, opcion incorrecta. Intenta nuevamente" << COLOR_POR_DEFECTO << endl;
            mostrar_mensaje_volver_menu(TIEMPO_ERROR);
            break;
    }
    system(CLR_SCREEN);
}