#ifndef _VERTICE_H_
#define _VERTICE_H_

#include <string>

class Vertice {
/*ATRIBUTOS*/
private:
    std::string nombre;

/*MÉTODOS*/
public:
    Vertice(std::string nombre);

    //post: obtiene el nombre del vertice
    std::string obtenerNombre();

    ~Vertice();
};

#endif //_VERTICE_H_