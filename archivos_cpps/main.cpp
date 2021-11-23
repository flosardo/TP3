#include "../archivos_h/menu/menu_partida.h"
#include "../archivos_h/menu/menu_configuracion.h"
#include "../archivos_h/materiales/madera.h"
#include "../archivos_h/materiales/metal.h"
#include "../archivos_h/materiales/bomba.h"
using namespace std;
int main(){
    Madera madera(20);
    Metal metal(2);
    Bomba bomba(2);
    madera.saludar();
    madera.mostrar_material();
    metal.mostrar_material();
    bomba.mostrar_material();
    return 0;
}

/* holaaa */
