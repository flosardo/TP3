#ifndef _MENU_H_
#define _MENU_H_
#include "../constantes.h"

class Menu{

    protected:

        int opcion_ingresada;
    
    public:

        /*
        *Post: Mostrará el menú que corresponda, según el comportamiento de cada hija.
        */
        virtual void mostrar_menu() = 0;
        
        /*
        *Post: Pedira una opcion para procesar.
        */
        int pedir_opcion();
        
};

#endif //_MENU_H_