#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "inventario.h"
#include "materiales/energia.h"
#include "construcciones/edificio.h"

class Jugador {

    private:

        Energia energia;
        int* coordenadas;
        Inventario* inventario;
        char convencion_jugador;
        Edificio** edificios_construidos;
        int cantidad_construidos;
        std::string nombre;

    public:


        Jugador();

        /*
        *Pre: Que el parámetro no sea null.
        *Post: Cargara el edificio.
        */
        void cargar_edificio(Edificio* edificio);

        /*
        *Pre:
        *Post:
        */
        void establecer_coordenadas(int fila, int columna);

        /*
        *Pre:
        *Post:
        */
        void establecer_convencion(char convencion);

        /*
        *Post: Eliminará el edificio.
        */
        void eliminar_edificio(int fila, int columna);

        /*
        *Post:
        */
        void establecer_nombre(std::string nombre);

        /*
        *Post: Establecera el nombre del jugador.
        */
        void establecer_convencion_jugador(char nombre);

        /*
        *Post:
        */
        int obtener_cantidad_construidos(std::string nombre_edificio);

        /*
        *Post: Redimensionara el edificio.
        */
        void redimensionar_edificio(int nueva_longitud);


        /*
        *Post: Devolvera el nombre del jugador.
        */
        char obtener_nombre();

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
        void mover(int fila, int columna);

        /*
        *Pre: Que la cantidad de energia sea >= 0.
        *Post: Modificará la cantidad de energía de un jugador.
        */
        void modificar_energia(int cantidad_energia);

        /*
        *Pre: Que la cantidad sea >= 0, y el material sea un materia válido que pertenezca al juego.
        *Post: Modificará el inventario.
        */
        void modificar_inventario(std::string material, int cantidad);

        void listar_construidos();

        int obtener_energia_actual();

        Inventario* obtener_inventario();

        /*
        *Post: Liberará la memoria usada durante la creacion del objeto Jugador.
        */
        ~Jugador();

};

#endif //_JUGADOR_H_