#ifndef _MAPA_H_ //_MAPA_H_
#define _MAPA_H_ //_MAPA_H_

#include "casilleros/casillero_construible.h"
#include "casilleros/casillero_transitable.h"
#include "casilleros/casillero_inaccesible.h"
#include "jugador.h"

#include <cstdlib>

class Mapa {

    private:

        int cantidad_filas;
        int cantidad_columnas;
        Casillero*** mapa;

    public:

        // Constructor
        Mapa();

        /*
        *Pre:
        *Post: 
        */

        /*
        *Pre: Recibe dos coordenadas
        *Post: Devuleve verdadero si el casillero en las corodenadas recibidas esta ocupado, falso de lo contrario.
        */

        /*
        *Pre: Que cantidad_filas y cantidad_columnas sean positivos.
        *Post: Creará el mapa con la cantidad_filas y cantidad_columnas recibidas por parámetro.
        */
        void crear_mapa(int cantidad_filas, int cantidad_columnas);
        
        /*
        *Pre: Recibe dos coordenadas
        *Post: Devuleve verdadero si el casillero en las corodenadas recibidas esta ocupado, falso de lo contrario.
        */
        bool esta_ocupado(int coord_x, int coord_y);

        /*
        *Pre: Que jugador no sea null.
        *Post: Posicionará al jugador en el mapa.
        */
        void posicionar_jugador(Jugador* jugador);

        /*
        *Pre:
        *Post: 
        */
        void agregar_material_casillero(Material* material, int fila, int columna);

        /*
        *Pre: 
        *Post: 
        */
        void agregar_edificio_casillero(Edificio* edificio, int fila, int columna);


        /*
        *Pre: Recibe dos coordenadas 
        *Post: Libera el casillero en las coordenas recibidas
        */
        void liberar_posicion(int coordenada_x, int coordenada_y);

        /*
        *Pre: Recibe dos coordenadas
        *Post: Devuelve verdadero en caso que se pueda construir en las coordenadas recibidas, falso de lo contrario
        */
        bool se_puede_construir(int coord_x, int coord_y);

        // PRE: recibe dos coordenadas
        // POS: devuelve verdadero en caso que las coordenadas recibidas esten fuera de rango, falso de lo contrario
        bool coordenadas_fuera_de_rango(int coord_x, int coord_y);

        // PRE: recibe dos coordenadas
        // POS: muestra el saludo del objeto que se encuntra en las coordenadas recibidas, si no hay nada le avisa al ususario
        void consultar_coordenada(int coord_x, int coord_y);

        // PRE: recibe la cantidad de material a insertar
        // POS: devuelve verdadero si la cantidad de casilleros transitbales es >= a la cantidad recibida
        bool es_posible_insertar_materiales(int cantidad_a_insertar);

        // PRE:
        // POS: devuelve un puntero a las coordenadas generadas para insertar material
        int* generar_coordenadas_validas();

        // PRE: recibe dos coordenadas
        // POS: devuleve un puntero a edificio en las coordenadas recibidas
        Edificio* obtener_elemento(int coord_x , int coord_y);

        // PRE:
        // POS: muestra el mapa por pantalla
        void mostrar_mapa();

        // PRE: recibe dos coordenadas
        // POS: devuelve el tipo del casillero en las coordenadas recibidas
        char obtener_casillero(int coordenada_x, int coordenada_y);

        /*
        * PRE: Que fil y col sean mayores a 0.
        * POST: Llenará los casilleros del mapa dependiendo del tipo de terreno que sea (Lago, Terreno, Camino).
        */
        void llenar_casillero(char terreno, int fil, int col);

        // Destructor
        ~Mapa();

    private:

        
        // PRE: Que el mapa este creado.
        // POS: Inicializa el mapa, dejando en 0 (null) sus casilleros.
        void inicializar_mapa();
};

#endif //_MAPA_H_