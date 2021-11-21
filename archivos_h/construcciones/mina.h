#ifndef _MINA_H_
#define _MINA_H_

#include "edificio.h"

class Mina : public Edificio {

    public:

        /*
        * Post: Creará un objeto de tipo Mina con los valores por defecto.
        */
        Mina();

        /*
        * Post: Creará un objeto de tipo Mina con los valores pasados por parámetro.
        */
        Mina(char jugador, unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria);

        // PRE:
        // POS: muestra por pantalla el saludo del edificio
        void mostrar_saludo();
};

#endif // _MINA_H_