#ifndef _PLANTA_ELECTRICA_H_
#define _PLANTA_ELECTRICA_H_

#include "edificio.h"

class Planta_electrica : public Edificio{

    public:

        /*
        *Post: Creará un objeto de tipo Planta_electrica, dejando sus atributos cargados con valores por defecto.
        */
        Planta_electrica();

        /*
        *Post: Creará un objeto de tipo Planta_electrica con los parámetros recibidos.
        */
        Planta_electrica(unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria, unsigned int permitidos);

        /*
        *Post: Creará un objeto de tipo Planta_electrica usando los parámetros que recibe.
        */
        Planta_electrica(char jugador);

        /*
        *Post: Mostrará un saludo del edificio planta electrica por consola.
        */
        void mostrar_saludo();
        
};

#endif //_PLANTA_ELECTRICA_H_