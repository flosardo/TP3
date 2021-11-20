#ifndef JUGADOR_H
#define JUGADOR_H
#include "constantes.h"
#include "inventario.h"
#include "materiales/energia.h"

class Jugador {

    private:
    
        Energia energia;
        unsigned int* coordenadas;
        Inventario* inventario;

    public:

        /*
        *Pre:
        *Post:
        */
        Jugador(unsigned int coordenada_x, unsigned int coordenada_y);

        /*
        *Pre:
        *Post:
        */
        void cargar_material(Material* material);

        /*
        *Pre:
        *Post:
        */
        unsigned int* devolver_coordenadas();

        /*
        *Pre:
        *Post:
        */
        void mover(unsigned int coordenada_x, unsigned int coordenada_y);

        /*
        *Pre:
        *Post:
        */
        void modificar_energia(int cantidad_energia);

        /*
        *Pre:
        *Post:
        */
        void modificar_inventario(char material, int cantidad);

};

#endif