#ifndef INVENTARIO_H
#define INVENTARIO_H
#include "constantes.h"
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
    int posicion_del_material(char material);

    // PRE:
    // POS: muestra el inventario
    void mostrar_inventario();

    // Destructor
    ~Inventario();
};

#endif