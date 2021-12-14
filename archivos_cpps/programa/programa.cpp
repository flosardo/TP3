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
        menu_configuracion.mostrar_mensaje(COLOR_ROJO + "   No se encontro una partida guardada :(  " + COLOR_DORADO);

    while (!this -> existe_ubicaciones && (opcion != OPCION_SALIR) && (opcion != OPCION_SALIR_JUEGO)) {
        cout << FONDO_MARRON << MENSAJE_ANDYPOLIS << COLOR_POR_DEFECTO << endl;
        menu_partida.mostrar_mensaje(COLOR_POR_DEFECTO + " Menu de configuración " + COLOR_DORADO);
        menu_configuracion.mostrar_menu();
        opcion = menu_configuracion.pedir_opcion();
        menu_configuracion.procesar_opcion(opcion, juego);
    }

    Jugador* jugador = nullptr;
    while (!this -> juego -> gano_la_partida() && opcion != OPCION_SALIR_JUEGO) {
        cout << FONDO_MARRON <<  MENSAJE_ANDYPOLIS << COLOR_POR_DEFECTO << endl;
        menu_partida.mostrar_mensaje(COLOR_POR_DEFECTO + " Menu de la partida " + COLOR_DORADO);
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

    if(this -> juego -> gano_la_partida() && this -> juego -> obtener_jugador_actual() -> obtener_nombre() == NUMERO_JUGADOR_1)
        cout << FONDO_VERDE << MENSAJE_FELICIDADES << " " << MENSAJE_JUGADOR_1  << COLOR_POR_DEFECTO << endl;
    else if(this -> juego -> gano_la_partida())
        cout << FONDO_VERDE << MENSAJE_FELICIDADES << " " << MENSAJE_JUGADOR_2 << COLOR_POR_DEFECTO << endl;

    materiales.guardar_materiales(this -> juego -> obtener_jugador(NUMERO_JUGADOR_1), this -> juego -> obtener_jugador(NUMERO_JUGADOR_2));
    edificios.guardar_edificios(this -> juego -> obtener_arbol());
    ubicacion.guardar_ubicaciones(this -> juego -> obtener_mapa(), this -> juego -> obtener_jugador(NUMERO_JUGADOR_1), this -> juego -> obtener_jugador(NUMERO_JUGADOR_2));
    sleep(2);
    system(CLR_SCREEN);
    cout << MENSAJE_CREDITOS << COLOR_POR_DEFECTO << endl;
    cout << MENSAJE_BRAYAN << endl;
    cout << MENSAJE_EZEQUIEL << endl;
    cout << MENSAJE_FRANCO << endl;
    cout << MENSAJE_SEBASTIAN << endl;
}

Programa::~Programa(){
    delete this -> juego;
    juego = nullptr;
}