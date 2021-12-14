#ifndef _MENU_PARTIDA_H_

#define _MENU_PARTIDA_H_
#include "menu.h"

class Menu_partida : public Menu {

    public:

        /*
        *Post: Creará un objeto de tipo Menu_partida con sus valores por defecto.
        */
        Menu_partida();
        
        /*
        *Post: Mostrará el menu de partida del juego.
        */
        void mostrar_menu();

        /*
        *Post: Procesará la opcion.
        */
        void procesar_opcion(int & opcion, Andypolis* juego);
        
};

#endif //_MENU_PARTIDA_H_