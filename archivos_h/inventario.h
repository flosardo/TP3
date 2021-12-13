#ifndef _INVENTARIO_H_
#define _INVENTARIO_H_
#include "materiales/material.h"

class Inventario {

    private:

        int cantidad_materiales;
        Material** inventario;

    public:

        /*
        *Post: Creará un objeto de tipo Inventario con sus valores por defecto.
        */
        Inventario();

        /*
        *Post: Devuelve un puntero al inventario.
        */
        Material** obtener_inventario();

        /*
        *Post: obtendra la cantidad de materiales.
        */
        int obtener_cantidad_materiales();

        /*
        *Post: obtendra un puntero del material pedido.
        */
        Material* obtener_material(std::string material_pedido);

        /*
        *Pre: Que el puntero material no sea null.
        *Post: Agregará un material.
        */
        void agregar_material(Material* material);

        /*
        *Pre: Que el parámetro cantidad sea >= 0.
        *Post: Modificará la cantidad del material pasado por parámetro.
        */
        void modificar_cantidad_material(std::string material_a_modificar, int cantidad);

        /*
        *Post: Mostrará el inventario.
        */
        void mostrar_inventario();

        /*
        *Post: Liberará la memoria utilizada a lo largo del programa por inventario.
        */
        ~Inventario();
        
};

#endif //_INVENTARIO_H_