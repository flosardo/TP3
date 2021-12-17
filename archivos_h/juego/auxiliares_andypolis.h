#ifndef _AUXILIARES_ANDYPOLIS_H_
#define _AUXILIARES_ANDYPOLIS_H_

#include "../objetivos/objetivo_andycoins.h"
#include "../objetivos/objetivo_armado.h"
#include "../objetivos/objetivo_bombardero.h"
#include "../objetivos/objetivo_cansado.h"
#include "../objetivos/objetivo_constructor.h"
#include "../objetivos/objetivo_energetico.h"
#include "../objetivos/objetivo_extremista.h"
#include "../objetivos/objetivo_letrado.h"
#include "../objetivos/objetivo_minero.h"
#include "../objetivos/objetivo_obelisco.h"
#include "../objetivos/objetivo_piedra.h"
#include "../../archivos_h/arbol/abb.h"
#include "../../archivos_h/mapa.h"
#include "../grafos/grafo.h"
#include "../construcciones/aserradero.h"
#include "../construcciones/mina.h"
#include "../construcciones/mina_oro.h"
#include "../construcciones/fabrica.h"
#include "../construcciones/escuela.h"
#include "../construcciones/planta_electrica.h"
#include "../construcciones/obelisco.h"
#include "../materiales/piedra.h"
#include "../materiales/madera.h"
#include "../materiales/metal.h"
#include "../materiales/andycoins.h"
#include "../system.h"
#include <unistd.h>
#include <algorithm>

class Auxiliares_andypolis {

    public:

        /*
        *Post: Construirá un objeto de tipo Auxiliares_andypolis con los valores por defecto.
        */
        Auxiliares_andypolis();

        /*
        *Post: Seleccionará el jugador que va a ser el actual.
        */
        void seleccionar_jugador(std::string & nombre_1, std::string & nombre_2);

        /*
        *Post: Cambiara el turno del jugador actual.
        */
        Jugador* cambiar_turno(Jugador* jugador_actual, Jugador* jugador_1, Jugador* jugador_2);
        
        /*
        *Pre: Que los parametros no sean null
        *Post: Cargará los caminos del grafo.
        */
        void cargar_caminos(Grafo* grafo, Mapa* mapa, Jugador* jugador_actual);
        
        /*
        *Pre: Que los parametros de tipo puntero no sea null, que fila y columna sean >= 0.
        *Post: Obtendrá el costo del camino.
        */
        int obtener_coste_camino(Mapa* mapa, Jugador* jugador, int fila, int columna);
        
        /*
        *Pre: Que el parametro no sea null.
        *Post: Inicializará el arreglo de objetivos.
        */
        void inicializar_arreglo_objetivos(Objetivo** objetivos);
        
        /*
        *Pre: Que el parámetro no sea null, y que permitidos_escuela >= 0.
        *Post: Inicializará el arreglo de objetivos.
        */
        void cargar_objetivos(Objetivo** objetivos, int permitidos_escuela);
        
        /*
        *Pre: Que los parametros punteros no sean null, y que indice sea >= 0.
        *Post: Devolverá true si el objetivo fue asignado, false en caso contrario.
        */
        bool el_objetivo_fue_asignado(Objetivo** objetivos, Objetivo* objetivo_a_asignar, int indice);
        
        /*
        *Pre: Que los parámetros no sean null.
        *Post: Devolverá true si gano la partida, false en caso contrario.
        */
        bool gano_la_partida(Jugador* jugador, Objetivo** objetivos);
        
        /*
        *Pre: Que objetivos no sea null, y permitidos_escuela >= 0.
        *Post: Asignará los objetivos a los vectores de objetivos de cada jugador.
        */
        void asignar_objetivos(Objetivo** objetivos, int permitidos_escuela);
        
        /*
        *Pre: Que el parametro no sea null.
        *Post: Aumentará la cantidad de materiales producidos.
        */
        void aumentar_materiales_producidos(Jugador* jugador_actual);

        /*
        *Pre: Que los parametros mapa, jugador_actual, jugador_1, jugador_2 no sean null, que la fila y columna sean >= 0.
        *Post: Aumentará los materiales producidos.
        */
        void atacar_edificio_auxiliar(Mapa* mapa, Jugador* jugador_actual, Jugador* jugador_1, Jugador* jugador_2, int fila, int columna);

        /*
        *Pre: Que el parametro no sea null.
        *Post: Hará la lluvia de materiales.
        */
        void lluvia_materiales(Mapa* mapa);

        /*
        *Pre: Que el mapa no sea null, y cantidad_a_generar sea >= 0.
        *Post: Hará la lluvia de un material.
        */
        void lluvia_material(std::string nombre_material, int cantidad_a_generar, Mapa* mapa);

        /*
        *Post: Devolvera un puntero de tipo Material con el material deseado.
        */
        Material* generar_material(std::string nombre_material);

