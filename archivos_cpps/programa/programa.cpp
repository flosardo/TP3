#include "../../archivos_h/programa/programa.h"

Programa::Programa() {
    this -> juego = Andypolis();
    edificios.carga_edificios(juego.devolver_arbol());
    //materiales.carga_materiales(juego.devolver_jugador(NUMERO_JUGADOR_1), juego.devolver_jugador(NUMERO_JUGADOR_2));
    mapa.carga_mapa(juego.devolver_mapa());
    this -> existe_ubicaciones = ubicacion.carga_ubicaciones(juego.devolver_mapa(), juego.devolver_jugador(NUMERO_JUGADOR_1), juego.devolver_jugador(NUMERO_JUGADOR_2));
}

void Programa::empezar() {
    int opcion = OPCION_EMPEZAR_JUEGO;  //Inicializo con un valor por defecto.

    if(!existe_ubicaciones)
        menu_configuracion.mostrar_mensaje_bienvenida();
    
    while((!this -> existe_ubicaciones && opcion != OPCION_EMPEZAR_JUEGO)  || (opcion != 4 && opcion != 5)){
        
        menu_configuracion.mostrar_menu();
        opcion = menu_configuracion.pedir_opcion();
        menu_configuracion.procesar_opcion(opcion, juego);
    }

    /*

    opcion = OPCION_EMPEZAR_JUEGO;

    while(opcion != OPCION_SALIR_JUEGO){

        menu_partida.mostrar_mensaje_bienvenida();
        menu_partida.mostrar_menu();
        opcion = menu_configuracion.pedir_opcion();
        menu_partida.procesar_opcion(opcion, juego);
    }

    */
}

void Programa::finalizar() {
    /*
    edificios.editar_archivo_edificios(juego.devolver_arbol());
    materiales.editar_archivo_materiales(juego.devolver_jugador(JUGADOR_1), juego.devolver_jugador(JUGADOR_2));
    mapa.editar_archivo_mapa(juego.devolver_mapa());
    this -> existe_ubicaciones = ubicacion.carga_ubicaciones(juego.devolver_mapa(), juego.devolver_jugador(JUGADOR_1), juego.devolver_jugador(JUGADOR_2));
    */
}