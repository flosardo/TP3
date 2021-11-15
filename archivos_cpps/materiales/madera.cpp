#include "../../archivos_h/materiales/madera.h"
#include "../../archivos_h/constantes.h"

using namespace std;

Madera::Madera(){
    nombre = MADERA;
    cantidad = CANTIDAD_MAX_MADERA_GENERADA;
}

Madera::Madera(int cantidad_inventario){
    nombre = MADERA;
    cantidad = cantidad_inventario;
}

void Madera::mostrar_estado(){
    cout << "Soy una Madera " << EMOJI_MADERA << ", y me encuentro en este casillero transitable." << endl;
}