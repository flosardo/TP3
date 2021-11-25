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

class Cargar_ubicaciones {

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
        *Pre:
        *Post:
        */
        void guardar_ubicaciones();

        /*
        *Pre:
        *Pos:
        */
        Edificio* crear_edificio(std::string nombre, char jugador);

        /*
        *Pre:
        *Pos:
        */
        Material* crear_material(std::string nombre);

    private:

        /*
        *Pre:
        *Pos:
        */
        void procesar_archivo(std::ifstream & archivo_ubicaciones, Mapa* mapa, std::string nombre);
        
};

#endif //_CARGAR_UBICACIONES_H_