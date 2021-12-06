#ifndef _CARGAR_MAPA_H_
#define _CARGAR_MAPA_H_

#include <fstream>
#include "../mapa.h"

class Cargar_mapa {
    
    private:

        std::string archivo_ruta;

    public:

        /*
        *Post: Creara un objeto de tipo Cargar_mapa, con sus valores por defecto.
        */
        Cargar_mapa();

        /*
        *Pre: Que mapa no sea null.
        *Post: Cargará el mapa de andypolis.
        */
        void carga_mapa(Mapa* mapa);

    private: 

        /*
        *Pre: Que el archivo exista, que mapa no sea null, que cantidad_filas y cantidad_columnas sean >= 0.
        *Post: Procesará el archivo.
        */
        void procesar_archivo(std::ifstream & archivo_mapa, Mapa* mapa, int cantidad_filas, int cantidad_columnas);
        
};

#endif //_CARGAR_MAPA_H_