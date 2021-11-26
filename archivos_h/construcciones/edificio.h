#ifndef _EDIFICIO_H_
#define _EDIFICIO_H_

#include "../constantes.h"

class Edificio{

    protected:

        char jugador;
        char representacion_edificio;
        char nombre_material;
        unsigned int cantidad_material_producido;
        unsigned int piedra_necesaria;
        unsigned int metal_necesario;
        unsigned int madera_necesaria;
        bool afectado;
        std::string nombre_del_edificio;

    public:

        /*
        *Post: Creará un objeto de tipo Edificio, con sus atributos cargados con valores por defecto.
        */
        Edificio();

        /*
        *Post: Creará un objeto de tipo Edificio con los parametros jugador, piedra_necesaria, metal_necesario, madera_necesaria.
        */
        Edificio(char jugador, unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria);

        /*
        *Post: Devolverá la representacion del edificio.
        */
        char obtener_representacion_del_edificio();

        /*
        *Post: Devolverá el nombre del material que produce.
        */
        char obtener_nombre_del_material();

        /*
        *Post: Devolverá la cantidad de material producido.
        */
        unsigned int obtener_cantidad_de_material_producido();

        /*
        *Post: Devolverá la cantidad de maderá necesaria.
        */
        unsigned int obtener_cantidad_madera_necesaria();

        /*
        *Post: Devolverá la cantidad de metal necesario.
        */
        unsigned int obtener_cantidad_metal_necesario();

        /*
        *Post: Devolverá la cantidad de piedra necesaria.
        */
        unsigned int obtener_cantidad_piedra_necesaria();

        /*
        *Post: Devolverá el jugador.
        */
        char obtener_jugador();

        /*
        *Post: Devolverá el estado del edificio.
        */
        bool esta_afectado();

        /*
        *Post: Cambiará el estado de afectado del edificio.
        */
        void cambiar_estado_afectado();
        
        /*
        *Post: Muestra por pantalla el saludo del edificio
        */
        virtual void mostrar_saludo() = 0;

        /*
        Pos: devuelve el nombre del edificio
        */
        std::string obtener_nombre_del_edificio();

        /*
        *Pre: Liberara la memoria utilizada por el edificio a lo largo del programa.
        */
        virtual ~Edificio();

};

#endif //_EDIFICIO_H_