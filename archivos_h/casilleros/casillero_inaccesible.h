#ifndef _CASILLERO_INACCESIBLE_H_
#define _CASILLERO_INACCESIBLE_H_

#include "casillero.h"

class Casillero_inaccesible : public Casillero {
    
    public:
    
        /*
        *Post: Creará un objeto de tipo CasilleroInaccesible, dejando sus atributos cargados con valores por defecto.
        */
        Casillero_inaccesible();

        /*
        *Post: Mostrará lo que hay en el casillero.
        */
        void mostrar();

};

#endif //_CASILLERO_INACCESIBLE_H_