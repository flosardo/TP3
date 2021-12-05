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

    public:

        /*
        *Pre:
        *Post:
        */
        Auxiliares_andypolis();

        /*
        *Pre:
        *Post:
        */
        Auxiliares_andypolis(Abb* edificios_disponibles, Mapa* mapa);

        /*
        *Pre:
        *Post:
        */
        void seleccionar_jugador(std::string & nombre_1, std::string & nombre_2);

        /*
        *Pre: 
        *Post:
        */
        void asignar_turno(Jugador* & jugador_actual, Jugador* jugador_1, Jugador* jugador_2);

        /*
        *Pre:
        *Post:
        */
        int* pedir_coordenadas();

        /*
        *Pre:
        *Post:
        */
        bool validar_coordenadas(int fila, int columna);

        /*
        *Pre:
        *Post:
        */
        bool es_casillero_valido(int fila, int columna);

        /*
        *Pre: 
        *Post:
        */
        std::string pedir_nombre_edificio();

        /*
        *Pre:
        *Post:
        */
        int pedir_nueva_cantidad_material(std::string material);

        /*
        *Pre:
        *Post:
        */
        void modificar_materiales_necesarios(Edificio* edificio);

        /*
        *Pre:
        *Post:
        */
        bool hay_energia_suficiente(int energia_necesaria, int energia_del_jugador);

        /*
        *Pre: 
        *Post:
        */
        void modificar_energia(Jugador* jugador_actual, int cantidad_a_modificar);

        /*
        *Pre:
        *Post:
        */
        bool es_posible_comprar_bombas(int cantidad_bombas, int cantidad_andycoins);

        /*
        *Pre: 
        *Post:
        */
        void validar_construccion(Jugador* jugador_actual, std::string edificio_a_construir);

        /*
        *Pre: 
        *Post:
        */
        bool se_alcanzo_maximo_permitido(Jugador* jugador, Edificio* edificio_a_construir);

        /*
        *Pre:
        *Post:
        */
        void modificar_materiales_necesarios(std::string edificio);

        /*
        *Pre: 
        *Post:
        */
        bool hay_material_suficiente(std::string material, Inventario* inventario, Edificio* edificio);

        /*
        *Pre:
        *Pos:
        */
       void actualizar_inventario(Inventario* inventario, Edificio* edificio);

        /*
        *Pre: 
        *Post:
        */
        bool confirmar_construccion(std::string edificio_a_construir);

        /*
        *Post: Devolverá un puntero de tipo Edificio, que contendra la información del edificio creado.
        */
        Edificio* crear_edificio(std::string nombre, int fila, int columna);
};


#endif //_AUXILIARES_ANDYPOLIS_H_