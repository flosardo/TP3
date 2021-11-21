#ifndef _MENU_H_
#define _MENU_H_
#include "../constantes.h"

class Menu {

    protected:

        int opcion_ingresada;
    
    public:

        /*
        FALTAN LAS CONDICIONES
        */
        virtual void mostrar_menu() = 0;
        
        /*
        FALTAN LAS CONDICIONES
        */
        int pedir_opcion();
};

#endif //_MENU_H_