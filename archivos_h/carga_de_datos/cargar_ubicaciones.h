#ifndef _CARGAR_UBICACIONES_H_
#define _CARGAR_UBICACIONES_H_
#include <fstream>
#include "../mapa.h"
#include "../materiales/piedra.h"
#include "../materiales/madera.h"
#include "../materiales/metal.h"
#include "../materiales/energia.h"
#include "../materiales/bomba.h"
#include "../materiales/andycoins.h"
#include "../construcciones/aserradero.h"
#include "../construcciones/escuela.h"
#include "../construcciones/fabrica.h"
#include "../construcciones/mina.h"
#include "../construcciones/mina_oro.h"
#include "../construcciones/obelisco.h"
#include "../construcciones/planta_electrica.h"

class Cargar_ubicaciones{

    private:

        std::string archivo_ruta;

    public:
        
        /*
        *Post: Crea un objeto Cargar_ubicaciones con sus atributos por defecto.
        */
        Cargar_ubicaciones();

        /*
        *Pre: Que el puntero andypolis no sea null.
        *Post: Cargará el mapa con las ubicaciones.
        */
        bool carga_ubicaciones(Mapa* mapa);

        /*
        *Post: Guardará las ubicaciones.
        */
        void guardar_ubicaciones();

        /*
        *Pre: Que el nombre venga con un nombre de edificio existente, y que el carácter del jugador pertenezca a un carácter valido.
        *Post: Devolverá un puntero de tipo Edificio, que contendra la información del edificio creado.
        */
        Edificio* crear_edificio(std::string nombre, char jugador);

        /*
        *Pre: Que el nombre venga con un nombre de material existente.
        *Post: Devolverá un puntero de tipo Material, que contendra la información del material creado.
        */
        Material* crear_material(std::string nombre);

    private:

        /*
        *Pre: Que el archivo exista, que el mapa no sea null, y que reciba un nombre válido.
        *Post: Procesará el archivo de ubicaciones.
        */
        void procesar_archivo(std::ifstream & archivo_ubicaciones, Mapa* mapa, std::string nombre);
        
};

#endif //_CARGAR_UBICACIONES_H_