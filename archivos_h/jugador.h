#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "inventario.h"
#include "materiales/energia.h"

class Jugador{

    private:

        Energia energia;
        int* coordenadas;
        Inventario* inventario;

    public:

        /*
        *Pre: Que las coordenadas recibidas por parametro sean >= 0.
        *Post: Creará un objeto de tipo Jugador con las coordenadas recibidad por parametro.
        */
        Jugador(int coordenada_x, int coordenada_y);

        /*
        *Pre: Que el material no sea null.
        *Post: Cargará un material.
        */
        void cargar_material(Material* material);

        /*
        *Post: Devolvera las coordenadas del jugador.
        */
        int* devolver_coordenadas();

        /*
        *Pre: Que las coordenadas recibidas por parametro sean >= 0.
        *Post: Mueve el jugador a las coordenadas x e y usando los caminos minimos.
        */
        void mover(int coordenada_x, int coordenada_y);

        /*
        *Pre: Que la cantidad de energia sea >= 0.
        *Post: Modificará la cantidad de energía de un jugador.
        */
        void modificar_energia(int cantidad_energia);

        /*
        *Pre: Que la cantidad sea >= 0, y el material sea un materia válido que pertenezca al juego.
        *Post: Modificará el inventario.
        */
        void modificar_inventario(char material, int cantidad);

        /*
        *Post: Liberará la memoria usada durante la creacion del objeto Jugador.
        */
        ~Jugador();

};

#endif //_JUGADOR_H_