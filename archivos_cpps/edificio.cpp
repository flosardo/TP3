#include "../archivos_h/edificio.h"


Edificio::Edificio(){
    nombre_edificio = VACIO;
    nombre_material = VACIO;
    cantidad_material_producido = 0;
    piedra_necesaria = 0;
    metal_necesario = 0;
    madera_necesaria = 0;
}

Edificio::Edificio(int piedra_necesaria, int metal_necesario, int madera_necesaria){
    this -> piedra_necesaria = piedra_necesaria;
    this -> metal_necesario = metal_necesario;
    this -> madera_necesaria = madera_necesaria;
}

char Edificio::nombre_del_edificio(){
    return nombre_edificio;
}

char Edificio::nombre_del_material(){
    return nombre_material;
}

int Edificio::cantidad_de_material_producido()
{
    return cantidad_material_producido;
}

int Edificio::cantidad_madera_necesaria()
{
    return piedra_necesaria;
}

int Edificio::cantidad_metal_necesario(){
    return metal_necesario;
}

int Edificio::cantidad_piedra_necesaria(){
    return piedra_necesaria;
}