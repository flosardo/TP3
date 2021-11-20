#include "../../archivos_h/materiales/material.h"

Material::Material(){
    this -> nombre = VACIO;
    this -> cantidad = 0;
}

char Material::nombre_material(){
    return nombre;
}

unsigned int Material::cantidad_material(){
    return cantidad;
}

void Material::modificar_cantidad(int cantidad_a_modificar){
    this -> cantidad += cantidad_a_modificar;
}

void Material::saludar(){}

Material::~Material(){}