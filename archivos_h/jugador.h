#ifndef JUGADOR_H
#define JUGADOR_H
#include "constantes.h"
#include "inventario.h"

class Jugador {
    private:
        int energia;
        int coordenada_x;
        int coordenada_y;
        Inventario* inventario;

    public:
        Jugador();

        int* devolver_coordenadas();

        void mover(int coordenada_x, int coordenada_y);

        void modificar_energia(int cantidad_energia);

        void modificar_inventario(char material, int cantidad);
};

#endif