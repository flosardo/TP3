#ifndef _PLANTA_ELECTRICA_H_
#define _PLANTA_ELECTRICA_H_

#include "edificio.h"

class Planta_electrica : public Edificio{

    public:

        /*
        *Post: Creará un objeto de tipo Planta_electrica, dejando sus atributos cargados con valores por defecto.
        */
        Planta_electrica();

        /*
        *Post: Creará un objeto de tipo Planta_electrica con los parámetros recibidos.
        */
        Planta_electrica(unsigned int piedra_necesaria, unsigned int madera_necesaria, unsigned int metal_necesario, unsigned int permitidos);

        /*
        *Post: Creará un objeto de tipo Planta_electrica usando los parámetros que recibe.
        */
        Planta_electrica(unsigned int fila, unsigned int columna);

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