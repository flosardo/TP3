#ifndef _EDIFICIO_H_
#define _EDIFICIO_H_

#include "../constantes.h"

class Edificio {

    protected:

        std::string nombre_del_edificio;
        int* materiales_necesarios;
        int permitidos;
        std::string nombre_material;
        int cantidad_material_producido;
        int* coordenadas;
        bool afectado;
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
        Pos: Devuelve el nombre del edificio
        */
        std::string obtener_nombre();

        /*
        Post: Devuelve un puntero al vector que contiene los materiales necesarios
        */
        int obtener_cantidad_necesaria(std::string material);

        /*
        *Post: Inicializara los atributos, según el comportamiento de cada hija.
        */
        int obtener_permitidos();

        /*
        *Post: Obtendra el nombre del material que produce.
        */
        std::string obtener_tipo_material_producido();

        /*
        *Post: Obtendra la cantidad de material producido.
        */
        int obtener_cantidad_de_material_producido();

        /*
        *Post: Obtendra el vector de coordenadas el edificio.
        */
        int* obtener_coordenadas();

        /*
        *Post: Obtendra la representacion del edificio.
        */
        std::string obtener_codigo_emoji();

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: Obtendra la columna del edificio.
        */
        void establecer_nuevos_materiales(int nueva_piedra, int nueva_madera, int nuevo_metal);

        /*
        *Post: Obtendra el estado del edificio.
        */
        bool esta_afectado();

        /*
        *Post: Cambiará el estado de afectado del edificio.
        */
        void cambiar_estado_afectado();

        /*
        *Post: Aumentará la cantidad de material que produce el edificio.
        */
        virtual void aumentar_material_producido();

        /*
        *Post: Inicializara los atributos, según el comportamiento de cada hija.
        */
        virtual void inicializar_atributos() = 0;

        /*
        *Pre: Que el parametro sea >= 0.
        *Post: Mostrará las caracteristicas.
        */
        void virtual mostrar_caracteristicas(int construidos) = 0;

        /*
        *Post: Muestra por pantalla el saludo del edificio
        */
        virtual void mostrar_saludo() = 0;

        /*
        *Post: Libera la memoria pedida.
        */
        virtual ~Edificio();

};

#endif //_EDIFICIO_H_