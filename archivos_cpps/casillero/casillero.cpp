#include "../../archivos_h/casilleros/casillero.h"

char Casillero::obtener_tipo_de_terreno(){
    return tipo_terreno;
}

Casillero::Casillero(){
    tipo_terreno = VACIO;
}

Edificio* Casillero::obtener_puntero_edificio(){
    return nullptr;
}

Material* Casillero::obtener_puntero_material(){
    return nullptr;
}

void Casillero::agregar_material(Material* material_a_agregar){}

void Casillero::agregar_edificio(Edificio* edificio_a_agregar){}

void Casillero::limpiar_casillero(){}

bool Casillero::esta_ocupado() {
    return false;
}

Casillero::~Casillero() {}