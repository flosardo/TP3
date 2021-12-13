#ifndef _MINA_H_
#define _MINA_H_

#include "edificio.h"

class Mina : public Edificio {

    public:

        /*
        *Post: Creará un objeto de tipo Mina con los valores por defecto.
        */
        Mina();

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Creará un objeto de tipo Mina con los valores pasados por parámetro.
        */
        Mina(int piedra_necesaria, int madera_necesaria, int metal_necesario, int permitidos);

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Creará un objeto de tipo Mina usando los parámetros que recibe.
        */
        Mina(int fila, int columna);

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
        *Post: Mostrará un saludo por consola del edificio Mina.
        */
        void mostrar_saludo();

    private:

        /*
        *Post: Inicializara los atributos de la clase.
        */
        void inicializar_atributos();

};

#endif //_MINA_H_