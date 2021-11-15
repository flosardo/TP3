#ifndef _EDIFICIO_H_
#define _EDIFICIO_H_

class Edificio{

protected:
    char nombre_edificio;
    char nombre_material;
    int cantidad_material_producido;
    int piedra_necesaria;
    int metal_necesario;
    int madera_necesaria;

public:
    /*
        * Post: Creará un objeto de tipo Edificio, con sus atributos cargados con valores por defecto.
        */
    Edificio();

    /*
        * Post: Creará un objeto de tipo Edificio con los parametros piedra_necesaria, metal_necesario, madera_necesaria.
        */
    Edificio(int piedra_necesaria, int metal_necesario, int madera_necesaria);

    /*
        * Post: Devolverá el nombre del edificio.
        */
    char nombre_del_edificio();

    /*
        * Post: Devolverá el nombre del material que produce.
        */
    char nombre_del_material();

    /*
        * Post: Devolverá la cantidad de material producido.
        */
    int cantidad_de_material_producido();

    /*
        * Post: Devolverá la cantidad de maderá necesaria.
        */
    int cantidad_madera_necesaria();

    /*
        * Post: Devolverá la cantidad de metal necesario.
        */
    int cantidad_metal_necesario();

    /*
        * Post: Devolverá la cantidad de piedra necesaria.
        */
    int cantidad_piedra_necesaria();
};

#endif // EDIFICIO_H_