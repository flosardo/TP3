#include "../../archivos_h/materiales/madera.h"
using namespace std;

Madera::Madera(unsigned int cantidad_inventario){
    nombre = MADERA;
    cantidad = cantidad_inventario;
}

void Madera::mostrar_estado(){
    cout << "Soy una Madera " << EMOJI_MADERA << ", y me encuentro en este casillero transitable." << endl;
}