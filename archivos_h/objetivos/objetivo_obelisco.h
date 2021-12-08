#ifndef _OBJETIVO_OBELISCO_H_
#define _OBJETIVO_OBELISCO_H_

#include "objetivo.h"

class Objetivo_obelisco: public Objetivo {

    private:
    
        bool obelisco_construido;

    public:

        /*
        *Post: Construira un objeto de tipo Objetivo_obelisco, con sus valores por defecto.
        */
        Objetivo_obelisco();

        /*
        *Post: Mostrará por consola el progreso.
        */
        void mostrar_progreso();

        /*
        *Post: obtenerá true si se construyo un obelisco, false en caso contrario.
        */
        bool se_cumplio_el_objetivo(std::string nombre);
        
};

#endif //_OBJETIVO_OBELISCO_H_