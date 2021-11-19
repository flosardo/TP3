#ifndef _CASILLERO_H_
#define _CASILLERO_H_

#include <iostream>

#include "../constantes.h"
#include "../construcciones/edificio.h"
#include "../materiales/material.h"

class Casillero{

    protected:

        char tipo_terreno;

    public:

        /*
        * Post: Creará un objeto de tipo Casillero, dejando sus atributos cargados con valores por defecto.
        */
        Casillero();

        /*
        * Post: Devolverá el tipo de terreno del casillero.
        */
        char obtener_tipo_de_terreno();

        /*
        * Post: Hace que las clases hijas muestren el casillero, según sea el comportamiento de cada hija.
        */
        virtual void mostrar() = 0;

        /*
        * Post: Hace que las clases hijas devuelvan el puntero a un edificio, según sea el comportamiento de cada hija.
        */
        virtual Edificio* obtener_puntero_edificio();

        /*
        * Post: Hace que las clases hijas devuelvan el puntero a un material, según sea el comportamiento de cada hija.
        */
        virtual Material* obtener_puntero_material();

        /*
        * Pre: Que el parámetro material_a_agregar no sea null.
        * Post: Hace que las clases hijas agreguen un material, según sea el comportamiento de cada hija.
        */
        virtual void agregar_material(Material* material_a_agregar);

        /*
        * Pre: Que el parametro edificio_a_agregar no sea null.
        * Post: Hace que las clases hijas agreguen un edificio, según sea el comportamiento de cada hija.
        */
        virtual void agregar_edificio(Edificio* edificio_a_agregar);

        /*
        * Post: Hace que las clases hijas limpien el casillero, según sea el comportamiento de cada hija.
        */
        virtual void limpiar_casillero();

        /*
        * Post: Hace que las clases hijas devuelvan el nombre del casillero, según sea el comportamiento de cada hija.
        */
        virtual char nombre_casillero();

        /*
        * Post: Hace que las clases hijas devuelvan la cantidad de material producido, según sea el comportamiento de cada hija.
        */
        virtual unsigned int cantidad_material_producido();

        /*
        * Post: Destruirá el casillero, liberando la memoria utilizada por el mismo.
        */
        virtual ~Casillero();

};

#endif // CASILLERO_H