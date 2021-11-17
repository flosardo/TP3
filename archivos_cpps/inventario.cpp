#include "../archivos_h/inventario.h"

using namespace std;

Inventario::Inventario() {
    this -> cantidad_materiales = 0;
    this -> inventario = new Material* [MATERIALES_DISPONIBLES];
}

int Inventario::obtener_cantidad_materiales(){
    return this->cantidad_materiales;
}

Material** Inventario::obtener_inventario(){
    return this->inventario;
}

int Inventario::posicion_del_material(char material) {
    int indice = 0;
    while (this->inventario[indice]->nombre_material() != material) {
        indice++;
    }
    return indice;
}

void Inventario::mostrar_inventario() {
    for (int i = 0; i < this->cantidad_materiales; i++) {
        this -> inventario[i] -> mostrar_material();
        cout << COLOR_MARRON << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
    }
}

Inventario::~Inventario() {
    delete[] this->inventario;
    this->inventario = 0;
}