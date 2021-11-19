#ifndef _MAPA_H
#define _MAPA_H
#include "constantes.h"
#include "casilleros/casillero_construible.h"
#include "casilleros/casillero_transitable.h"
#include "casilleros/casillero_inaccesible.h"

class Mapa {
    private:
        int cantidad_filas;
        int cantidad_columnas;
        Casillero*** mapa;

    public:
        // Constructor
        Mapa(int filas, int columnas);

        // PRE:
        // POS: crea el mapa
        void crear_mapa();
        
        // PRE: recibe dos coordenadas
        // POS: devuleve verdadero si el casillero en las corodenadas recibidas esta ocupado, falso de lo contrario
        bool esta_ocupado(int coord_x, int coord_y);

        void agregar_material_casillero(Material* material, int fila, int columna);

        void agregar_edificio_casillero(Edificio* edificio, int fila, int columna);

        // PRE: recibe dos coordenadas
        // POS: libera el casillero en las coordenadas recibidas
        void liberar_posicion(int coordenada_x, int coordenada_y);

        // PRE: recibe dos coordenadas
        // POS: devuleve verdadero en caso que se pueda construir en las coordenadas recibidas, falso de lo contrario
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

        // Destructor
        ~Mapa();
};

#endif