#include "../archivos_h/menu/menu_partida.h"
#include "../archivos_h/menu/menu_configuracion.h"
#include "../archivos_h/materiales/madera.h"
#include "../archivos_h/materiales/metal.h"
#include "../archivos_h/materiales/bomba.h"
#include "../archivos_h/carga_de_datos/cargar_ubicaciones.h"
#include "../archivos_h/carga_de_datos/cargar_edificios.h"
#include "../archivos_h/carga_de_datos/cargar_mapa.h"
#include "../archivos_h/mapa.h"
#include "../archivos_h/arbol/abb.h"
#include "../archivos_h/juego/andypolis.h"

using namespace std;

int main(){
    Cargar_ubicaciones cargar_ubicaciones;
    Cargar_edificios cargar_edificios;
    Cargar_mapa cargar_mapa;

    Andypolis juego;
    Abb* nuevo_arbol = juego.devolver_arbol();
    Mapa* mapa = juego.devolver_mapa();

    cargar_edificios.carga_edificios(nuevo_arbol);
    cargar_mapa.carga_mapa(mapa);

    Jugador* jugador_1 = juego.devolver_jugador(1);
    Jugador* jugador_2 = juego.devolver_jugador(2);

    cargar_ubicaciones.carga_ubicaciones(mapa, jugador_1, jugador_2);
    //juego.listar_edificios(jugador_1);
    //jugador_1 -> listar_construidos();

    delete nuevo_arbol;
    return 0;
}