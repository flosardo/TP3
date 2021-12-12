#include "../../archivos_h/programa/programa.h"

using namespace std;

Programa::Programa() {
    this -> juego = Andypolis();
    edificios.carga_edificios(juego.obtener_arbol());
    mapa.carga_mapa(juego.obtener_mapa());
    materiales.carga_materiales(juego.obtener_jugador(NUMERO_JUGADOR_1), juego.obtener_jugador(NUMERO_JUGADOR_2));
    this -> existe_ubicaciones = ubicacion.carga_ubicaciones(juego.obtener_mapa(), juego.obtener_jugador(NUMERO_JUGADOR_1), juego.obtener_jugador(NUMERO_JUGADOR_2));
    juego.cargar_grafo();
}

void Programa::empezar() {
    system(CLR_SCREEN);
    int opcion = OPCION_EMPEZAR;  //Inicializo con un valor por defecto.

    if (!this -> existe_ubicaciones)
        menu_configuracion.mostrar_mensaje_bienvenida();

    while (!this -> existe_ubicaciones && (opcion != OPCION_SALIR) && (opcion != OPCION_SALIR_JUEGO)) {
        menu_configuracion.mostrar_menu();
        opcion = menu_configuracion.pedir_opcion();
        menu_configuracion.procesar_opcion(opcion, juego);
    }

    juego.inicializar_objetivos();
    Jugador* jugador = 0;
    while (!juego.gano_la_partida() && opcion != OPCION_SALIR_JUEGO) {
        menu_partida.mostrar_mensaje_bienvenida();
        menu_partida.mostrar_menu();

        jugador = juego.obtener_jugador_actual();
        juego.verificar_energia(opcion);
        cout << "TURNO DEL JUGADOR: " << jugador -> obtener_codigo_emoji() << VACIO
             << EMOJI_ENERGIA << jugador -> obtener_energia_actual() << endl << endl;

        if (opcion != OPCION_FINALIZAR_TURNO && opcion != OPCION_SALIR_JUEGO)
            opcion = menu_partida.pedir_opcion();
        if (opcion != OPCION_SALIR_JUEGO)
            menu_partida.procesar_opcion(opcion, juego);
    }
}

void Programa::finalizar() {
    materiales.guardar_materiales(juego.obtener_jugador(NUMERO_JUGADOR_1), juego.obtener_jugador(NUMERO_JUGADOR_2));
    edificios.guardar_edificios(juego.obtener_arbol());
    ubicacion.guardar_ubicaciones(juego.obtener_mapa(), juego.obtener_jugador(NUMERO_JUGADOR_1), juego.obtener_jugador(NUMERO_JUGADOR_2));
}