#include "../../archivos_h/casilleros/casillero_transitable.h"


using namespace std;

Casillero_transitable::Casillero_transitable(){
    material = nullptr;
    tipo_terreno = CAMINO;
}

Casillero_transitable::Casillero_transitable(Material* material){
    this -> material = material;
}

void Casillero_transitable::mostrar(){
    if (material == nullptr){
        cout << COLOR_DORADO << "══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð\n" << COLOR_POR_DEFECTO;
        cout << "Soy un casillero transitable " << EMOJI_CAMINO << " y me encuentro vacío." << endl;
        cout << COLOR_DORADO << "══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð\n" << COLOR_POR_DEFECTO;
    }else{
        material -> mostrar_estado();
    }
}

Material* Casillero_transitable::puntero_material(){
    return material;
}

void Casillero_transitable::agregar_material(Material* material_a_agregar){
    material = material_a_agregar;
}

void Casillero_transitable::limpiar_casillero(){
    material = nullptr;
}

char Casillero_transitable::nombre_casillero(){
    return material -> nombre_material();
}

Casillero_transitable::~Casillero_transitable(){
    delete material;
}