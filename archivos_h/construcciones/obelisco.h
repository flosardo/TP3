#ifndef _OBELISCO_H_
#define _OBELISCO_H_

#include "edificio.h"

class Obelisco : public Edificio {

    public:

        /*
        *Post: Creará un objeto de tipo Obelisco, dejandolo con sus atributos cargados con valores por defecto.
        */
        Obelisco();

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Creará un objeto de tipo Obelisco, usando los parámetros que recibe.
        */
        Obelisco(int piedra_necesaria, int madera_necesaria, int metal_necesario, int permitidos);

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Creará un objeto de tipo Obelisco usando los parámetros que recibe.
        */
        Obelisco(int fila, int columna);

        /*
        *Pre: Que el parametro sea >= 0.
        *Post: Mostrará las caracteristicas.
        */
        void mostrar_caracteristicas(int construidos);

        /*
        *Post: Mostrará un saludo por consola del edificio obelisco.
        */
        void mostrar_saludo();

    private:

        /*
        *Post: Inicializara los atributos de la clase.
        */
        void inicializar_atributos();
        
};

#endif //_OBELISCO_H_