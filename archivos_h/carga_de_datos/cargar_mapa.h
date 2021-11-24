#ifndef _CARGAR_MAPA_H_
#define _CARGAR_MAPA_H_
#include <fstream>
#include "../andypolis.h"

class Cargar_mapa {
    private:
        std::string archivo_ruta;

    public:
        Cargar_mapa();

        bool carga_mapa(Andypolis* andypolis, Mapa mapa);
};

#endif // _CARGAR_UBICACIONES_H_