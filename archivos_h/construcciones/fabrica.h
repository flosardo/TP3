#ifndef _FABRICA_H_
#define _FABRICA_H_

#include "edificio.h"

class Fabrica : public Edificio {
    
    public:

        /*
        *Post: Creara un objeto de tipo Fábrica con sus valores por defecto.
        */
        Fabrica();

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Creará un objeto de tipo Fábrica con los valores pasados por parámetro.
        */
        Fabrica(int piedra_necesaria, int madera_necesaria, int metal_necesario, int permitidos);

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Creará un objeto de tipo Fabrica usando los parámetros que recibe.
        */
        Fabrica(int fila, int columna);

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
        *Post: Mostrará un saludo por consola de un edificio Fabrica.
        */
        void mostrar_saludo();

    private:

        /*
        *Post: Inicializara los atributos de la clase.
        */
        void inicializar_atributos();

};

#endif //_FABRICA_H_