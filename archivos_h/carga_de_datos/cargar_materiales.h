#ifndef _CARGAR_MATERIALES_H_
#define _CARGAR_MATERIALES_H_

#include <fstream>
#include "../jugador.h"
#include "../materiales/andycoins.h"
#include "../materiales/piedra.h"
#include "../materiales/madera.h"
#include "../materiales/metal.h"
#include "../materiales/bomba.h"

class Cargar_materiales {
    
    private:

        std::string archivo_ruta;

    public:

        /*
        *Post: Crea un objeto de tipo cargar_materiales con sus valores por defecto.
        */
        Cargar_materiales();

        /*
        *Pre: Que jugador_1 y jugador_2 no sean nulos.
        *Post: Cargara los materiales para los jugadores 1 y 2.
        */
        void carga_materiales(Jugador* jugador_1, Jugador* jugador_2);

        /*
        *Pre: Que jugador_1 y jugador_2 no sean nulos.
        *Post: Guardará los materiales de los jugadores 1 y 2.
        */
        void guardar_materiales(Jugador* jugador_1, Jugador* jugador_2);

    private:

        /*
        *Pre: Que el parámetro jugador no sea nulo, sumado a eso que la cantidad del material sea >= 0, y que reciba el tipo de material.
        *Post: Procesa el archivo.
        */
        void procesar_archivo(std::string tipo_material, int cantidad_material, Jugador* jugador);
        
};

#endif //_CARGAR_MATERIALES_H_