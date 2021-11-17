#include "../../archivos_h/materiales/piedra.h"
using namespace std;

Piedra::Piedra(unsigned int cantidad_inventario){
    nombre = PIEDRA;
    cantidad = cantidad_inventario;
}

void Piedra::mostrar_estado(){
    cout << "Soy una piedra " << EMOJI_PIEDRA << " y me encuentro en el casillero consultado." << endl;
}

void Piedra::mostrar_material(){
    cout << "--> Material: piedra, cantidad: " << this -> cantidad << endl;
}