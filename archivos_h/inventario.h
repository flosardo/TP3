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
        *Pre: Que el puntero material no sea null.
        *Post: Agregará un material.
        */
        void agregar_material(Material* material);

        /*
        *Post: Devuelve un puntero al inventario.
        */
        Material** obtener_inventario();

        /*
        *Post: Devolvera la cantidad de materiales.
        */
        int obtener_cantidad_materiales();

        /*
        *Pre:
        *Pos:
        */
        Material* obtener_material(std::string material_pedido);

        /*
        *Pre:
        *Pos:
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

        // /*
        // *Pre: Que el indice sea > 0.
        // *Post: Modificiará la cantidad del material.
        // */
        // void modificar_cantidad_material(int indice, int cantidad);

        // /*
        // *Pre: Recibe el nombre del materia válido.
        // *Post: Devuelve la posicion del material recibido
        // */
        // int obtener_indice_del_material(std::string material);

#endif //_INVENTARIO_H_