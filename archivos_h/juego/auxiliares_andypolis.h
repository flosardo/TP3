#ifndef _AUXILIARES_ANDYPOLIS_H_
#define _AUXILIARES_ANDYPOLIS_H_

#include "../../archivos_h/arbol/abb.h"
#include "../../archivos_h/mapa.h"
#include "../construcciones/aserradero.h"
#include "../construcciones/mina.h"
#include "../construcciones/mina_oro.h"
#include "../construcciones/fabrica.h"
#include "../construcciones/escuela.h"
#include "../construcciones/planta_electrica.h"
#include "../construcciones/obelisco.h"
#include "../materiales/piedra.h"
#include "../materiales/madera.h"
#include "../materiales/metal.h"
#include "../materiales/andycoins.h"
#include <unistd.h>
#include <algorithm>

class Auxiliares_andypolis {

    public:

        /*
        *Post: Construirá un objeto de tipo Auxiliares_andypolis con los valores por defecto.
        */
        Auxiliares_andypolis();

        /*
        *Post: Seleccionará el jugador que va a ser el actual.
        */
        void seleccionar_jugador(std::string & nombre_1, std::string & nombre_2);

        /*
        *Post: Cambiara el turno del jugador actual.
        */
        Jugador* cambiar_turno(Jugador* jugador_actual, Jugador* jugador_1, Jugador* jugador_2);

        /*
        *Post: Asignará el turno aleatoriamente, para el jugador que va a empezar.
        */
        Jugador* asignar_turno(Jugador* jugador_1, Jugador* jugador_2);

        /*
        *Pre: Que el parametro no sea null
        *Post: Aumentará los materiales producidos.
        */
        void aumentar_materiales_producidos(Jugador* jugador_actual);

        /*
        *Pre: Que los parametros mapa, jugador_actual, jugador_1, jugador_2 no sean null, que la fila y columna sean >= 0.
        *Post: Aumentará los materiales producidos.
        */
        void atacar_edificio_auxiliar(Mapa* mapa, Jugador* jugador_actual, Jugador* jugador_1, Jugador* jugador_2, int fila, int columna);

        /*
        *Pre: Que el parametro no sea null.
        *Post: Hará la lluvia de materiales.
        */
        void lluvia_materiales(Mapa* mapa);

        /*
        *Pre: Que el mapa no sea null, y cantidad_a_generar sea >= 0.
        *Post: Hará la lluvia de un material.
        */
        void lluvia_material(std::string nombre_material, int cantidad_a_generar, Mapa* mapa);

        /*
        *Post: Devolvera un puntero de tipo Material con el material deseado.
        */
        Material* generar_material(std::string nombre_material);

        /*
        *Post: Obtendrá un puntero con las coordenadas pedidas.
        */
        int* pedir_coordenadas(Mapa* mapa);

        /*
        *Pre: Que los parámetros sean >= 0.
        *Post: Obtendrá true si las coordenadas son validas, false en caso contrario.
        */
        bool validar_coordenadas(Mapa* mapa, int fila, int columna);

        /*
        *Pre: Que la opcion sea >= 0.
        *Post: Verificará la energía.
        */
        void verificar_energia(Jugador* jugador_actual, int & opcion_ingresada);

        /*
        *Pre: Que los parámetros sean >= 0.
        *Post: Obtendrá true si el casillero es válido, false en caso contrario.
        */
        bool es_casillero_valido(Mapa* mapa, int fila, int columna);

        /*
        *Post: Obtendrá un string con el string del nombre del edificio pedido.
        */
        std::string pedir_nombre_edificio();

        /*
        *Post: Obtendrá la nueva cantidad de material pedida.
        */
        int pedir_nueva_cantidad_material(std::string material);

        /*
        *Pre: Que el parámetro no sea null.
        *Post: Modificará los materiales necesarios de un edificio.
        */
        void modificar_materiales_necesarios(Edificio* edificio);

        /*
        *Pre: Que los parámetros sean >= 0.
        *Post: Obtendrá true si hay energia suficiente para realizar la operación, false en caso contrario.
        */
        bool hay_energia_suficiente(int energia_necesaria, int energia_del_jugador);

        /*
        *Pre: Que el parametro sea >= 0.
        *Post: Modificará el valor de la energía del jugador.
        */
        void modificar_energia(Jugador* jugador_actual, int cantidad_a_modificar);

        /*
        *Pre: Que los parámetros sean >= 0.
        *Post: Obtendrá true si es posible comprar bombas, false en caso contrario.
        */
        bool es_posible_comprar_bombas(int cantidad_bombas, int cantidad_andycoins);

        /*
        *Post: Construirá un edificio.
        */
        void construir_edificio_auxiliar(Abb* edificios_disponibles, Mapa* mapa, Jugador* jugador_actual, std::string edificio_a_construir);

        /*
        *Pre: Que el parámetro no sea null.
        *Post: Obtendrá true si se alcanzo el maximo permitido, false en caso contrario.
        */
        bool se_alcanzo_maximo_permitido(Abb* edificios_disponibles, Edificio* edificio_a_construir, Jugador* jugador_actual);

        /*
        *Post: Modificará los materiales necesarios.
        */
        void modificar_materiales_necesarios(std::string edificio);

        /*
        *Pre: Que el parametro inventario y edificio no sean null.
        *Post: Obtendrá true si hay materiales suficientes, false en caso contrario.
        */
        bool hay_material_suficiente(std::string material, Inventario* inventario, int cantidad_material);

        /*
        *Pre: Que los parametros no sea null.
        *Pos: Actualizará el inventario del jugador.
        */
        void actualizar_inventario(Inventario* inventario, int piedra, int madera, int metal);

        /*
        *Post: Obtendrá true si se confirmo la construcción, false en caso contrario.
        */
        bool confirmar_construccion(std::string edificio_a_construir);

        /*
        *Pre: Que los parámetros fila y columna sean >= 0.
        *Post: Obtendrá un puntero de tipo Edificio, que contendra la información del edificio creado.
        */
        Edificio* crear_edificio(std::string nombre, int fila, int columna);

        /*
        *Pre: Que los parametros edificios_disponibles, mapa, jugador_actual sean != null, y que fila y columna sean >= 0.
        *Post: Demolerá un edificio de andypolis.
        */
        void demoler_edificio_auxiliar(Abb* edificios_disponibles, Mapa* mapa, Jugador* jugador_actual, int fila, int columna);

        /*
        *Pre: Que los parametros edificios_disponibles, mapa, jugador_actual sean != null, y que fila y columna sean >= 0.
        *Post: Reparará un edificio de andypolis
        */
        void reparar_edificio_auxiliar(Abb* edificios_disponibles, Mapa* mapa, Jugador* jugador_actual, int fila, int columna);

        /*
        *Pre: Que el parametro no sea null.
        *Post: Recolectará los recursos.
        */
        void recolectar_recursos_auxiliares(Jugador* jugador_actual);
        
};

#endif //_AUXILIARES_ANDYPOLIS_H_