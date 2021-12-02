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
        *Post: Creará un objeto de tipo Aserradero usando los parametros que recibe.
        */
        Aserradero(unsigned int fila, unsigned int columna);

        /*
        Pos:
        */
        void mostrar_caracteristicas(int construidos);      

        /*
        *Post: Mostrará un saludo del edificio aserradero por consola.
        */
        void mostrar_saludo();

    private:

        /*
        *Pre:
        *Post:
        */
        void inicializar_atributos();
        
};

#endif //_ASERRADERO_H_