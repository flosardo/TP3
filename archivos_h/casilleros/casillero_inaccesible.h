#ifndef _CASILLERO_INACCESIBLE_H_
#define _CASILLERO_INACCESIBLE_H_

#include "casillero.h"

class CasilleroInaccesible : public Casillero{
    
    public:
    
        /*
        * Post: Creará un objeto de tipo CasilleroInaccesible, dejando sus atributos cargados con valores por defecto.
        */
        CasilleroInaccesible();

        /*
        * Post: Mostrará lo que hay en el casillero.
        */
        void mostrar();

};

#endif // _CASILLERO_INACCESIBLE_H_