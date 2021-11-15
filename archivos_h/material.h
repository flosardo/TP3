#ifndef _MATERIAL_H_
#define _MATERIAL_H_

class Material{

protected:
    char nombre;
    int cantidad;

public:
    /*
        * Post: Creará un objeto de tipo material, dejando sus atributos cargados con los valores por defecto.
        */
    Material();

    /*
        * Post: Devolverá la cantidad de material.
        */
    int devolver_cantidad_material();

    /*
        * Post: Devolverá el tipo de material.
        */
    char devolver_nombre_material();

    /*
        * Post: Aumentará la cantidad del material, según corresponda la cantidad del parámetro cantidad_a_aumentar.
        */
    void aumentar_cantidad(int cantidad_a_aumentar);

    /*
        * Post: Reducirá la cantidad del material, según corresponda la cantidad del parámetro cantidad_a_reducir.
        */
    void reducir_cantidad(int cantidad_a_reducir);

    /*
        * Post: Hace que las clases hijas muestren un mensaje de estado, según sea el comportamiento de cada hija.
        */
    virtual void mostrar_estado();

    /*
        * Post: Destruye el material, liberando la memoria utilizada por el mismo.
        */
    virtual ~Material();
};

#endif // _MATERIAL_H_