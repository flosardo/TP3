#include "../../archivos_h/materiales/material.h"

Material::Material(){
    nombre = VACIO;
    cantidad = 0;
}

char Material::nombre_material(){
    return nombre;
}

unsigned int Material::cantidad_material(){
    return cantidad;
}

void Material::aumentar_cantidad(unsigned int cantidad_a_aumentar){
    cantidad += cantidad_a_aumentar;
}

void Material::reducir_cantidad(unsigned int cantidad_a_reducir){
    cantidad -= cantidad_a_reducir;
}

void Material::saludar(){}

Material::~Material(){}