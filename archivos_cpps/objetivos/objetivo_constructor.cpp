#include "../../archivos_h/objetivos/objetivo_constructor.h"

using namespace std;

Objetivo_constructor::Objetivo_constructor() {
    this -> nombre = NOMBRE_OBJETIVO_CONSTRUCTOR;
    for (int i = 0; i < MAX_EDIFICIOS_DISPONIBLES-1; i++)
        construidos[i] = false;
}

bool Objetivo_constructor::se_cumplio_el_objetivo(Jugador* jugador) {
    Edificio** edificios_construidos = jugador -> obtener_edificios_construidos();
    int cantidad_edificios_construidos = jugador -> obtener_construidos();
    string nombre_edificio;
    for (int i = 0; i < cantidad_edificios_construidos; i++) {
        nombre_edificio = edificios_construidos[i] -> obtener_nombre();
        this -> cambiar_estado_construido(nombre_edificio);
    }
    int i = 0;
    bool cumplido = true;
    while (cumplido && i < MAX_EDIFICIOS_DISPONIBLES) {
        cumplido = this -> construidos[i];
        i++;
    }
    return cumplido;
}

void Objetivo_constructor::mostrar_progreso() {
    if (!this -> construidos[POS_PLANTA_ELECTRICA])
        cout << "Falta una " << PLANTA_ELECTRICA << " por construir" << endl;
    if (!this -> construidos[POS_ASERRADERO])
        cout << "Falta un " << NOMBRE_ASERRADERO << " por construir" << endl;
    if (!this -> construidos[POS_MINA_ORO])
        cout << "Falta una " << NOMBRE_MINA_ORO << " por construir" << endl;
    if (!this -> construidos[POS_MINA])
        cout << "Falta una " << NOMBRE_MINA << " por construir" << endl;
    if (!this -> construidos[POS_ESCUELA])
        cout << "Falta una " << NOMBRE_ESCUELA << " por construir" << endl;
    if (!this -> construidos[POS_FABRICA])
        cout << "Falta una " << NOMBRE_FABRICA << " por construir" << endl;

}

void Objetivo_constructor::cambiar_estado_construido(string nombre) {
    if (nombre == PLANTA_ELECTRICA)
        this -> construidos[POS_PLANTA_ELECTRICA] = true;
    else if (nombre == NOMBRE_ASERRADERO)
        this -> construidos[POS_ASERRADERO] = true;
    else if (nombre == NOMBRE_MINA_ORO)
        this -> construidos[POS_MINA_ORO] = true;
    else if (nombre == NOMBRE_MINA)
        this -> construidos[POS_MINA] = true;
    else if (nombre == NOMBRE_ESCUELA)
        this -> construidos[POS_ESCUELA] = true;
    else if (nombre == NOMBRE_FABRICA)
        this -> construidos[POS_FABRICA] = true;
}