#ifndef _ASERRADERO_H_
#define _ASERRADERO_H_

#include "edificio.h"

class Aserradero : public Edificio {

    public:

        /*
         Post: Creará un objeto de tipo Aserradero dejando sus atributos cargados con valores por defecto.
        */
        Aserradero();

        /*
        *Post: Creará un objeto de tipo Aserradero usando los parametros que recibe.
        */
        Aserradero(int piedra_necesaria, int madera_necesaria, int metal_necesario, int permitidos);

        /*
        *Post: Creará un objeto de tipo Aserradero usando los parametros que recibe.
        */
        Aserradero(int fila, int columna);

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