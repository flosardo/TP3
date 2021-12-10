#ifndef _CARGAR_EDIFICIOS_H_
#define _CARGAR_EDIFICIOS_H_

#include <fstream>
#include "../arbol/abb.h"
#include "../construcciones/aserradero.h"
#include "../construcciones/escuela.h"
#include "../construcciones/fabrica.h"
#include "../construcciones/mina.h"
#include "../construcciones/mina_oro.h"
#include "../construcciones/obelisco.h"
#include "../construcciones/planta_electrica.h"

class Cargar_edificios {
    
    private:

        std::string archivo_ruta;

    public:

        /*
        *Post: Creara un objeto de tipo Cargar_edificios, con sus valores por defecto.
        */
        Cargar_edificios();

        /*
        *Pre: Que arbol no sea null.
        *Post: Cargará el arbol de edificios.
        */
        void carga_edificios(Abb* arbol);

        /*
        *Pre: Que arbol no sea null.
        *Post: Guardará el arbol de edificios.
        */
        void guardar_edificios(Abb* arbol);

    private: 

        /*
        *Pre: Que el archivo exista, que arbol y edificio no sean null, y que piedra, madera, metal, y permitidos sean >= 0.
        *Post: Creará un edificio.
        */
        void crear_edificio(Abb* arbol, std::string nombre_edificio, int piedra, int madera, int metal, int permitidos);

        /*
        *Pre: Que el archivo exista, que edificios este correctamente cargado, que la cantidad sea >= 0.
        *Post: Guardará los edificios en el archivo de edificios.
        */
        void editar_archivo_edificios(std::ofstream & archivo_edificios, Edificio** edificios, int cantidad_edificios);
        
};

#endif //_CARGAR_EDIFICIOS_H_