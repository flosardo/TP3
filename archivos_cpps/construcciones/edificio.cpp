#include "../../archivos_h/construcciones/edificio.h"

Edificio::Edificio() {
    this -> jugador = VACIO;
    this -> nombre_edificio = VACIO;
    this -> nombre_material = VACIO;
    this -> cantidad_material_producido = 0;
    this -> piedra_necesaria = 0;
    this -> metal_necesario = 0;
    this -> madera_necesaria = 0;
    this -> afectado = false;
}

Edificio::Edificio(char jugador, unsigned int piedra_necesaria, unsigned int metal_necesario, unsigned int madera_necesaria) {
    this -> jugador = jugador;
    this -> piedra_necesaria = piedra_necesaria;
    this -> metal_necesario = metal_necesario;
    this -> madera_necesaria = madera_necesaria;
    this -> afectado = false;
}

char Edificio::obtener_nombre_del_edificio() {
    return nombre_edificio;
}

char Edificio::obtener_nombre_del_material() {
    return nombre_material;
}

unsigned int Edificio::obtener_cantidad_de_material_producido() {
    return cantidad_material_producido;
}

unsigned int Edificio::obtener_cantidad_madera_necesaria() {
    return piedra_necesaria;
}

unsigned int Edificio::obtener_cantidad_metal_necesario() {
    return metal_necesario;
}

unsigned int Edificio::obtener_cantidad_piedra_necesaria() {
    return piedra_necesaria;
}

char Edificio::obtener_jugador() {
    return jugador;
}

bool Edificio::esta_afectado() {
    return afectado;
}

void Edificio::cambiar_estado_afectado() {
    afectado = !afectado;
}

Edificio::~Edificio() {};