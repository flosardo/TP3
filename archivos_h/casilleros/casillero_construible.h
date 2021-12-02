#ifndef _CASILLERO_CONSTRUIBLE_H_
#define _CASILLERO_CONSTRUIBLE_H_

#include "casillero.h"

class Casillero_construible: public Casillero{

    private:

        Edificio* edificio;
        Jugador* jugador;

    public: 

        /*
        *Post: Creará un objeto de tipo Casillero_construible dejandola con los atributos cargados con valores por defecto.
        */
        Casillero_construible();

        /*
        *Post: Que el parámetro edificio no sea null.
        *Pre: Creará un objeto de tipo Casillero_construible usando el parametro edificio.
        */
        Casillero_construible(Edificio* edificio);

        /*
        *Post: Mostrará lo que hay en el casillero.
        */
        void mostrar();

        /*
        *Pre: Que el parámetro edificio_a_agregar no sea null.
        *Post: Agregará un edificio al casillero.
        */
        void agregar_edificio(Edificio* edificio_a_agregar);

        /*
        *Post: Devolverá el puntero de tipo edificio que esta en el atributo.
        */
        Edificio* obtener_edificio();

        /*
        *Post: Devolverá true si el casillero se encuentra ocupado con un edificio, o false en caso contrario.
        */
        bool esta_ocupado();

        /*
        *Post: Limpiará el contenido que hay en el casillero.
        */
        void limpiar_casillero();

        /*
        *Pre:
        *Post:
        */
        void agregar_jugador(Jugador* jugador);

        /*
        *Post: Devolverá la cantidad material producido.
        */
        int cantidad_material_producido();

};

#endif //_CASILLERO_CONSTRUIBLE_H_