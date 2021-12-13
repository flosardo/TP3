#ifndef _CASILLERO_CONSTRUIBLE_H_
#define _CASILLERO_CONSTRUIBLE_H_

#include "casillero.h"

class Casillero_construible: public Casillero {

    private:

        Jugador* jugador;
        Edificio* edificio;

    public: 

        /*
        *Post: Creará un objeto de tipo Casillero_construible dejandola con los atributos cargados con valores por defecto.
        */
        Casillero_construible();

        /*
        *Post: Obtendrá null si no hay puntero jugador, en caso contrario Obtendrá el puntero de tipo Jugador, con el jugador pedido.
        */
        Jugador* obtener_puntero_jugador();

        /*
        *Post: Obtendrá el puntero de tipo edificio que esta en el atributo.
        */
        Edificio* obtener_puntero_edificio();

        /*
        *Pre: Que el parametro jugador no sea null.
        *Post: Agregará un jugador al casillero construible.
        */
        void agregar_jugador(Jugador* jugador);

        /*
        *Pre: Que el parámetro edificio_a_agregar no sea null.
        *Post: Agregará un edificio al casillero.
        */
        void agregar_edificio(Edificio* edificio_a_agregar);

        /*
        *Post: Obtendrá true si el casillero se encuentra ocupado con un edificio, o false en caso contrario.
        */
        bool esta_ocupado();

        /*
        *Post: Limpiará el contenido que hay en el casillero.
        */
        void limpiar_casillero();

        /*
        *Post: Mostrará lo que hay en el casillero.
        */
        void mostrar();

        /*
        *Post: Liberara la memoria usada por el Casillero_construible.
        */
        ~Casillero_construible();

};

#endif //_CASILLERO_CONSTRUIBLE_H_