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
        int andycoins_juntados;
        int bombas_usadas;
        int bombas_compradas;

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
        *Post: Obtendra los andycoins juntados.
        */
        int obtener_andycoins_juntados();

        /*
        *Post: Obtendra las bombas usadas.
        */
        int obtener_bombas_usadas();

        /*
        *Post: Obtendra la cantidad de bombas compradas.
        */
        int obtener_cantidad_bombas_compradas();

        /*
        *Post: Aumentará la cantidad de bombas usadas.
        */
        void aumentar_bombas_usadas();  

        /*
        *Pre: Que los parámetros sea >= 0.
        *Post: Establecerá las coordenadas del jugador.
        */
        void establecer_coordenadas(int fila, int columna);

        /*
        *Post: Establecerá la convencion del jugador.
        */
        void establecer_convencion(char convencion);

        /*
        *Post: Obtendrá el nombre del jugador.
        */
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
        *Post: Obtendrá la cantidad de construidos, del edificio pedido.
        */
        int obtener_cantidad_edificio(std::string nombre_edificio);

        /*
        *Post: Redimensionara el edificio.
        */
        void redimensionar_edificio(int nueva_longitud);

        /*
        *Post: Obtendrá la cantidad de construidos, del edificio pedido.
        */
        int obtener_construidos();

        /*
        *Post: Obtendrá los edificios construidos.
        */
        Edificio** obtener_edificios_construidos();

        /*
        *Post: Obtendrá el código emoji del jugador.
        */
        std::string obtener_codigo_emoji();

        /*
        *Pre: Que el material no sea null.
        *Post: Cargará un material.
        */
        void cargar_material(Material* material);

        /*
        *Post: Obtendrá las coordenadas del jugador.
        */
        int* obtener_coordenadas();

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
        *Post: Obtendrá la energía actual del jugador actual.
        */
        int obtener_energia_actual();

        /*
        *Post: Obtendrá el puntero con el inventario del jugador.
        */
        Inventario* obtener_inventario();

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Devolvera true si existe el edificio, false en caso contrario.
        */
        bool existe_el_edificio(int fila, int columna);

        /*
        *Post: Liberará la memoria usada durante la creacion del objeto Jugador.
        */
        ~Jugador();

};

#endif //_JUGADOR_H_