#ifndef _OBELISCO_H_
#define _OBELISCO_H_

#include "edificio.h"

class Obelisco : public Edificio{

    public:

        /*
        *Post: Creará un objeto de tipo Obelisco, dejandolo con sus atributos cargados con valores por defecto.
        */
        Obelisco();

        /*
        *Post: Creará un objeto de tipo Obelisco, usando los parámetros que recibe.
        */
        Obelisco(unsigned int piedra_necesaria, unsigned int madera_necesaria, unsigned int metal_necesario, unsigned int permitidos);

        /*
        *Post: Creará un objeto de tipo Obelisco usando los parámetros que recibe.
        */
        Obelisco(unsigned int fila, unsigned int columna);

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