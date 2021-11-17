#include "../archivos_h/menu/menu_partida.h"
#include "../archivos_h/menu/menu_configuracion.h"
#include "../archivos_h/materiales/madera.h"
using namespace std;
int main(){
    Madera mat(20);
    mat.mostrar_estado();
    Menu_configuracion a;
    Menu_partida b;
    a.mostrar_menu();
    cout << endl;
    b.mostrar_menu();
    cout << endl;
    return 0;
}