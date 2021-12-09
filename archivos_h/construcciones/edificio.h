#ifndef _EDIFICIO_H_
#define _EDIFICIO_H_

#include "../constantes.h"

class Edificio {

    protected:

        std::string nombre_del_edificio;
        int* materiales_necesarios;
        int permitidos;
        int* coordenadas;
        std::string codigo_emoji;
        std::string nombre_material;
        int cantidad_material_producido;
        bool afectado;

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

        int* obtener_coordenadas();

        /*
        *Pre: Que los parametros sean >= 0.
        *Post: obtendra la columna del edificio.
        */
        void establecer_nuevos_materiales(int nueva_piedra, int nueva_madera, int nuevo_metal);

        /*
        *Post: obtendra la representacion del edificio.
        */
        std::string obtener_codigo_emoji();

        /*
        *Post: obtendra el nombre del material que produce.
        */
        std::string obtener_nombre_del_material();

        /*
        *Post: obtendra la cantidad de material producido.
        */
        int obtener_cantidad_de_material_producido();

        /*
        Post: devuelve un puntero al vector que contiene los materiales necesarios
        */
        int obtener_cantidad_necesaria(std::string material);

        /*
        *Post: obtendra el estado del edificio.
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

        virtual void aumentar_material_producido();

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