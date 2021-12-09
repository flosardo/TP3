#include "../archivos_h/mapa.h"

using namespace std;

Mapa::Mapa() {
    this -> mapa = nullptr;
    this -> cantidad_filas = 0;
    this -> cantidad_columnas = 0;
}

void Mapa::crear_mapa(int cantidad_filas, int cantidad_columnas) {
    this -> cantidad_filas = cantidad_filas;
    this -> cantidad_columnas = cantidad_columnas;
    this -> mapa = new Casillero**[this -> cantidad_filas];
    this -> inicializar_mapa();
}

void Mapa::inicializar_mapa() {
    for (int fila = 0; fila < this -> cantidad_filas; fila++) {
        this -> mapa[fila] = new Casillero*[this -> cantidad_columnas];
        for (int columna = 0; columna < this -> cantidad_columnas; columna++)
            mapa[fila][columna] = nullptr;
    }
}

int* Mapa::obtener_dimensiones() {
    int* dimensiones = new int[MAX_COORDENADAS];
    dimensiones[INDICE_FILA] = this -> cantidad_filas;
    dimensiones[INDICE_COLUMNA] = this -> cantidad_columnas;
    return dimensiones;
}

void Mapa::mostrar_simbologia(){
    cout << COLOR_DORADO << " ╔■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■╗" << endl;
    cout << " ■ " << COLOR_POR_DEFECTO << "SIMBOLOGIA " << COLOR_DORADO << setw(110) << "■" << endl; 
    cout << " ■ " << COLOR_POR_DEFECTO << "1. Convenciones Casillero Construible: " << COLOR_DORADO << setw(82) << "■" << endl; 
    cout << " ■ " << COLOR_POR_DEFECTO << "\t->" << NOMBRE_ASERRADERO << ": " << EMOJI_ASERRADERO << VACIO << NOMBRE_FABRICA << ": "  << EMOJI_FABRICA << VACIO
                                       << NOMBRE_ESCUELA << ": " << EMOJI_ESCUELA << VACIO << NOMBRE_OBELISCO << ": " << EMOJI_OBELISCO << VACIO << NOMBRE_MINA << ": " << EMOJI_MINA << VACIO
                                       << NOMBRE_PLANTA_ELECTRICA << ": " << EMOJI_PLANTA_ELECTRICA << VACIO << "Terreno: " << COLOR_TERRENO << COLOR_POR_DEFECTO << setw(25) << COLOR_DORADO << "■" << endl;
    cout << " ■ " << COLOR_POR_DEFECTO << "2. Convenciones Casillero Inaccesible: " << COLOR_DORADO << setw(82) << "■" << endl;                              
    cout << " ■ " << COLOR_POR_DEFECTO << "\t-> Lago: " << COLOR_LAGO << COLOR_DORADO << setw(105) << "■" << endl;                     
    cout << " ■ " << COLOR_POR_DEFECTO << "3. Convenciones Casillero Transitable: " << COLOR_DORADO << setw(82) << "■" << endl;
    cout << " ■ " << COLOR_POR_DEFECTO << "\t-> Camino: " << COLOR_CAMINO << VACIO << PIEDRA << ": "  << EMOJI_PIEDRA << VACIO << MADERA << ": " << EMOJI_MADERA << VACIO
                                       << METAL << ": " << EMOJI_METAL << VACIO << ANDYCOINS << ": " << EMOJI_ANDYCOINS << COLOR_DORADO << setw(71) << "■" << endl;
    cout << " ╚■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■╝" << COLOR_POR_DEFECTO << endl;
}

void Mapa::inicializar_casillero(char terreno, int fila, int columna) {
    if (terreno == LAGO)
        this -> mapa[fila][columna] = new Casillero_inaccesible();
    else if (terreno == TERRENO)
        this -> mapa[fila][columna] = new Casillero_construible();
    else
        this -> mapa[fila][columna] = new Casillero_transitable();
}

bool Mapa::se_ubico_material(Material* material, int fila, int columna) {
    bool coordenada_valida = !this -> esta_ocupado(fila, columna) 
                            && this -> obtener_tipo_casillero(fila, columna) != LAGO && this -> obtener_tipo_casillero(fila, columna) != TERRENO;
    if (coordenada_valida)
        this -> mapa[fila][columna] -> agregar_material(material);
    else
        cout << COLOR_ROJO << "No se pudo posicionar al material en las coordenadas ingresadas, intente nuevamente" << COLOR_POR_DEFECTO << endl;
    return coordenada_valida;
}

bool Mapa::se_ubico_edificio(Edificio* edificio, int fila, int columna) {
    bool coordenada_valida = !this -> esta_ocupado(fila, columna) && this -> obtener_tipo_casillero(fila, columna) == TERRENO;
    if (coordenada_valida)
        this -> mapa[fila][columna] -> agregar_edificio(edificio);
    else
        cout << COLOR_ROJO << "No se pudo posicionar el edificio en las coordenadas ingresadas, intente nuevamente" << COLOR_POR_DEFECTO << endl;
    return coordenada_valida;
}

