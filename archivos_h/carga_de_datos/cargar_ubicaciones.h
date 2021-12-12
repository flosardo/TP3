#ifndef _CARGAR_UBICACIONES_H_
#define _CARGAR_UBICACIONES_H_

#include <fstream>
#include "../mapa.h"
#include "../materiales/piedra.h"
#include "../materiales/madera.h"
#include "../materiales/metal.h"
#include "../materiales/andycoins.h"
#include "../construcciones/aserradero.h"
#include "../construcciones/escuela.h"
#include "../construcciones/fabrica.h"
#include "../construcciones/mina.h"
#include "../construcciones/mina_oro.h"
#include "../construcciones/obelisco.h"
#include "../construcciones/planta_electrica.h"

class Cargar_ubicaciones {

    private:

        std::string archivo_ruta;

    public:
        
        /*
        *Post: Crea un objeto Cargar_ubicaciones con sus atributos por defecto.
        */
        Cargar_ubicaciones();

        /*
        *Pre: Que los parametros punteros no sean null.
        *Post: Cargará un edificio en un jugador 1 ó 2, según sea el caso.
        */
        void cargar_edificio_en_jugador(Edificio* edificio, Jugador* jugador_1, Jugador* jugador_2, std::string convencion);

        /*
        *Pre: Que los punteros no sean null.
        *Post: Cargará el mapa con las ubicaciones.
        */
        bool carga_ubicaciones(Mapa* mapa, Jugador* jugador_1, Jugador* jugador_2);

        /*
        *Pre: Que los parametros no sean null.
        *Post: Guardará las ubicaciones.
        */
        void guardar_ubicaciones(Mapa* mapa, Jugador* jugador_1, Jugador* jugador_2);

        /*
        *Pre: Que el archivo exista, y que el parametro jugador no sea null.
        *Post: Guardará a el jugador en el archivo.
        */
        void guardar_jugador(std::ofstream & archivo_ubicaciones, Jugador* jugador);

        /*
        *Pre: Que el archivo exista, y que el parametro mapa no sea null.
        *Post: Guardará la lluvia de materiales en el archivo.
        */
        void guardar_materiales_lluvia(std::ofstream & archivo_ubicaciones, Mapa* mapa);

        /*
        *Pre: Que los parametros fila y columna sean >= 0.
        *Post: obtendra un puntero de tipo Edificio, que contendra la información del edificio creado.
        */
        Edificio* crear_edificio(std::string nombre, int fila, int columna);

        /*
        *Pre: Que el nombre venga con un nombre de material existente.
        *Post: obtendra un puntero de tipo Material, que contendra la información del material creado.
        */
        Material* crear_material(std::string nombre);

    private:

        /*
        *Pre: Que el archivo exista, que los punteros no sean null.
        *Post: Procesará el archivo de ubicaciones.
        */
        void procesar_archivo(std::ifstream & archivo_ubicaciones, Mapa* mapa, Jugador* jugador_1, Jugador* jugador_2, std::string nombre, std::string & convencion_jugador);
        
};

#endif //_CARGAR_UBICACIONES_H_