#include "../../archivos_h/materiales/metal.h"
#include "../../archivos_h/constantes.h"

using namespace std;

Metal::Metal(){
    nombre = METAL;
    cantidad = CANTIDAD_MAX_METAL_GENERADO;
}

Metal::Metal(int cantidad_inventario)
{
    nombre = METAL;
    cantidad = cantidad_inventario;
}

void Metal::mostrar_estado()
{
    cout << "Soy un metal, " << EMOJI_METAL << " y me encuentro en este casillero transitable." << endl;
}