        /*
        *Post: Obtendrá un puntero con las coordenadas pedidas.
        */
        int* pedir_coordenadas(Mapa* mapa);

        /*
        *Pre: Que la opcion sea >= 0.
        *Post: Verificará la energía.
        */
        bool tiene_energia(Jugador* jugador_actual);

        /*
        *Pre: que jugador no sea nulo
        *Pos: realiza el movimiento del jugador en las coordenadas recibidas
        */
        void realizar_movimiento(Jugador* jugador, Mapa* mapa, int fila, int columna);

        /*
        *Pre:
        *Pos:
        */
        void mover_jugador(Jugador *jugador, Mapa* mapa, int fila, int columna, int energia_consumida);

        /*
        *Pre: que jugador no sea nulo
        *Pos: recolecta los materiales en fila y columna y se los asgina al jugador recibido
        */
        void recolectar_materiales(Jugador* jugador, Mapa* mapa, int fila, int columna);

        /*
        *Pre: que ambos parametros no sean nulos
        *Pos: carga el grafo
        */
        void cargar_grafo_auxiliar(Grafo* grafo, Mapa* mapa);

        /*
        *Post: Obtendrá un string con el string del nombre del edificio pedido.
        */
        std::string pedir_nombre_edificio();

        /*
        *Post: Obtendrá la nueva cantidad de material pedida.
        */
        int pedir_nueva_cantidad_material(std::string material);

        /*
        *Pre: Que el parámetro no sea null.
        *Post: Modificará los materiales necesarios de un edificio.
        */
        void modificar_materiales_necesarios(Edificio* edificio);

        /*
        *Pre: Que los parámetros sean >= 0.
        *Post: Obtendrá true si hay energia suficiente para realizar la operación, false en caso contrario.
        */
        bool hay_energia_suficiente(int energia_necesaria, int energia_del_jugador);

        /*
        *Pre: Que los parámetros sean >= 0.
        *Post: Obtendrá true si es posible comprar bombas, false en caso contrario.
        */
        bool es_posible_comprar_bombas(Inventario* inventario, int cantidad_bombas);

        /*
        *Post: Construirá un edificio.
        */
        void construir_edificio_auxiliar(Abb* edificios_disponibles, Mapa* mapa, Jugador* jugador_actual, std::string edificio_a_construir);

        /*
        *Pre: Que el parámetro no sea null.
        *Post: Obtendrá true si se alcanzo el maximo permitido, false en caso contrario.
        */
        bool se_alcanzo_maximo_permitido(Edificio* edificio_a_construir, Jugador* jugador_actual);

        /*
        *Post: Modificará los materiales necesarios.
        */
        void modificar_materiales_necesarios(std::string edificio);

        /*
        *Pre: Que el parametro inventario y edificio no sean null.
        *Post: Obtendrá true si hay materiales suficientes, false en caso contrario.
        */
        bool hay_material_suficiente(std::string material, Inventario* inventario, int cantidad_material);

        /*
        *Pre: Que los parametros no sea null.
        *Pos: Actualizará el inventario del jugador.
        */
        void actualizar_inventario(Inventario* inventario, int piedra, int madera, int metal);

        /*
        *Post: Obtendrá true si se confirmo la construcción, false en caso contrario.
        */
        bool confirmar_construccion(std::string edificio_a_construir);

        /*
        *Pre: Que los parámetros fila y columna sean >= 0.
        *Post: Obtendrá un puntero de tipo Edificio, que contendra la información del edificio creado.
        */
        Edificio* crear_edificio(std::string nombre, int fila, int columna);

        /*
        *Pre: Que los parametros edificios_disponibles, mapa, jugador_actual sean != null, y que fila y columna sean >= 0.
        *Post: Demolerá un edificio de andypolis.
        */
        void demoler_edificio_auxiliar(Abb* edificios_disponibles, Mapa* mapa, Jugador* jugador_actual, int fila, int columna);

        /*
        *Pre: que los parametros recibidos no sean nulos
        *Pos: movera al jugdaor recibido a las coordenadas solicitadas en caso de ser posible
        */
        void moverse_auxiliar(Grafo* grafo, Mapa* mapa, Jugador* jugador);

        /*
        *Pre: Que los parametros edificios_disponibles, mapa, jugador_actual sean != null, y que fila y columna sean >= 0.
        *Post: Reparará un edificio de andypolis
        */
        void reparar_edificio_auxiliar(Abb* edificios_disponibles, Mapa* mapa, Jugador* jugador_actual, int fila, int columna);

        /*
        *Pre: Que el parametro no sea null.
        *Post: Recolectará los recursos.
        */
        void recolectar_recursos_auxiliares(Jugador* jugador_actual);

        /*
        *Pre:
        *Pos: muestra por pantalla las preguntas frecuentes
        */
        void mostrar_preguntas_frecuentes_auxiliares();
        
};

#endif //_AUXILIARES_ANDYPOLIS_H_