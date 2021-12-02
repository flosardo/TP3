#ifndef _EDIFICIO_H_
#define _EDIFICIO_H_

#include "../constantes.h"

class Edificio{

    protected:

        unsigned int fila;
        unsigned int columna;
        std::string nombre_material;
        unsigned int cantidad_material_producido;
        unsigned int* materiales_necesarios;
        unsigned int permitidos;
        bool afectado;
        std::string nombre_del_edificio;
        std::string codigo_emoji;

    public:

        /*
        *Post: Creará un objeto de tipo Edificio, con sus atributos cargados con valores por defecto.
        */
        Edificio();

        /*
        *Post: Creará un objeto de tipo Edificio con los parametros jugador, piedra_necesaria, metal_necesario, madera_necesaria.
        */
        Edificio(unsigned int piedra_necesaria, unsigned int madera_necesaria, unsigned int metal_necesario, unsigned int permitidos);

        /*
        *Post: Creará un objeto de tipo Edificio con los valores de los parametros recibidos.
        */
        Edificio(unsigned int fila, unsigned int columna);

        /*
        *Post: Devolvera la fila del edificio.
        */
        unsigned int obtener_fila();

        /*
        *Post: Devolvera la columna del edificio.
        */
        unsigned int obtener_columna();

        /*
        *Post: Devolvera la columna del edificio.
        */
        void establecer_nuevos_materiales(unsigned int nueva_piedra, unsigned int nueva_madera, unsigned int nuevo_metal);

        /*
        *Post: Devolverá la representacion del edificio.
        */
        std::string obtener_codigo_emoji();

        /*
        *Post: Devolverá el nombre del material que produce.
        */
        std::string obtener_nombre_del_material();

        /*
        *Post: Devolverá la cantidad de material producido.
        */
        unsigned int obtener_cantidad_de_material_producido();

        /*
        Post: devuelve un puntero al vector que contiene los materiales necesarios
        */
        unsigned int* obtener_materiales_necesarios();

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
        Pos:
        */
        void virtual mostrar_caracteristicas(int construidos) = 0;

        /*
        *Post: Inicializara los atributos, según el comportamiento de cada hija.
        */
        virtual void inicializar_atributos() = 0;

        /*
        Post: libera la memoria pedida
        */
        virtual ~Edificio();

};

#endif //_EDIFICIO_H_