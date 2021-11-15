#ifndef _OBELISCO_H_
#define _OBELISCO_H_

#include "../edificio.h"

class Obelisco : public Edificio{

public:
    /*
        * Post: Creará un objeto de tipo Obelisco, dejandolo con sus atributos cargados con valores por defecto.
        */
    Obelisco();

    /*
        * Post: Creará un objeto de tipo Obelisco, usando los parámetros que recibe.
        */
    Obelisco(int piedra_necesaria, int metal_necesario, int madera_necesaria);
};

#endif // _OBELISCO_H_