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
        *Post: Devolvera la cantidad de materiales.
        */
        int obtener_cantidad_materiales();

        /*
        *Post: Devuelve un puntero al inventario.
        */
        Material** obtener_inventario();

        /*
        *Pre: Recibe el nombre del materia válido.
        *Post: Devuelve la posicion del material recibido
        */
        int obtener_indice_del_material(std::string material);

        /*
        *Pre: Que el puntero material no sea null.
        *Post: Agregará un material.
        */
        void agregar_material(Material* material);

        /*
        *Post: Mostrará el inventario.
        */
        void mostrar_inventario();
        
        /*
        *Pre: Que el indice sea > 0.
        *Post: Modificiará la cantidad del material.
        */
        void modificar_cantidad_material(int indice, int cantidad);

        /*
        *Post: Liberará la memoria utilizada a lo largo del programa por inventario.
        */
        ~Inventario();
        
};

#endif //_INVENTARIO_H_