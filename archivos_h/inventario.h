#ifndef INVENTARIO_H
#define INVENTARIO_H
#include "materiales/material.h"

class Inventario {

    private:

        int cantidad_materiales;
        Material** inventario;

    public:

        // Constructor
        Inventario();

        // PRE:
        // POS: devuelve la cantidad de materiales
        int obtener_cantidad_materiales();

        // PRE:
        // POS: devuelve un puntero al inventario
        Material** obtener_inventario();

        // PRE: recibe el nombre del material
        // POS: devuelve la posicion del material recibido
        int obtener_indice_del_material(char material);

        void agregar_material(Material* material);

        // PRE:
        // POS: muestra el inventario
        void mostrar_inventario();
        
        //PRE:
        //POST:
        void modificar_cantidad_material(unsigned int indice, int cantidad);

        // Destructor
        ~Inventario();
};

#endif // _INVENTARIO_H_