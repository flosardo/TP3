#include "../../archivos_h/materiales/material.h"

using namespace std;

Material::Material() {
    this -> nombre = VACIO;
    this -> cantidad = 0;
    this -> codigo_emoji = VACIO;
}

string Material::obtener_nombre_material() {
    return this -> nombre;
}

int Material::obtener_cantidad() {
    return this -> cantidad;
}

string Material::obtener_codigo_emoji() {
    return this -> codigo_emoji;
}

void Material::modificar_cantidad(int cantidad_a_modificar) {
    this -> cantidad += cantidad_a_modificar;
}

void Material::saludar() {}

Material::~Material() {}