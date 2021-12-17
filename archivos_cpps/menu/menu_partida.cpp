#include "../../archivos_h/menu/menu_partida.h"

using namespace std;

Menu_partida::Menu_partida() {}

void Menu_partida::mostrar_menu() {
    string borde = COLOR_DORADO + "║" + COLOR_POR_DEFECTO;
    cout << COLOR_DORADO;
    cout << "╔═══════════════════════════════════════════╗" << endl;
    cout << borde << " 1. Construir edificio por nombre " << EMOJI_CONSTRUIR_EDIFICIO_POR_NOMBRE << setw(20) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 2. Listar mis edificios construidos " << EMOJI_CHECK << setw(16) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 3. Demoler un edificio por coordenada " << EMOJI_DEMOLER_POR_COORDENADA << setw(14) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 4. Atacar un edificio por coordenada " << EMOJI_ATACAR_POR_COORDENADA << setw(15) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 5. Reparar un edificio por coordenada " << EMOJI_REPARAR_POR_COORDENADA << setw(14) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 6. Comprar bombas " << EMOJI_COMPRAR_BOMBAS << setw(34) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 7. Consultar coordenada " << EMOJI_CONSULTAR_COORDENADAS << setw(29) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 8. Mostrar inventario " << EMOJI_INVENTARIO << setw(30) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 9. Mostrar objetivos " << EMOJI_OBJETIVOS << setw(31) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 10.Recolectar recursos producidos " << EMOJI_RECURSOS_PRODUCIDOS << setw(19) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 11.Moverse a una coordenada " << EMOJI_MOVERSE_A_UNA_COORDENADA << setw(24) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 12.Mostrar mapa " << EMOJI_MOSTRAR_MAPA << setw(36) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 13.Mostrar preguntas frecuentes " << EMOJI_REGLAS_JUEGO << setw(20) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 14.Finalizar turno " << EMOJI_FINALIZAR_TURNO << setw(33) << borde << endl;
    cout << borde << setw(55) << borde << endl;
    cout << borde << " 15.Guardar y salir " << EMOJI_GUARDAR_Y_SALIR << setw(33) << borde << endl << COLOR_DORADO;
    cout << "╚═══════════════════════════════════════════╝" << COLOR_POR_DEFECTO << endl;
}

void Menu_partida::procesar_opcion(int & opcion_ingresada, Andypolis* juego) {
    switch (opcion_ingresada) {
        case OPCION_CONSTRUIR_EDIFICIO:
            mostrar_mensaje("OPCION CONSTRUIR EDIFICIO", 13);
            juego -> construir_edificio();
            mostrar_mensaje_volver_menu(TIEMPO_CONSTRUIR_EDIFICIO);
            break;
        case OPCION_LISTAR_MIS_EDIFICIOS:
            mostrar_mensaje("OPCION LISTAR MIS EDIFICIOS", 12);
            juego -> listar_mis_edificios();
            mostrar_mensaje_volver_menu(TIEMPO_LISTAR_TOTAL_EDIFICIOS);
            break;
        case OPCION_DEMOLER_EDIFICIO:
            mostrar_mensaje("OPCION DEMOLER EDIFICIO", 15);
            juego -> demoler_edificio();
            mostrar_mensaje_volver_menu(TIEMPO_DEMOLER_EDIFICIO);
            break;
        case OPCION_ATACAR_EDIFICIO_COORDENADA:
            mostrar_mensaje("OPCION ATACAR EDIFICIO POR COORDENADA", 7);
            juego -> atacar_edificio();
            mostrar_mensaje_volver_menu(TIEMPO_ATACAR_EDIFICIO_COORDENADA);
            break;
        case OPCION_REPARAR_EDIFICO_COODENADA:
            mostrar_mensaje("OPCION REPARAR EDIFICIO POR COORDENADA", 7);
            juego -> reparar_edificio();
            mostrar_mensaje_volver_menu(TIEMPO_REPARAR_EDIFICIO_COORDENADA);
            break;
        case OPCION_COMPRAR_BOMBAS:
            mostrar_mensaje("OPCION COMPRAR BOMBAS", 15);
            juego -> comprar_bombas();
            mostrar_mensaje_volver_menu(TIEMPO_COMPRAR_BOMBAS);
            break;
        case OPCION_CONSULTAR_COORDENADAS:
            mostrar_mensaje("OPCION CONSULTAR COORDENADAS", 12);
            juego -> consultar_coordenada();
            mostrar_mensaje_volver_menu(TIEMPO_CONSULTAR_COORDENADAS);
            break;
        case OPCION_MOSTRAR_INVENTARIO:
            mostrar_mensaje("OPCION MOSTRAR INVENTARIO", 13);
            juego -> mostrar_inventario();
            mostrar_mensaje_volver_menu(TIEMPO_MOSTRAR_INVENTARIO);
            break;
        case OPCION_MOSTRAR_OBJETIVOS:
            mostrar_mensaje("OPCION MOSTRAR OBJETIVOS", 15);
            juego -> mostrar_objetivos();
            mostrar_mensaje_volver_menu(TIEMPO_MOSTRAR_OBJETIVOS);
            break;
        case OPCION_RECOLECTAR_RECURSOS_PRODUCIOS:
            mostrar_mensaje("OPCION RECOLECTAR RECURSOS PRODUCIDOS", 7);
            juego -> recolectar_recursos();
            mostrar_mensaje_volver_menu(TIEMPO_RECOLECTAR_RECURSOS_PRODUCIDOS);
            break;
        case OPCION_MOVERSE_UNA_COORDENADA:
            mostrar_mensaje("OPCION MOVER PERSONAJE UNA COORDENADA", 6);
            juego -> moverse();
            mostrar_mensaje_volver_menu(TIEMPO_MOVERSE_UNA_COORDENADA);
            break;
        case OPCION_MOSTRAR_MAPA_JUEGO: 
            mostrar_mensaje("MAPA ANDYPOLIS", 17);
            juego -> mostrar_mapa();
            mostrar_mensaje_volver_menu(TIEMPO_MOSTRAR_MAPA);
            break;
        case OPCION_MOSTRAR_PREGUNTAS_FRECUENTES: 
            mostrar_mensaje("PREGUNTAS FRECUENTES", 31);
            juego -> mostrar_preguntas_frecuentes();
            mostrar_mensaje_volver_menu(TIEMPO_MOSTRAR_PREGUNTAS_FRECUENTES);
            break;
        case OPCION_FINALIZAR_TURNO:
            mostrar_mensaje("EL TURNO HA FINALIZADO..", 15);
            opcion_ingresada = OPCION_SALIR;
            juego -> finalizar_turno();
            mostrar_mensaje_volver_menu(TIEMPO_FINALIZAR_TURNO);
            break;
        case OPCION_GUARDAR_SALIR_PARTIDA:
            mostrar_mensaje("SE GUARDARON LOS CAMBIOS..", 13);
            opcion_ingresada = OPCION_SALIR_JUEGO;
            mostrar_mensaje_volver_menu(TIEMPO_GUARDAR_SALIR);
            break;
        default:
            cout << COLOR_ROJO << "Oops :(, opcion incorrecta. Intenta nuevamente" << COLOR_POR_DEFECTO << endl;
            mostrar_mensaje_volver_menu(TIEMPO_ERROR);
            break;
    }
    system(CLR_SCREEN);
}