bool Mapa::se_ubico_jugador(Jugador* jugador, int fila, int columna) {
    bool coordenada_valida = !this -> esta_ocupado(fila, columna) && this -> obtener_tipo_casillero(fila, columna) != LAGO;
    if (coordenada_valida)
        this -> mapa[fila][columna] -> agregar_jugador(jugador);
    else
        cout << COLOR_ROJO << "No se pudo posicionar al jugador en las coordenadas ingresadas, intente nuevamente" << COLOR_POR_DEFECTO << endl;
    return coordenada_valida;
}

char Mapa::obtener_tipo_casillero(int fila, int columna) {
    return this -> mapa[fila][columna] -> obtener_tipo_de_terreno();
}

void Mapa::consultar_coordenada(int fila, int columna) {
    if (!this -> coordenadas_fuera_de_rango(fila, columna))
        this -> mapa[fila][columna] -> mostrar();
    else
        cout << COLOR_ROJO << "Oops!, intentaste acceder a una coordenada fuera de rango, intenta nuevamente" << COLOR_POR_DEFECTO << endl;
}

bool Mapa::esta_ocupado(int fila, int columna) {
    return this -> mapa[fila][columna] -> esta_ocupado();
}

bool Mapa::coordenadas_fuera_de_rango(int fila, int columna) {
    bool esta_fuera_de_rango = (fila < 0 || fila >= cantidad_filas) || (columna < 0 || columna >= cantidad_columnas);
    if (esta_fuera_de_rango)
        cout << COLOR_ROJO << "Oops!, intentaste acceder a una coordenada fuera de rango, intenta nuevamente" << COLOR_POR_DEFECTO << endl;
    return esta_fuera_de_rango;
}

bool Mapa::es_posible_insertar_materiales(int cantidad_a_insertar) {
    int fila = 0;
    int columna;
    while (cantidad_a_insertar > 0 && fila < this -> cantidad_filas) {
        columna = 0;
        while (cantidad_a_insertar > 0 && columna < this -> cantidad_columnas) {
            if (this -> obtener_tipo_casillero(fila, columna) != TERRENO && this -> obtener_tipo_casillero(fila, columna) != LAGO && !this -> esta_ocupado(fila, columna))
                cantidad_a_insertar--;
            columna++;
        }
        fila++;
    }

    return cantidad_a_insertar == 0;
}

int* Mapa::generar_coordenadas_validas() {
    int* coordenadas_validas = nullptr;
    while (!coordenadas_validas) {
        int fila = (rand() % this -> cantidad_filas);
        int columna = (rand() % this -> cantidad_columnas);
        if (this -> obtener_tipo_casillero(fila, columna) != TERRENO && this -> obtener_tipo_casillero(fila, columna) != LAGO && !this -> esta_ocupado(fila, columna)) {
            coordenadas_validas = new int[MAX_COORDENADAS];
            coordenadas_validas[INDICE_FILA] = fila;
            coordenadas_validas[INDICE_COLUMNA] = columna;
        }
    }

    return coordenadas_validas;
}

void Mapa::liberar_posicion(int fila, int columna) {
    this -> mapa[fila][columna] -> limpiar_casillero();
}

Edificio* Mapa::obtener_edificio(int fila, int columna) {
    Edificio* edificio = nullptr;
    if(!this -> mapa[fila][columna] -> obtener_puntero_jugador())
        edificio = this -> mapa[fila][columna] -> obtener_puntero_edificio();
    return edificio;
}

Material* Mapa::obtener_material(int fila, int columna) {
    Material* material = nullptr;
    if(!this -> mapa[fila][columna] -> obtener_puntero_jugador())
        material = this -> mapa[fila][columna] -> obtener_puntero_material();
    return material;
}

void Mapa::mostrar_mapa() {
    cout << endl;
    this -> mostrar_simbologia();
    cout << endl;
    cout << "   ";
    for (int i = 0; i < this -> cantidad_columnas; i++) {
        cout << i << "   ";
    }
    cout << endl;
    for (int fila = 0; fila < this -> cantidad_filas; fila++) { 
        cout << ' ' << fila << ' ';
        for (int columna = 0; columna < this -> cantidad_columnas; columna++) {
            if (!this -> esta_ocupado(fila, columna))
                cout << mapa[fila][columna] -> obtener_color() << setw(6);
            else if (this -> mapa[fila][columna] -> obtener_puntero_jugador())
                cout << mapa[fila][columna] -> obtener_color() + mapa[fila][columna] -> obtener_puntero_jugador() -> obtener_codigo_emoji() << setw(4);
            else if (this -> obtener_tipo_casillero(fila, columna) == TERRENO) 
                cout << this -> mapa[fila][columna] -> obtener_color() + this -> mapa[fila][columna] -> obtener_puntero_edificio() -> obtener_codigo_emoji() << setw(4);
            else 
                cout << this -> mapa[fila][columna] -> obtener_color() + this -> mapa[fila][columna] -> obtener_puntero_material() -> obtener_codigo_emoji() << setw(4);

            cout << COLOR_POR_DEFECTO << setw(2) << VACIO;
        }
        cout << endl << endl;
    }
}

Mapa::~Mapa() {
    for (int fila = 0; fila < this -> cantidad_filas; fila++) {
        for (int columna = 0; columna < this -> cantidad_columnas; columna++)
            delete this -> mapa[fila][columna];

        delete [] this -> mapa[fila];
    }
    delete [] this -> mapa;
    this -> mapa = nullptr;
}