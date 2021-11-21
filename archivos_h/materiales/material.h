#ifndef _MATERIAL_H_
#define _MATERIAL_H_
#include "../constantes.h"

class Material {

protected:

    char nombre;
    unsigned int cantidad;

public:

    /*
    * Post: Creará un objeto de tipo material, dejando sus atributos cargados con los valores por defecto.
    */
    Material();

    /*
    * Post: Devolverá la cantidad de material.
    */
    unsigned int cantidad_material();

    /*
    * Post: Devolverá el tipo de material.
    */
    char obtener_nombre_material();

    /*
    * Post: Mostrará el estado en el que se encuentra el material.
    */
    virtual void mostrar_material() = 0;

    /*
    * Post: Modificará la cantidad segun corresponda.
    */
    virtual void modificar_cantidad(int cantidad_a_modificar);

    /*
    * Post: Hace que las clases hijas muestren su saludo, según sea el comportamiento de cada hija.
    */
    virtual void saludar();

    /*
    * Post: Destruye el material, liberando la memoria utilizada por el mismo.
    */
    virtual ~Material();
    
};

#endif // _MATERIAL_H_