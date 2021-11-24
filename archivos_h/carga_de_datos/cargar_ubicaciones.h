#ifndef _CARGAR_UBICACIONES_H_
#define _CARGAR_UBICACIONES_H_

#include <fstream>
#include "../andypolis.h"

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
        
};

#endif //_CARGAR_UBICACIONES_H_