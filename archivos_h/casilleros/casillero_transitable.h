#ifndef _CASILLERO_TRANSITABLE_H_
#define _CASILLERO_TRANSITABLE_H_

#include "casillero.h"

class Casillero_transitable: public Casillero {

    private:

        Jugador* jugador;
        Material* material;
    public:

        /*
        *Post: Creará un objeto de tipo Casillero_transitable, dejando sus atributos cargados con valores por defecto.
        */
        Casillero_transitable(std::string color, char tipo);

        /*
        *Post: obtendra el puntero de tipo jugador del jugador pedido, en caso contrario obtendra null.
        */
        Jugador* obtener_puntero_jugador();

        /*
        *Post: obtendra el puntero de tipo material que está en el atributo.
        */
        Material* obtener_puntero_material();

        /*
        *Pre: Que el parametro no sea null.
        *Post: Agregará un jugador al casillero transitable.
        */
        void agregar_jugador(Jugador* jugador);

        /*
        *Pre: Agregará un material al casillero.
        *Post: Que el parámetro material_a_agregar no sea null.
        */
        void agregar_material(Material* material_a_agregar);

        /*
        *Post: obtendra true si el casillero se encuentra ocupado con un material o jugador, o false en caso contrario.
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
        *Post: Liberará la memoria utilizada por el Casillero_transitable.
        */
        ~Casillero_transitable();
        
};

#endif // CASILLERO_TRANSITABLE_H