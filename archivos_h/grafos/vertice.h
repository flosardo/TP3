#ifndef _VERTICE_H_
#define _VERTICE_H_

#include <string>

class Vertice {

    private:

        std::string nombre;

    public:
    
        Vertice(std::string nombre);

        //post: obtiene el nombre del vertice
        std::string obtener_nombre();

        ~Vertice();
    
};

#endif //_VERTICE_H_