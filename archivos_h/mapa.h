#ifndef _MAPA_H_ //_MAPA_H_
#define _MAPA_H_ //_MAPA_H_

#include "casilleros/casillero_construible.h"
#include "casilleros/casillero_transitable.h"
#include "casilleros/casillero_inaccesible.h"
#include "jugador.h"

#include <cstdlib>

class Mapa{

    private:

        int cantidad_filas;
        int cantidad_columnas;
        Casillero*** mapa;

    public:

        /*
        *Post: Creara un mapa con sus valores por defecto.
        */
        Mapa();

        /*
        *Pre: Que cantidad_filas y cantidad_columnas sean positivos.
        *Post: Creará el mapa con la cantidad_filas y cantidad_columnas recibidas por parámetro.
        */
        void crear_mapa(int cantidad_filas, int cantidad_columnas);
        
        /*
        *Pre: Recibe dos coordenadas
        *Post: Devuleve true si el casillero en las coordenadas recibidas esta ocupado, falso en caso contrario.
        */
        bool esta_ocupado(int coord_x, int coord_y);

        /*
        *Pre: Que jugador no sea null y que las coordenadas sean .
        *Post: Posicionará al jugador en el mapa.
        */
        void posicionar_jugador(Jugador* jugador, int fila, int columna);

        /*
        *Pre: Que material no sea null, fila >= 0, columna >= 0.
        *Post: Agregará un material al casillero.
        */
        void agregar_material_casillero(Material* material, int fila, int columna);

        /*
        *Pre:  Que edificio no sea null, fila >= 0, columna >= 0
        *Post: Agregará un edificio al casillero.
        */
        void agregar_edificio_casillero(Edificio* edificio, int fila, int columna);


        /*
        *Pre: Recibe dos coordenadas que deben ser >= 0.
        *Post: Libera el casillero en las coordenas recibidas.
        */
        void liberar_posicion(int coordenada_x, int coordenada_y);

        /*
        *Pre: Recibe dos coordenadas que deben ser >= 0.
        *Post: Devuelve true en caso que se pueda construir en las coordenadas recibidas, falso en caso contrario.
        */
        bool se_puede_construir(int coord_x, int coord_y);

        /*
        *Pre: Recibe dos coordenadas que deben ser >= 0.
        *Post: Devuelve true en caso que las coordenadas recibidas esten fuera de rango, falso en caso contrario
        */
        bool coordenadas_fuera_de_rango(int coord_x, int coord_y);

        /*
        *Pre: Recibe dos coordenadas que deben ser >= 0.
        *Post: Muestra el saludo del objeto que se encuentra en las coordenadas recibidas (en caso de existir un objeto en dichas coordenadas).
        */
        void consultar_coordenada(int coord_x, int coord_y);

        /*
        *Pre: Recibe la cantidad de material a insertar.
        *Post: Devuelve true si la cantidad de casilleros transitbales es >= a la cantidad recibida, false en caso contrario.
        */
        bool es_posible_insertar_materiales(int cantidad_a_insertar);

        /*
        *Post: Devuelve un puntero a las coordenadas generadas para insertar material.
        */
        int* generar_coordenadas_validas();

        /*
        *Pre: Recibe dos coordenadas.
        *Post: Devuelve un puntero a edificio, que se encuentra en las coordenadas recibidas.
        */
        Edificio* obtener_elemento(int coord_x , int coord_y);

        /*
        *Post: Mostrará el mapa.
        */
        void mostrar_mapa();

        /*
        *Pre: Que coordenada_x y coordenada_y sean >= 0
        *Post: Devuelve el tipo del casillero en las coordenadas recibidas.
        */
        char obtener_casillero(int coordenada_x, int coordenada_y);

        /*
        * PRE: Que fil y col sean >= 0.
        * POST: Llenará los casilleros del mapa dependiendo del tipo de terreno que sea (Lago, Terreno, Camino).
        */
        void llenar_casillero(char terreno, int fil, int col);

        //Pos: devuelve un puntero al arreglo que contiene las dimensiones del mapa
        
        int* obtener_dimensiones();

        /*
        *Post: Liberará la memoria utilizada por el mapa a lo largo del programa.
        */
        ~Mapa();

    private:
        
        /*
        *Pre: Que el mapa este creado.
        *Post: Inicializará el mapa, dejando en 0 (null) sus casilleros.
        */
        void inicializar_mapa();

};

#endif //_MAPA_H_