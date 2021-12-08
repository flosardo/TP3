#ifndef _ESCUELA_H_
#define _ESCUELA_H_

#include "edificio.h"

class Escuela : public Edificio {

    public:

        /*
        *Post: Creará un objeto de tipo Escuela, dejandolo con sus atributos cargados con valores por defecto.
        */
        Escuela();

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Creará un objeto de tipo Escuela, usando los parámetros que recibe.
        */
        Escuela(int piedra_necesaria, int madera_necesaria, int metal_necesario, int permitidos);

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Creará un objeto de tipo Escuela usando los parametros que recibe.
        */
        Escuela(int fila, int columna); 

        /*
        *Post: Creará un objeto de tipo Escuela usando los parámetros que recibe.
        */
        Escuela(char jugador);

        /*
        *Pre: Que el parametro sea >= 0.
        *Post: Mostrará las caracteristicas.
        */
        void mostrar_caracteristicas(int construidos);

        /*
        *Post: Mostrará un saludo por consola del edificio de tipo escuela.
        */
        void mostrar_saludo();

        void aumentar_material_producido();

    private:
    
        /*
        *Post: Inicializara los atributos de la clase.
        */
        void inicializar_atributos();
    
};

#endif //_ESCUELA_H_