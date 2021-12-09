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
        std::string codigo_emoji;
        Edificio** edificios_construidos;
        int cantidad_construidos;
        std::string nombre;

    public:

        /*
        *Post: Construirá un objeto de tipo Jugador, con sus valores por defecto.
        */
        Jugador();

        /*
        *Pre: Que el parámetro no sea null.
        *Post: Cargara el edificio.
        */
        void cargar_edificio(Edificio* edificio);

        /*
        *Pre: Que los parámetros sea >= 0.
        *Post: Establecerá las coordenadas del jugador.
        */
        void establecer_coordenadas(int fila, int columna);

        /*
        *Post: Establecerá la convencion del jugador.
        */
        void establecer_convencion(char convencion);

        std::string obtener_nombre();

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Eliminará el edificio.
        */
        bool eliminar_edificio(int fila, int columna);

        /*
        *Post: Establecerá el nombre del jugador.
        */
        void establecer_nombre(std::string nombre);

        /*
        *Post: Establecera el código emoji del jugador.
        */
        void establecer_codigo_emoji(std::string codigo_emoji);

        /*
        *Post: obtendra la cantidad de construidos, del edificio pedido.
        */
        int obtener_cantidad_edificio(std::string nombre_edificio);

        /*
        *Post: Redimensionara el edificio.
        */
        void redimensionar_edificio(int nueva_longitud);


        int obtener_construidos();

        Edificio** obtener_edificios_construidos();

        /*
        *Post: obtendra el código emoji del jugador.
        */
        std::string obtener_codigo_emoji();

        /*
        *Pre: Que el material no sea null.
        *Post: Cargará un material.
        */
        void cargar_material(Material* material);

        /*
        *Post: obtendra las coordenadas del jugador.
        */
        int* obtener_coordenadas();

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

        /*
        *Post: Listará los construidos del jugador.
        */
        void listar_construidos();

        /*
        *Post: obtendra la energía actual del jugador actual.
        */
        int obtener_energia_actual();

        /*
        *Post: obtendra el puntero con el inventario del jugador.
        */
        Inventario* obtener_inventario();

        bool existe_el_edificio(int fila, int columna);

        /*
        *Post: Liberará la memoria usada durante la creacion del objeto Jugador.
        */
            ~Jugador();
        };

#endif //_JUGADOR_H_