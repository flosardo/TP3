#include "../archivos_h/programa/programa.h"

using namespace std;

int main() {
    srand((unsigned) time(NULL));
    Programa programa;
    programa.empezar();
    programa.finalizar();
    return 0;
}