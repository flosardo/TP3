#include "../../archivos_h/construcciones/edificio.h"

/*
 * EL DESTRUCTOR ESTA AL PEDO PORQUE NUNCA PEDIMOS MEMORIA PARA NINGUNO DE SUS ATRIBUTOS
*/
using namespace std;

Edificio::Edificio() {
    this -> jugador = VACIO;
    this -> nombre_del_edificio = VACIO;
    this -> nombre_material = VACIO;
    this -> codigo_emoji = VACIO;
    this -> cantidad_material_producido = 0;
    //this -> piedra_necesaria = 0;
    //this -> metal_necesario = 0;
    //this -> madera_necesaria = 0;
    this -> afectado = false;
}

Edificio::Edificio(unsigned int piedra_necesaria, unsigned int madera_necesaria, unsigned int metal_necesario, unsigned int permitidos) {
    this -> permitidos = permitidos;
    //this -> piedra_necesaria = piedra_necesaria;
    //this -> madera_necesaria = madera_necesaria;
    //this -> metal_necesario = metal_necesario;
    this -> materiales_necesarios = new unsigned int[3];
    this -> materiales_necesarios[0] = piedra_necesaria;
    this -> materiales_necesarios[1] = madera_necesaria;
    this -> materiales_necesarios[2] = metal_necesario;
    this -> codigo_emoji = VACIO;
    this -> afectado = false;
}

unsigned int* Edificio::obtener_materiales_necesarios() {
    return this -> materiales_necesarios;
}

string Edificio::obtener_codigo_emoji() {
    return this -> codigo_emoji;
}

string Edificio::obtener_nombre_del_edificio() {
    return this -> nombre_del_edificio;
}

string Edificio::obtener_nombre_del_material() {
    return this -> nombre_material;
}

unsigned int Edificio::obtener_cantidad_de_material_producido() {
    return this -> cantidad_material_producido;
}


char Edificio::obtener_jugador() {
    return this -> jugador;
}

bool Edificio::esta_afectado() {
    return this -> afectado;
}

void Edificio::cambiar_estado_afectado() {
    this -> afectado = !this -> afectado;
}

Edificio::~Edificio() {
    if (this -> materiales_necesarios) {
        delete[] this -> materiales_necesarios;
    }
    this -> materiales_necesarios = nullptr;
}