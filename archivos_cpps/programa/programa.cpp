#include "../../archivos_h/programa/programa.h"

using namespace std;

Programa::Programa() {
    this -> juego = Andypolis();
    edificios.carga_edificios(juego.obtener_arbol());
    mapa.carga_mapa(juego.obtener_mapa());
    materiales.carga_materiales(juego.obtener_jugador(NUMERO_JUGADOR_1), juego.obtener_jugador(NUMERO_JUGADOR_2));
    this -> existe_ubicaciones = ubicacion.carga_ubicaciones(juego.obtener_mapa(), juego.obtener_jugador(NUMERO_JUGADOR_1), juego.obtener_jugador(NUMERO_JUGADOR_2));
}

void Programa::empezar() {
    int opcion = OPCION_EMPEZAR;  //Inicializo con un valor por defecto.

    if (!this -> existe_ubicaciones)
        menu_configuracion.mostrar_mensaje_bienvenida();

    while (!this -> existe_ubicaciones && (opcion != OPCION_SALIR) && (opcion != OPCION_SALIR_JUEGO)) {
        menu_configuracion.mostrar_menu();
        opcion = menu_configuracion.pedir_opcion();
        menu_configuracion.procesar_opcion(opcion, juego);
    }

    opcion = opcion == OPCION_SALIR_JUEGO ? OPCION_SALIR_JUEGO : OPCION_EMPEZAR;

    while (opcion != OPCION_SALIR_JUEGO) {
        juego.verificar_energia(opcion);
        cout << "TURNO DEL JUGADOR: " << this -> juego.obtener_jugador_actual() -> obtener_codigo_emoji() << " ";
        cout << EMOJI_ENERGIA << this -> juego.obtener_jugador_actual() -> obtener_energia_actual() << endl;
        menu_partida.mostrar_mensaje_bienvenida();
        menu_partida.mostrar_menu();
        if(opcion != OPCION_FINALIZAR_TURNO) {
            opcion = menu_partida.pedir_opcion();
        }
        menu_partida.procesar_opcion(opcion, juego);
    }
}

void Programa::finalizar() {
    materiales.guardar_materiales(juego.obtener_jugador(JUGADOR_1), juego.obtener_jugador(JUGADOR_2));
    edificios.guardar_edificios(juego.obtener_arbol());
    // mapa.editar_archivo_mapa(juego.obtener_mapa());
    // this -> existe_ubicaciones = ubicacion.carga_ubicaciones(juego.obtener_mapa(), juego.obtener_jugador(JUGADOR_1), juego.obtener_jugador(JUGADOR_2));
}