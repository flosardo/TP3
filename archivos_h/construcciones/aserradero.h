#ifndef _ASERRADERO_H_
#define _ASERRADERO_H_

#include "edificio.h"

class Aserradero : public Edificio {

    public:

        /*
        *Post: Creará un objeto de tipo Aserradero dejando sus atributos cargados con valores por defecto.
        */
        Aserradero();

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Creará un objeto de tipo Aserradero usando los parametros que recibe.
        */
        Aserradero(int piedra_necesaria, int madera_necesaria, int metal_necesario, int permitidos);

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Creará un objeto de tipo Aserradero usando los parametros que recibe.
        */
        Aserradero(int fila, int columna);

        /*
        *Post: Aumentará la cantidad de material que produce el edificio.
        */
        void aumentar_material_producido();

        /*
        *Pre: Que el parametro sea >= 0.
        *Post: Mostrará las caracteristicas.
        */
        void mostrar_caracteristicas(int construidos);      

        /*
        *Post: Mostrará un saludo del edificio aserradero por consola.
        */
        void mostrar_saludo();

    private:

        /*
        *Post: Inicializará los atributos del objeto.
        */
        void inicializar_atributos();
        
};

#endif //_ASERRADERO_H_