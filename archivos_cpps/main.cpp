#include "../archivos_h/menu/menu_partida.h"
#include "../archivos_h/menu/menu_configuracion.h"
#include "../archivos_h/materiales/madera.h"
#include "../archivos_h/materiales/metal.h"
#include "../archivos_h/materiales/bomba.h"
#include "../archivos_h/carga_de_datos/cargar_ubicaciones.h"
#include "../archivos_h/carga_de_datos/cargar_edificios.h"
#include "../archivos_h/mapa.h"
#include "../archivos_h/arbol/abb.h"
#include "../archivos_h/juego/andypolis.h"

using namespace std;

int main(){
    Menu_configuracion c;
    Cargar_ubicaciones car;
    Mapa map;
    Andypolis juego;
    Abb* nuevo_arbol = juego.devolver_arbol();
    Cargar_edificios edi;
    edi.carga_edificios(nuevo_arbol);
    Edificio* edificio = nuevo_arbol -> buscar_edificio("planta electrica");
    cout << edificio -> obtener_nombre_del_edificio() << endl;
    unsigned int* mat_viejos = edificio -> obtener_materiales_necesarios();
    cout << mat_viejos[0] << " " << mat_viejos[1] << " " << mat_viejos[2] << endl;
    juego.modificar_edificio_nombre();
    unsigned int* nuevos_mat = edificio -> obtener_materiales_necesarios();
    cout << nuevos_mat[0] << " " << nuevos_mat[1] << " " << nuevos_mat[2] << endl;
    delete nuevo_arbol;
    return 0;
}