#ifndef _ASERRADERO_H_
#define _ASERRADERO_H_

#include "edificio.h"

class Aserradero : public Edificio{

    public:

        /*
         Post: Creará un objeto de tipo Aserradero dejando sus atributos cargados con valores por defecto.
        */
        Aserradero();

        /*
        *Post: Creará un objeto de tipo Aserradero usando los parametros que recibe.
        */
        Aserradero(unsigned int piedra_necesaria, unsigned int madera_necesaria, unsigned int metal_necesario, unsigned int permitidos);

        /*
        *Post: Creará un objeto de tipo Aserradero usando los parámetros que recibe.
        */
        Aserradero(char jugador);

        /*
        *Post: Mostrará un saludo del edificio aserradero por consola.
        */
        void mostrar_saludo();

        /*
        *Post: muestra por pantalla las caractersiticas del edificio
        */
        void mostrar_edificio(Mapa* mapa, Jugador* jugador); 
        
};

#endif //_ASERRADERO_H_