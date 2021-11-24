#ifndef _CARGAR_MATERIALES_H_
#define _CARGAR_MATERIALES_H_
#include <fstream>
#include "../andypolis.h"

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

    private:

        /*
        *Pre: Que los parametros jugador_1 y jugador_2 no sean nulos, sumado a eso que las cantidades sean >= 0, y que reciba un nombre.
        *Post: Procesa el archivo.
        */
        void procesar_archivo(std::string nombre, int cantidad_jugador_1, int cantidad_jugador_2, Jugador* jugador_1, Jugador* jugador_2);
        
};

#endif // _CARGAR_MATERIALES_H_