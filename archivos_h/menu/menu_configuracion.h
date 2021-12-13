#ifndef _MENU_CONFIGURACION_H_
#define _MENU_CONFIGURACION_H_
#include "menu.h"

class Menu_configuracion: public Menu {

    public:

        /*
        *Post: Creará un objeto de tipo Menu_configuracion con sus valores por defecto.
        */
        Menu_configuracion();
        
        /*
        *Post: Mostrará el menu de configuracion del juego.
        */
        void mostrar_menu();

        /*
        *Post: Procesará la opcion.
        */
        void procesar_opcion(int & opcion, Andypolis* juego);

        /*
        *Post: Mostrará el mensaje de bienvenida del menu de configuración.
        */
        void mostrar_mensaje_bienvenida();
        
};

#endif //_MENU_CONFIGURACION_H_