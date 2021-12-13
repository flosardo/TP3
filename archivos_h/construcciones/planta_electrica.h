#ifndef _PLANTA_ELECTRICA_H_
#define _PLANTA_ELECTRICA_H_

#include "edificio.h"

class Planta_electrica : public Edificio {

    public:

        /*
        *Post: Creará un objeto de tipo Planta_electrica, dejando sus atributos cargados con valores por defecto.
        */
        Planta_electrica();

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Creará un objeto de tipo Planta_electrica con los parámetros recibidos.
        */
        Planta_electrica(int piedra_necesaria, int madera_necesaria, int metal_necesario, int permitidos);

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Creará un objeto de tipo Planta_electrica usando los parámetros que recibe.
        */
        Planta_electrica(int fila, int columna);

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
        *Post: Mostrará un saludo del edificio planta electrica por consola.
        */
        void mostrar_saludo();

    private:

        /*
        *Post: Inicializara los atributos de la clase.
        */
        void inicializar_atributos();
        
};

#endif //_PLANTA_ELECTRICA_H_