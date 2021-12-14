#ifndef _VERTICE_H_
#define _VERTICE_H_

#include <string>

class Vertice {

    private:
        
        std::string nombre;

    public:
        
        /*
        *Pre: Creará un objeto de tipo Vertice con los parámetros recibidos.
        */
        Vertice(std::string nombre);

        /*
        *Post: Obtiene el nombre del vertice.
        */
        std::string obtener_nombre();
    
        /*
        *Post: Liberará la memoria utilizada por la clase.
        */
        ~Vertice();
        
};

#endif //_VERTICE_H_