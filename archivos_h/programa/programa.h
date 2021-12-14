#ifndef _PROGRAMA_H_
#define _PROGRAMA_H_

#include "../menu/menu_configuracion.h"
#include "../menu/menu_partida.h"
#include "../carga_de_datos/cargar_edificios.h"
#include "../carga_de_datos/cargar_mapa.h"
#include "../carga_de_datos/cargar_materiales.h"
#include "../carga_de_datos/cargar_ubicaciones.h"
#include <cstdlib>

class Programa {

    private:

        Menu_configuracion menu_configuracion;
        Menu_partida menu_partida;
        Cargar_materiales materiales;
        Cargar_edificios edificios;
        Cargar_mapa mapa;
        Cargar_ubicaciones ubicacion;
        Andypolis* juego;
        bool existe_ubicaciones;
    
    public:

        /*
        *Post: Creará un objeto de tipo programa, dejando los atributos correctamente cargados con sus valores por defecto.
        */
        Programa();

        /*
        *Post: Emperzará el programa.
        */
        void empezar();

        /*
        *Post: Finalizará el programa, dejandolo con todos los cambios realizados actualizados.
        */
        void finalizar();
        
        /*
        *Post: Liberara la memoria utilizada por la clase.
        */
        ~Programa();

};

#endif //_PROGRAMA_H_