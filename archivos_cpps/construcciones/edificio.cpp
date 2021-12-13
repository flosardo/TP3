#include "../../archivos_h/construcciones/edificio.h"

using namespace std;

Edificio::Edificio() {
    this -> nombre_del_edificio = VACIO;
    this -> materiales_necesarios = nullptr;
    this -> permitidos = 0;
    this -> nombre_material = VACIO;
    this -> cantidad_material_producido = 0;
    this -> coordenadas = nullptr;
    this -> afectado = false;
    this -> codigo_emoji = VACIO;
}

Edificio::Edificio(int piedra_necesaria, int madera_necesaria, int metal_necesario, int permitidos) {
    this -> nombre_del_edificio = VACIO;
    this -> nombre_material = VACIO;
    this -> cantidad_material_producido = 0;
    this -> permitidos = permitidos;
    this -> materiales_necesarios = new int[MAX_MATERIALES];
    this -> materiales_necesarios[POS_PIEDRA] = piedra_necesaria;
    this -> materiales_necesarios[POS_MADERA] = madera_necesaria;
    this -> materiales_necesarios[POS_METAL] = metal_necesario;
    this -> coordenadas = nullptr;
    this -> afectado = false;
    this -> codigo_emoji = VACIO;
}

Edificio::Edificio(int fila, int columna) {
    this -> nombre_del_edificio = VACIO;
    this -> materiales_necesarios = nullptr;
    this -> permitidos = 0;
    this -> nombre_material = VACIO;
    this -> cantidad_material_producido = 0;
    this -> coordenadas = new int[MAX_COORDENADAS];
    this -> coordenadas[INDICE_FILA] = fila;
    this -> coordenadas[INDICE_COLUMNA] = columna;
    this -> afectado = false;
    this -> codigo_emoji = VACIO;
}

string Edificio::obtener_nombre() {
    return this -> nombre_del_edificio;
}

int Edificio::obtener_cantidad_necesaria(string material) {
    int indice = POS_PIEDRA;
    if (material == MADERA)
        indice = POS_MADERA;
    else if (material == METAL)
        indice = POS_METAL;
    return this -> materiales_necesarios[indice];
}

int Edificio::obtener_permitidos() {
    return this -> permitidos;
}

string Edificio::obtener_tipo_material_producido() {
    return this -> nombre_material;
}

int Edificio::obtener_cantidad_de_material_producido() {
    return this -> cantidad_material_producido;
}

int* Edificio::obtener_coordenadas() {
    return this -> coordenadas;
}

string Edificio::obtener_codigo_emoji() {
    return this -> codigo_emoji;
}

void Edificio::establecer_nuevos_materiales(int nueva_piedra, int nueva_madera, int nuevo_metal) {
    this -> materiales_necesarios[POS_PIEDRA] = nueva_piedra;
    this -> materiales_necesarios[POS_MADERA] = nueva_madera;
    this -> materiales_necesarios[POS_METAL] = nuevo_metal;
}

bool Edificio::esta_afectado() {
    return this -> afectado;
}

void Edificio::cambiar_estado_afectado() {
    this -> afectado = !this -> afectado;
}

void Edificio::aumentar_material_producido() {}

Edificio::~Edificio() {
    if (this -> coordenadas)
        delete [] this -> coordenadas;
    if (this -> materiales_necesarios) 
        delete[] this -> materiales_necesarios;
    this -> coordenadas = nullptr;
    this -> materiales_necesarios = nullptr;
}