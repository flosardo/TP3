#ifndef _MENU_H_
#define _MENU_H_
#include "../constantes.h"
#include <iostream>
class Menu{
    protected:
    int opcion_ingresada;
    
    public:
        // PRE
        // POS
        virtual void mostrar_menu() = 0;
        
        // PRE
        // POS:
        int pedir_opcion();
};

#endif //_MENU_H_