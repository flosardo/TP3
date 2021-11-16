#include "../../archivos_h/casilleros/casillero.h"

char Casillero::tipo_de_terreno(){
    return tipo_terreno;
}

Casillero::Casillero(){
    tipo_terreno = VACIO;
}

Edificio* Casillero::puntero_edificio(){
    return nullptr;
}

Material* Casillero::puntero_material(){
    return nullptr;
}

void Casillero::agregar_material(Material* material_a_agregar){}

void Casillero::agregar_edificio(Edificio* edificio_a_agregar){}

void Casillero::limpiar_casillero(){}

char Casillero::nombre_casillero(){
    return VACIO;
}

int Casillero::cantidad_material_producido(){
    return MIN_VALOR_MATERIAL;
}

Casillero::~Casillero(){}