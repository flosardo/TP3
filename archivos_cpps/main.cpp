#include "../archivos_h/menu/menu_partida.h"
#include "../archivos_h/menu/menu_configuracion.h"
#include "../archivos_h/materiales/madera.h"
#include "../archivos_h/materiales/metal.h"
#include "../archivos_h/materiales/bomba.h"
#include "../archivos_h/carga_de_datos/cargar_ubicaciones.h"
#include "../archivos_h/carga_de_datos/cargar_edificios.h"
#include "../archivos_h/mapa.h"
#include "../archivos_h/arbol/abb.h"
using namespace std;
int main(){
    Menu_configuracion c;
    c.mostrar_menu();
    Cargar_ubicaciones car;
    Mapa map;
    //map.crear_mapa(8, 10);
    //car.carga_ubicaciones(&map);
    //Nodo* nuevo_nodo = new Nodo;
    // Edificio* mina = new Mina_oro(50,60,50,3);
    Abb* nuevo_arbol = new Abb;
    Cargar_edificios edi;
    edi.carga_edificios(nuevo_arbol);
    Madera madera(20);
    Metal metal(2);
    Bomba bomba(2);
    madera.saludar();
    madera.mostrar_material();
    metal.mostrar_material();
    bomba.mostrar_material();
    return 0;
}
