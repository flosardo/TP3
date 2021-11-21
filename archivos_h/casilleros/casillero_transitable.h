#ifndef _CASILLERO_TRANSITABLE_H_
#define _CASILLERO_TRANSITABLE_H_

#include "casillero.h"

class Casillero_transitable: public Casillero{

    private:

        Material* material;

    public:

        /*
        * Post: Creará un objeto de tipo Casillero_transitable, dejando sus atributos cargados con valores por defecto.
        */
        Casillero_transitable();

        /*
        * Pre: Que el parámetro material no sea null.
        * Post: Creará un objeto de tipo Casillero_transitable con el parámetro material.
        */
        Casillero_transitable(Material* material);

        /*
        * Post: Mostrará lo que hay en el casillero.
        */
        void mostrar();

        /*
        * Post: Devolvera el puntero de tipo material que está en el atributo.
        */
        Material* obtener_material();

        /*
        * FALTA PONER CONDICIONES
        */
        bool esta_ocupado();

        /*
        * Pre: Agregará un material al casillero.
        * Post: Que el parámetro material_a_agregar no sea null.
        */
        void agregar_material(Material* material_a_agregar);
        
        /*
        * Post: Limpiará el contenido que hay en el casillero.
        */
        void limpiar_casillero();

        /*
        * Post: Devolvera el nombre del casillero.
        */
        char nombre_casillero();

        /*
        * Post: Destruirá el Casillero, liberando la memoria utilizada por el mismo.
        */
        ~Casillero_transitable();
        
};

#endif // CASILLERO_TRANSITABLE_H