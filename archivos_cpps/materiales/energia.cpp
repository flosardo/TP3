#include "../../archivos_h/materiales/energia.h"

using namespace std;

Energia::Energia() {
    this -> nombre = ENERGIA;
    this -> cantidad = ENERGIA_INICIAL;
    this -> codigo_emoji = EMOJI_ENERGIA;
}

Energia::Energia(int cantidad_energia) {
    this -> nombre = ENERGIA;
    this -> cantidad = cantidad_energia;
    this -> codigo_emoji = EMOJI_ENERGIA;
}

int Energia::obtener_energia_actual() {
    return this -> cantidad;
}

void Energia::modificar_cantidad(int cantidad_a_modificar) {
    this -> cantidad += cantidad_a_modificar;
    this -> cantidad %= (MAXIMO_ENERGIA + 1);
}

void Energia::mostrar_material() {
    cout << "--> Material: energia, cantidad: " << this -> cantidad << endl;
}