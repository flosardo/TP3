#include "../archivos_h/material.h"

const char VACIO = ' ';


Material::Material(){
    nombre = VACIO;
    cantidad = 0;
}

char Material::devolver_nombre_material(){
    return nombre;
}

int Material::devolver_cantidad_material(){
    return cantidad;
}

void Material::aumentar_cantidad(int cantidad_a_aumentar){
    cantidad += cantidad_a_aumentar;
}

void Material::reducir_cantidad(int cantidad_a_reducir){
    cantidad -= cantidad_a_reducir;
}

void Material::mostrar_estado(){}

Material::~Material(){}