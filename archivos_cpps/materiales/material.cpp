#include "../../archivos_h/materiales/material.h"

Material::Material(){
    this -> nombre = VACIO;
    this -> cantidad = 0;
}

char Material::obtener_nombre_material() {
    return this -> nombre;
}

int Material::cantidad_material() {
    return this -> cantidad;
}

void Material::modificar_cantidad(int cantidad_a_modificar) {
    this -> cantidad += cantidad_a_modificar;
}

void Material::saludar() {}

Material::~Material() {}