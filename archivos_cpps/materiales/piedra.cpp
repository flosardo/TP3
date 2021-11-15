#include "../../archivos_h/materiales/piedra.h" 
#include "../../archivos_h/constantes.h"

using namespace std;


Piedra::Piedra(){}

Piedra::Piedra(int cantidad_inventario){
    nombre = PIEDRA;
    cantidad = cantidad_inventario;
}

void Piedra::mostrar_estado(){
    cout << "Soy una piedra " << EMOJI_PIEDRA << " y me encuentro en este casillero transitable." << endl;
}