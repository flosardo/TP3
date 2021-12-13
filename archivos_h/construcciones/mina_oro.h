#ifndef _MINA_ORO_H_
#define _MINA_ORO_H_

#include "edificio.h"

class Mina_oro : public Edificio {

    public:

        /*
        *Post: Creará un objeto de tipo mina_oro, dejando sus atributos cargados con valores por defecto.
        */
        Mina_oro();

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Creará un objeto de tipo mina_oro con los parámetros recibidos.
        */
        Mina_oro(int piedra_necesaria, int madera_necesaria, int metal_necesario, int permitidos);

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Creará un objeto de tipo Mina_oro usando los parámetros que recibe.
        */
        Mina_oro(int fila, int columna);

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
        *Post: Mostrará un saludo por consola del edificio mina oro.
        */
        void mostrar_saludo();

    private:

        /*
        *Post: Inicializara los atributos de la clase.
        */
        void inicializar_atributos();

};

#endif //_MINA_ORO_H_