#ifndef _MAPA_H_ //_MAPA_H_
#define _MAPA_H_ //_MAPA_H_

#include "casilleros/casillero_construible.h"
#include "casilleros/casillero_transitable.h"
#include "casilleros/casillero_inaccesible.h"
#include "jugador.h"
#include <iomanip>
#include <cstdlib>

class Mapa {

    private:

        Casillero*** mapa;
        int* dimensiones;

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
        *Pre: Que fil y col sean >= 0.
        *Post: Llenará los casilleros del mapa dependiendo del tipo de terreno que sea (Lago, Terreno, Camino).
        */
        void inicializar_casillero(char terreno, int fil, int col);

        /*
        *Post: Devolverá un puntero con las dimensiones del mapa.
        */
        int* obtener_dimensiones();

        /*
        *Pre: Que material no sea null, fila >= 0, columna >= 0.
        *Post: Agregará un material al casillero.
        */
        bool se_ubico_material(Material* material, int fila, int columna);

        /*
        *Pre:  Que edificio no sea null, fila >= 0, columna >= 0
        *Post: Agregará un edificio al casillero.
        */
        bool se_ubico_edificio(Edificio* edificio, int fila, int columna);

        /*
        *Pre: Que jugador no sea null y que las coordenadas sean.
        *Post: Posicionará al jugador en el mapa.
        */
        bool se_ubico_jugador(Jugador* jugador, int fila, int columna);

        /*
        *Pre: Que columna y fila sean >= 0.
        *Post: Devuelve el tipo del casillero en las coordenadas recibidas.
        */
        char obtener_tipo_casillero(int fila, int columna);

        /*
        *Pre: Recibe dos coordenadas que deben ser >= 0.
        *Post: Muestra el saludo del objeto que se encuentra en las coordenadas recibidas (en caso de existir un objeto en dichas coordenadas).
        */
        void consultar_coordenada(int fila, int columna);
        
        /*
        *Pre: Recibe dos coordenadas.
        *Post: Devuleve true si el casillero en las coordenadas recibidas esta ocupado, falso en caso contrario.
        */
        bool esta_ocupado(int fila, int columna);

        /*
        *Pre: Recibe dos coordenadas que deben ser >= 0.
        *Post: Devuelve true en caso que las coordenadas recibidas esten fuera de rango, falso en caso contrario
        */
        bool coordenadas_fuera_de_rango(int fila, int columna);

        /*
        *Pre: Recibe la cantidad de material a insertar.
        *Post: Devuelve true si la cantidad de casilleros transitbales es >= a la cantidad recibida, false en caso contrario.
        */
        bool es_posible_insertar_materiales(int cantidad_a_insertar);

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Devolverá un edificio.
        */
        Edificio* obtener_edificio(int fila, int columna);

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Devolverá un material.
        */
        Material* obtener_material(int fila, int columna);

        /*
        *Pre: que fila y columna sean validos
        *Pos: devuelve un puntero al jugador en las coordenadas recibidas
        */
        Jugador* obtener_jugador(int fila, int columna);

        /*
        *Post: Devuelve un puntero a las coordenadas generadas para insertar material.
        */
        int* generar_coordenadas_validas();

        /*
        *Pre: Recibe dos coordenadas que deben ser >= 0.
        *Post: Libera el casillero en las coordenas recibidas.
        */
        void liberar_posicion(int fila, int columna);

        /*
        *Post: Mostrará el mapa.
        */
        void mostrar_mapa();


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

        /*
        *Post: Mostrá el inventario del mapa.
        */
        void mostrar_simbologia();

};

#endif //_MAPA_H_