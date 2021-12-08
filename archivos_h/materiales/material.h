#ifndef _MATERIAL_H_
#define _MATERIAL_H_
#include "../constantes.h"

class Material {

    protected:

        std::string nombre;
        int cantidad;
        std::string codigo_emoji;

    public:

        /*
        *Post: Creará un objeto de tipo material, dejando sus atributos cargados con los valores por defecto.
        */
        Material();

        /*
        *Post: obtenerá la cantidad de material.
        */
        int obtener_cantidad();

        /*
        *Post: obtenerá el tipo de material.
        */
        std::string obtener_nombre_material();

        /*
        *Post: obtenerá el codigo del emoji.
        */
        std::string obtener_codigo_emoji();

        /*
        *Post: Mostrará el estado en el que se encuentra el material.
        */
        virtual void mostrar_material() = 0;

        /*
        *Post: Modificará la cantidad segun corresponda.
        */
        virtual void modificar_cantidad(int cantidad_a_modificar);

        /*
        *Post: Hace que las clases hijas muestren su saludo, según sea el comportamiento de cada hija.
        */
        virtual void saludar();
        
};

#endif //_MATERIAL_H_