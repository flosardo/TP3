#ifndef _OBELISCO_H_
#define _OBELISCO_H_

#include "edificio.h"

class Obelisco : public Edificio{

    public:

        /*
        *Post: Creará un objeto de tipo Obelisco, dejandolo con sus atributos cargados con valores por defecto.
        */
        Obelisco();

        /*
        *Post: Creará un objeto de tipo Obelisco, usando los parámetros que recibe.
        */
        Obelisco(char jugador, unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria);

        /*
        *Post: Creará un objeto de tipo Obelisco usando los parámetros que recibe.
        */
        Obelisco(char jugador);

        /*
        *Post: Mostrará un saludo por consola del edificio obelisco.
        */
        void mostrar_saludo();
        
};

#endif //_OBELISCO_H_