#ifndef _CARGAR_UBICACIONES_H_
#define _CARGAR_UBICACIONES_H_
#include <fstream>
#include "../andypolis.h"

class Cargar_ubicaciones {
    private:
        std::string archivo_ruta;
    public:
        Cargar_ubicaciones();

        bool carga_ubicaciones(Andypolis* andypolis);
 
        void guardar_ubicaciones();
        
};

#endif // _CARGAR_UBICACIONES_H_