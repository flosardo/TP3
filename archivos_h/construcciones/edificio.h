#ifndef _EDIFICIO_H_
#define _EDIFICIO_H_

#include "../constantes.h"

class Edificio {

    protected:

        int fila;
        int columna;
        std::string nombre_material;
        int cantidad_material_producido;
        int* materiales_necesarios;
        int permitidos;
        bool afectado;
        std::string nombre_del_edificio;
        std::string codigo_emoji;

    public:

        /*
        *Post: Creará un objeto de tipo Edificio, con sus atributos cargados con valores por defecto.
        */
        Edificio();

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Creará un objeto de tipo Edificio con los parametros jugador, piedra_necesaria, metal_necesario, madera_necesaria.
        */
        Edificio(int piedra_necesaria, int madera_necesaria, int metal_necesario, int permitidos);

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Creará un objeto de tipo Edificio con los valores de los parametros recibidos.
        */
        Edificio(int fila, int columna);

        /*
        *Post: Devolvera la fila del edificio.
        */
        int obtener_fila();

        /*
        *Post: Devolvera la columna del edificio.
        */
        int obtener_columna();

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Devolvera la columna del edificio.
        */
        void establecer_nuevos_materiales(int nueva_piedra, int nueva_madera, int nuevo_metal);

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
        int obtener_cantidad_de_material_producido();

        /*
        Post: devuelve un puntero al vector que contiene los materiales necesarios
        */
        int obtener_cantidad_necesaria(std::string material);

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
        std::string obtener_nombre();
        
        /*
        *Post: Inicializara los atributos, según el comportamiento de cada hija.
        */
        int obtener_permitidos();

        /*
        *Pre: Que el parametro sea >= 0.
        *Post: Mostrará las caracteristicas.
        */
        void virtual mostrar_caracteristicas(int construidos) = 0;

        /*
        *Post: Inicializara los atributos, según el comportamiento de cada hija.
        */
        virtual void inicializar_atributos() = 0;

        /*
        *Post: libera la memoria pedida.
        */
        virtual ~Edificio();

};

#endif //_EDIFICIO_H_