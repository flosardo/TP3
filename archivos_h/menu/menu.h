#ifndef _MENU_H_
#define _MENU_H_
#include "../constantes.h"
#include "../system.h"
#include "../juego/andypolis.h"

class Menu {

    protected:

        int opcion_ingresada;
    
    public:

        /*
        *Post: Mostrará el menú que corresponda, según el comportamiento de cada hija.
        */
        virtual void mostrar_menu() = 0;

        /*
        *Post: Mostrará el mensaje de bienvenida del menú que corresponda, según el comportamiento de cada hija.
        */
        virtual void mostrar_mensaje_bienvenida() = 0;

        /*
        *Post: Procesara las opciones, según el comportamiento de cada hija.
        */
        virtual void procesar_opcion(int opcion, Andypolis juego) = 0;
        
        /*
        *Post: Pedira una opcion para procesar.
        */
        int pedir_opcion();

        /*
        *Post: Liberará la memoria.
        */
        virtual ~Menu();

};

#endif //_MENU_H_