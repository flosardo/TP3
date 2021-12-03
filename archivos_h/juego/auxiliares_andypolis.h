#ifndef _AUXILIARES_ANDYPOLIS_H_
#define _AUXILIARES_ANDYPOLIS_H_
#include "../../archivos_h/arbol/abb.h"
#include "../../archivos_h/mapa.h"
#include <iostream>

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
        bool es_edificio_valido(std::string edificio);

        /*
        *Pre:
        *Post:
        */
        bool validar_coordenadas(int fila, int columna);

        /*
        *Pre:
        *Post:
        */
        bool es_posible_comprar_bombas(int & cantidad_bombas, int cantidad_andycoins);

        /*
        *Pre:
        *Post:
        */
        bool es_casillero_valido(int fila, int columna);

        /*
        *Pre:
        *Post:
        */
        bool hay_energia_suficiente(int energia_necesaria, int energia_del_jugador);

        /*
        *Pre:
        *Post:
        */
        int* pedir_coordenadas();

        /*
        *Pre:
        *Post:
        */
        void modificar_materiales_necesarios(Edificio* edificio);

        /*
        *Pre:
        *Post:
        */
        void seleccionar_jugador(std::string & nombre_1, std::string & nombre_2);

        /*
        *Pre:
        *Post:
        */
        int pedir_nueva_cantidad_material(std::string material);

        /*
        *Pre:
        *Post:
        */
        void modificar_materiales_necesarios(std::string edificio);

        /*
        *Pre: 
        *Post:
        */
        std::string pedir_nombre_edificio();
        

        /*
        *Pre: 
        *Post:
        */
        void asignar_turno(Jugador* & jugador_actual, Jugador* jugador_1, Jugador* jugador_2);
        
        /*
        *Pre: 
        *Post:
        */
        void modificar_energia(Jugador* jugador_actual, int cantidad_a_modificar);

        /*
        *Pre: 
        *Post:
        */
        void validar_construccion(Jugador* jugador_actual, std::string edificio_a_construir);
        
        /*
        *Pre: 
        *Post:
        */
        bool hay_materiales_suficientes(Jugador* jugador_actual, std::string edificio_a_construir);
        
        /*
        *Pre: 
        *Post:
        */
        bool se_alcanzo_maximo_permitido(Abb* arbol, Jugador* jugador, std::string edificio_a_construir);
        
        /*
        *Pre: 
        *Post:
        */
        bool confirmar_construccion(std::string edificio_a_construir);
    
        
};


#endif //_AUXILIARES_ANDYPOLIS_H_