#include "../../archivos_h/casilleros/casillero_construible.h"

using namespace std;

Casillero_construible::Casillero_construible(){
    edificio = nullptr;
    tipo_terreno = TERRENO;
}

Casillero_construible::Casillero_construible(Edificio* edificio){
    this -> edificio = edificio;
}

void Casillero_construible::mostrar(){
    if(edificio == nullptr){
        cout << COLOR_DORADO << "══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð\n" << COLOR_POR_DEFECTO;
        cout << "Soy un terreno " << EMOJI_TERRENO << ", un casillero construible y me encuentro vacío." << endl;
        cout << COLOR_DORADO << "══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð\n" << COLOR_POR_DEFECTO;

    }else{
        string nombre = NOMBRE_ASERRADERO;

        if(edificio -> nombre_del_edificio() == ESCUELA)
            nombre = NOMBRE_ESCUELA;
        else if(edificio -> nombre_del_edificio() == PLANTA_ELECTRICA)
            nombre = NOMBRE_PLANTA_ELECTRICA;
        else if(edificio -> nombre_del_edificio() == FABRICA)
            nombre = NOMBRE_FABRICA;
        else if(edificio -> nombre_del_edificio() == MINA)
            nombre = NOMBRE_MINA;
        else if(edificio -> nombre_del_edificio() == OBELISCO)
            nombre = NOMBRE_OBELISCO;

        cout << COLOR_DORADO << "══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð\n" << COLOR_POR_DEFECTO;
        cout << "Soy un terreno " << EMOJI_TERRENO << ", un casillero construible y no me encuentro vacío." << endl;
        cout << "Soy una " << nombre << ", y me encuentro en este casillero." << endl;
        cout << COLOR_DORADO << "══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð\n" << COLOR_POR_DEFECTO;
    }
}

void Casillero_construible::agregar_edificio(Edificio* edificio_a_construir){
    edificio = edificio_a_construir;
}

Edificio* Casillero_construible::puntero_edificio(){
    return edificio;
}

void Casillero_construible::limpiar_casillero(){
    edificio = nullptr; 
}

char Casillero_construible::nombre_casillero(){
    return edificio -> nombre_del_edificio();
}

int Casillero_construible::cantidad_material_producido(){
    return edificio -> cantidad_de_material_producido();
}

Casillero_construible::~Casillero_construible(){
    delete edificio;
}