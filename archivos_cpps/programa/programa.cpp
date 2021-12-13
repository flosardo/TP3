#include "../../archivos_h/programa/programa.h"

using namespace std;

Programa::Programa() {
    this -> juego = new Andypolis();
    edificios.carga_edificios(this -> juego -> obtener_arbol());
    this -> juego -> cargar_objetivos();
    mapa.carga_mapa(this -> juego -> obtener_mapa());
    materiales.carga_materiales(this -> juego -> obtener_jugador(NUMERO_JUGADOR_1), this -> juego -> obtener_jugador(NUMERO_JUGADOR_2));
    this -> existe_ubicaciones = ubicacion.carga_ubicaciones(this -> juego -> obtener_mapa(), this -> juego -> obtener_jugador(NUMERO_JUGADOR_1), this -> juego -> obtener_jugador(NUMERO_JUGADOR_2));
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

    Jugador* jugador = nullptr;
    while (!this -> juego -> gano_la_partida() && opcion != OPCION_SALIR_JUEGO) {
        menu_partida.mostrar_mensaje_bienvenida();
        menu_partida.mostrar_menu();

        jugador = this -> juego -> obtener_jugador_actual();
        this -> juego -> verificar_energia(opcion);
        cout << "TURNO DEL JUGADOR: " << jugador -> obtener_codigo_emoji() << VACIO
             << EMOJI_ENERGIA << jugador -> obtener_energia_actual() << endl << endl;

        if (opcion != OPCION_FINALIZAR_TURNO && opcion != OPCION_SALIR_JUEGO)
            opcion = menu_partida.pedir_opcion();
        if (opcion != OPCION_SALIR_JUEGO)
            menu_partida.procesar_opcion(opcion, juego);
    }
}

void Programa::finalizar() {
    materiales.guardar_materiales(this -> juego -> obtener_jugador(NUMERO_JUGADOR_1), this -> juego -> obtener_jugador(NUMERO_JUGADOR_2));
    edificios.guardar_edificios(this -> juego -> obtener_arbol());
    ubicacion.guardar_ubicaciones(this -> juego -> obtener_mapa(), this -> juego -> obtener_jugador(NUMERO_JUGADOR_1), this -> juego -> obtener_jugador(NUMERO_JUGADOR_2));
}

Programa::~Programa(){
    delete this -> juego;
}