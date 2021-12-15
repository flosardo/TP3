#include "../archivos_h/inventario.h"

using namespace std;

Inventario::Inventario() {
    this -> inventario = new Material* [MATERIALES_DISPONIBLES];
    this -> cantidad_materiales = 0;
}

Material** Inventario::obtener_inventario() {
    return this -> inventario;
}

int Inventario::obtener_cantidad_materiales() {
    return this -> cantidad_materiales;
}

Material* Inventario::obtener_material(string material_pedido) {
    Material* material_a_obtener = nullptr;
    int indice = 0;
    do {
        material_a_obtener = this -> inventario[indice];
        indice++;
    } while (material_a_obtener -> obtener_nombre_material() != material_pedido && indice < this -> cantidad_materiales);
    return material_a_obtener;
}

void Inventario::agregar_material(Material* material) {
    this -> inventario[this -> cantidad_materiales] = material;
    this -> cantidad_materiales++;
}

void Inventario::modificar_cantidad_material(string material_a_modificar, int cantidad) {
    Material* material = this -> obtener_material(material_a_modificar);
    material -> modificar_cantidad(cantidad);
    material = nullptr;
}

void Inventario::mostrar_inventario() {
    for (int i = 0; i < this -> cantidad_materiales; i++) {
        this -> inventario[i] -> mostrar_material();
        cout << COLOR_MARRON << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
    }
}

Inventario::~Inventario() {
    for (int i = 0; i < this -> cantidad_materiales; i++) {
        delete this -> inventario[i];
    }

    delete [] this -> inventario;
    this -> inventario = nullptr;
}