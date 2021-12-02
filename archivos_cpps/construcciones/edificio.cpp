#include "../../archivos_h/construcciones/edificio.h"

/*
 * EL DESTRUCTOR ESTA AL PEDO PORQUE NUNCA PEDIMOS MEMORIA PARA NINGUNO DE SUS ATRIBUTOS
*/
using namespace std;

Edificio::Edificio() {
    this -> columna = -1;
    this -> fila = -1;
    this -> nombre_del_edificio = VACIO;
    this -> nombre_material = VACIO;
    this -> codigo_emoji = VACIO;
    this -> cantidad_material_producido = 0;
    this -> materiales_necesarios = nullptr;
    this -> afectado = false;
}

Edificio::Edificio(unsigned int piedra_necesaria, unsigned int madera_necesaria, unsigned int metal_necesario, unsigned int permitidos) {
    this -> permitidos = permitidos;
    this -> materiales_necesarios = new unsigned int[MAX_MATERIALES];
    this -> materiales_necesarios[POS_PIEDRA] = piedra_necesaria;
    this -> materiales_necesarios[POS_MADERA] = madera_necesaria;
    this -> materiales_necesarios[POS_METAL] = metal_necesario;
    this -> codigo_emoji = VACIO;
    this -> afectado = false;
}

Edificio::Edificio(unsigned int fila, unsigned int columna) {
    this -> fila = fila;
    this -> columna = columna;
    this -> permitidos = 0;
    this -> materiales_necesarios = nullptr;
    this -> codigo_emoji = VACIO;
    this -> afectado = false;
}

void Edificio::establecer_nuevos_materiales(unsigned int nueva_piedra, unsigned int nueva_madera, unsigned int nuevo_metal){
    this -> materiales_necesarios[POS_PIEDRA] = nueva_piedra;
    this -> materiales_necesarios[POS_MADERA] = nueva_madera;
    this -> materiales_necesarios[POS_METAL] = nuevo_metal;
}

unsigned int* Edificio::obtener_materiales_necesarios() {
    return this -> materiales_necesarios;
}

unsigned int Edificio::obtener_fila(){
    return this -> fila;
}

unsigned int Edificio::obtener_columna(){
    return this -> columna;
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