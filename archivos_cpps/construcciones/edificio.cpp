#include "../../archivos_h/construcciones/edificio.h"

Edificio::Edificio(){
    jugador = VACIO;
    nombre_edificio = VACIO;
    nombre_material = VACIO;
    cantidad_material_producido = 0;
    piedra_necesaria = 0;
    metal_necesario = 0;
    madera_necesaria = 0;
    afectado = false;
}

Edificio::Edificio(char jugador, unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria){
    this -> jugador = jugador;
    this -> piedra_necesaria = piedra_necesaria;
    this -> metal_necesario = metal_necesario;
    this -> madera_necesaria = madera_necesaria;
    afectado = false;
}

char Edificio::nombre_del_edificio(){
    return nombre_edificio;
}

char Edificio::nombre_del_material(){
    return nombre_material;
}

unsigned int Edificio::cantidad_de_material_producido(){
    return cantidad_material_producido;
}

unsigned int Edificio::cantidad_madera_necesaria(){
    return piedra_necesaria;
}

unsigned int Edificio::cantidad_metal_necesario(){
    return metal_necesario;
}

unsigned int Edificio::cantidad_piedra_necesaria(){
    return piedra_necesaria;
}

char Edificio::obtener_jugador(){
    return jugador;
}

bool Edificio::esta_afectado(){
    return afectado;
}

void Edificio::cambiar_estado_afectado(){
    afectado = !afectado;
}