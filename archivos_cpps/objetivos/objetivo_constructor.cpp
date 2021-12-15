#include "../../archivos_h/objetivos/objetivo_constructor.h"

using namespace std;

Objetivo_constructor::Objetivo_constructor() {
    this -> nombre = NOMBRE_OBJETIVO_CONSTRUCTOR;
    this -> se_cumplio = false;
    for (int i = 0; i < MAX_EDIFICIOS_DISPONIBLES; i++)
        this -> construidos[i] = false;
}

bool Objetivo_constructor::se_cumplio_objetivo(Jugador* jugador) {
    if (!this -> se_cumplio) {
        Edificio** edificios_construidos = jugador -> obtener_edificios_construidos();
        int cantidad_edificios_construidos = jugador -> obtener_construidos();
        for (int i = 0; i < cantidad_edificios_construidos; i++) {
            this -> cambiar_estado_construido(edificios_construidos[i] -> obtener_nombre());
        }
        edificios_construidos = nullptr;
        int i = 0;
        this -> se_cumplio = true;
        while (this -> se_cumplio && i < MAX_EDIFICIOS_DISPONIBLES) {
            this -> se_cumplio = this -> construidos[i];
            i++;
        }
    }
    return this -> se_cumplio;
}

void Objetivo_constructor::mostrar_progreso() {
    cout << this -> nombre;
    if (this -> se_cumplio)
       cout << VACIO << EMOJI_CHECK << endl;
    else {
        cout << endl;
        if (!this -> construidos[POS_PLANTA_ELECTRICA]) {
            cout << COLOR_DORADO << setw(3) << "|-> " << COLOR_POR_DEFECTO << EMOJI_PLANTA_ELECTRICA << VACIO
            << "Falta construir una planta electrica, para dañar la capa de ozono" << endl;
        }
            
        if (!this -> construidos[POS_ASERRADERO]) {
            cout << COLOR_DORADO << setw(3) << "|-> " << COLOR_POR_DEFECTO << EMOJI_ASERRADERO << VACIO
            << "Falta construir un aserradero, para dañar más arboles" << endl;
        }
            
        if (!this -> construidos[POS_MINA_ORO]) {
            cout << COLOR_DORADO << setw(3) << "|-> " << COLOR_POR_DEFECTO << EMOJI_MINA_ORO << VACIO
            << "Falta construir una mina de oro, para estar full de guita paa " << endl;
        }
        
        if (!this -> construidos[POS_MINA]) {
            cout << COLOR_DORADO << setw(3) << "|-> " << COLOR_POR_DEFECTO << EMOJI_MINA << VACIO
            << "Falta construir una mina de piedra, para ser full niño rata." << endl;
        }
        
        if (!this -> construidos[POS_ESCUELA]) {
            cout << COLOR_DORADO << setw(3) << "|-> " << COLOR_POR_DEFECTO << EMOJI_ESCUELA << VACIO
            << "Falta construir una escuela, para que te puedas educar." << endl;
        }
        
        if (!this -> construidos[POS_FABRICA]) {
            cout << COLOR_DORADO << setw(3) << "|-> " << COLOR_POR_DEFECTO << EMOJI_FABRICA << VACIO
            << "Falta construir una fábrica, para esclavizar trabajadores en negro." << endl;
        }

    }
    cout << endl;
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