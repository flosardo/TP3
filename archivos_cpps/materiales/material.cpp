#include "../../archivos_h/materiales/material.h"

using namespace std;

Material::Material(){
    this -> nombre = VACIO;
    this -> codigo_emoji = VACIO;
    this -> cantidad = 0;
}

string Material::obtener_nombre_material() {
    return this -> nombre;
}

string Material::obtener_codigo_emoji() {
    return this -> codigo_emoji;
}

int Material::cantidad_material() {
    return this -> cantidad;
}

void Material::modificar_cantidad(int cantidad_a_modificar) {
    this -> cantidad += cantidad_a_modificar;
}

void Material::saludar() {}