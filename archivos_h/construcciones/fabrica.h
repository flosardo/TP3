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
        *Post: Creará un objeto de tipo Fábrica con los valores pasados por parámetro.
        */
        Fabrica(int piedra_necesaria, int madera_necesaria, int metal_necesario, int permitidos);

        /*
        *Post: Creará un objeto de tipo Fabrica usando los parámetros que recibe.
        */
        Fabrica(int fila, int columna);

        /*
        Pos:
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