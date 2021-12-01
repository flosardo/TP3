#ifndef _MINA_H_
#define _MINA_H_

#include "edificio.h"

class Mina : public Edificio{

    public:

        /*
        *Post: Creará un objeto de tipo Mina con los valores por defecto.
        */
        Mina();

        /*
        *Post: Creará un objeto de tipo Mina con los valores pasados por parámetro.
        */
        Mina(unsigned int piedra_necesaria, unsigned int madera_necesaria, unsigned int metal_necesario, unsigned int permitidos);

        /*
        *Post: Creará un objeto de tipo Mina usando los parámetros que recibe.
        */
        Mina(unsigned int fila, unsigned int columna);

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