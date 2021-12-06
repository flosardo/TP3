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

#include <algorithm>

class Auxiliares_andypolis {

    private:

        Abb* edificios_disponibles;
        Mapa* mapa;
        Jugador* jugador_1;
        Jugador* jugador_2;
        Jugador* jugador_actual;

    public:

        /*
        *Post: Construirá un objeto de tipo Auxiliares_andypolis con los valores por defecto.
        */
        Auxiliares_andypolis();

        /*
        *Pre: Que los punteros no sean null.
        *Post: Construirá un objeto de tipo Auxiliares_andypolis con los valores pasados por parámetros.
        */
        Auxiliares_andypolis(Abb* edificios_disponibles, Mapa* & mapa, Jugador* & jugador_actual, Jugador* & jugador_1, Jugador* & jugador_2);

        /*
        *Post: Seleccionará el jugador que va a ser el actual.
        */
        void seleccionar_jugador(std::string & nombre_1, std::string & nombre_2);

        /*
        *Post: Asignará el turno aleatoriamente, para el jugador que va a empezar.
        */
        void asignar_turno();

        /*
        *Post: Devolverá un puntero con las coordenadas pedidas.
        */
        int* pedir_coordenadas();

        /*
        *Pre: Que los parámetros sean >= 0.
        *Post: Devolverá true si las coordenadas son validas, false en caso contrario.
        */
        bool validar_coordenadas(int fila, int columna);

        /*
        *Pre: Que los parámetros sean >= 0.
        *Post: Devolvera true si el casillero es válido, false en caso contrario.
        */
        bool es_casillero_valido(int fila, int columna);

        /*
        *Post: Devolverá un string con el string del nombre del edificio pedido.
        */
        std::string pedir_nombre_edificio();

        /*
        *Post: Devolvera la nueva cantidad de material pedida.
        */
        int pedir_nueva_cantidad_material(std::string material);

        /*
        *Pre: Que el parámetro no sea null.
        *Post: Modificará los materiales necesarios de un edificio.
        */
        void modificar_materiales_necesarios(Edificio* edificio);

        /*
        *Pre: Que los parámetros sean >= 0.
        *Post: Devolvera true si hay energia suficiente para realizar la operación, false en caso contrario.
        */
        bool hay_energia_suficiente(int energia_necesaria, int energia_del_jugador);

        /*
        *Pre: Que el parametro sea >= 0.
        *Post: Modificará el valor de la energía del jugador.
        */
        void modificar_energia(int cantidad_a_modificar);

        /*
        *Pre: Que los parámetros sean >= 0.
        *Post: Devolverá true si es posible comprar bombas, false en caso contrario.
        */
        bool es_posible_comprar_bombas(int cantidad_bombas, int cantidad_andycoins);

        /*
        *Post: Construirá un edificio.
        */
        void construir_edificio_auxiliar(std::string edificio_a_construir);

        /*
        *Pre: Que el parámetro no sea null.
        *Post: Devolvera true si se alcanzo el maximo permitido, false en caso contrario.
        */
        bool se_alcanzo_maximo_permitido(Edificio* edificio_a_construir);

        /*
        *Post: Modificará los materiales necesarios.
        */
        void modificar_materiales_necesarios(std::string edificio);

        /*
        *Pre: Que el parametro inventario y edificio no sean null.
        *Post: Devolvera true si hay materiales suficientes, false en caso contrario.
        */
        bool hay_material_suficiente(std::string material, Inventario* inventario, Edificio* edificio);

        /*
        *Pre: Que los parametros no sea null.
        *Pos: Actualizará el inventario del jugador.
        */
        void actualizar_inventario(Inventario* inventario, Edificio* edificio);

        /*
        *Post: Devolverá true si se confirmo la construcción, false en caso contrario.
        */
        bool confirmar_construccion(std::string edificio_a_construir);

        /*
        *Pre: Que los parámetros fila y columna sean >= 0.
        *Post: Devolverá un puntero de tipo Edificio, que contendra la información del edificio creado.
        */
        Edificio* crear_edificio(std::string nombre, int fila, int columna);

};

#endif //_AUXILIARES_ANDYPOLIS_H_