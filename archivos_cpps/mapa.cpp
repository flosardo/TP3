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

void Mapa::mostrar_simbologia() {
    string borde = COLOR_DORADO + " ■" + COLOR_POR_DEFECTO;
    cout << COLOR_DORADO; 
    cout << " ╔■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■╗" << endl;
    cout << borde << " SIMBOLOGIA "                                                                                                    << setw(119) << borde << endl; 
    cout << borde << " 1. Convenciones Casillero Construible:"                                                                         << setw(92)  << borde << endl; 
    cout << borde << "    Terreno:"                                  << SIMBOLO_TERRENO          << VACIO << VACIO << VACIO
                            << NOMBRE_ASERRADERO          << ":"     << EMOJI_ASERRADERO         << VACIO << VACIO << VACIO
                            << NOMBRE_FABRICA             << ":"     << EMOJI_FABRICA            << VACIO << VACIO << VACIO
                            << NOMBRE_ESCUELA             << ":"     << EMOJI_ESCUELA            << VACIO << VACIO << VACIO
                            << NOMBRE_OBELISCO            << ":"     << EMOJI_OBELISCO           << VACIO << VACIO << VACIO
                            << NOMBRE_MINA                << ":"     << EMOJI_MINA               << VACIO << VACIO << VACIO
                            << NOMBRE_MINA_ORO            << ":"     << EMOJI_MINA_ORO           << VACIO << VACIO << VACIO
                            << PLANTA_ELECTRICA           << ":"     << EMOJI_PLANTA_ELECTRICA   << VACIO << VACIO                                  << borde << endl;
    cout << borde << " 2. Convenciones Casillero Inaccesible:"                                                                         << setw(92)  << borde << endl;                              
    cout << borde << "    Lago:"                                     << SIMBOLO_LAGO                                                   << setw(120) << borde << endl;                     
    cout << borde << " 3. Convenciones Casillero Transitable:"                                                                         << setw(92)  << borde << endl;
    cout << borde << "    Camino:"                                   << SIMBOLO_CAMINO           << VACIO << VACIO << VACIO
                            << "Betún:"                              << SIMBOLO_BETUN            << VACIO << VACIO << VACIO
                            << "Muelle:"                             << SIMBOLO_MUELLE           << VACIO << VACIO << VACIO
                            << PIEDRA     << ":"                     << EMOJI_PIEDRA             << VACIO << VACIO << VACIO
                            << MADERA     << ":"                     << EMOJI_MADERA             << VACIO << VACIO << VACIO
                            << METAL      << ":"                     << EMOJI_METAL              << VACIO << VACIO << VACIO
                            << ANDYCOINS  << ":"                     << EMOJI_ANDYCOINS                                                << setw(45)  << borde << endl << COLOR_DORADO;
    cout << " ╚■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■╝" << COLOR_POR_DEFECTO << endl;
}

void Mapa::inicializar_casillero(char terreno, int fila, int columna) {
    if (terreno == LAGO)
        this -> mapa[fila][columna] = new Casillero_inaccesible();
    else if (terreno == TERRENO)
        this -> mapa[fila][columna] = new Casillero_construible();
    else {
        string color;
        if (terreno == BETUN)
            color = FONDO_GRIS_CLARO;
        else if (terreno == CAMINO)
            color = FONDO_GRIS;
        else
            color = FONDO_MARRON;
    
        this -> mapa[fila][columna] = new Casillero_transitable(color, terreno);
    }
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
    
    if (coordenada_valida) {
        this -> mapa[fila][columna] -> agregar_jugador(jugador);
        jugador -> establecer_coordenadas(fila, columna);
    }else
        cout << COLOR_ROJO << "No se pudo posicionar al jugador en las coordenadas ingresadas, intente nuevamente" << COLOR_POR_DEFECTO << endl;
    return coordenada_valida;
}

void Mapa::realizar_movimiento(Jugador* jugador, int fila, int columna) {
    int* coordenadas_viejas = jugador -> obtener_coordenadas();
    int fila_vieja = coordenadas_viejas[INDICE_FILA];
    int columna_vieja = coordenadas_viejas[INDICE_COLUMNA];
    this -> mapa[fila][columna] -> agregar_jugador(jugador);
    this -> liberar_posicion(fila_vieja, columna_vieja);
    jugador -> establecer_coordenadas(fila, columna);
}

void Mapa::recolectar_materiales(Jugador* jugador, int fila, int columna) {
    Material* material = this -> mapa[fila][columna] -> obtener_puntero_material();
    Inventario* inventario = jugador -> obtener_inventario();
    inventario -> modificar_cantidad_material(material -> obtener_nombre_material(), material -> obtener_cantidad());
    material = nullptr;
    inventario = nullptr;
}

void Mapa::mover_jugador(Jugador* jugador, int fila, int columna, int energia_consumida) {
    if (!this -> esta_ocupado(fila, columna) && this -> obtener_tipo_casillero(fila, columna) != LAGO) {
        realizar_movimiento(jugador, fila, columna);
        jugador -> modificar_energia(-energia_consumida);
    }else if (this -> obtener_tipo_casillero(fila, columna) == LAGO) {
        cout << COLOR_ROJO << "No se puede mover el jugador :(, es un lago, te quieres ahogar papu?" << COLOR_POR_DEFECTO << endl;
    }else{
        if (this -> mapa[fila][columna] -> obtener_puntero_jugador() != nullptr)
            cout << COLOR_ROJO << "No se puede mover el jugador :(, porque hay un jugador en esa posición" << COLOR_POR_DEFECTO << endl;
        else if (this -> obtener_tipo_casillero(fila, columna) == TERRENO)
            cout << COLOR_ROJO << "No se puede mover el jugador :(, porque hay un edificio en esa posición" << COLOR_POR_DEFECTO << endl;
        else{
            cout << COLOR_VERDE << "Se movio el jugador (:, se recolecto el material que estaba en lugar de destino" << COLOR_POR_DEFECTO << endl;
            recolectar_materiales (jugador, fila, columna);
            realizar_movimiento(jugador, fila, columna);
            jugador -> modificar_energia(-energia_consumida);
        }
    }
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
    if (!this -> mapa[fila][columna] -> obtener_puntero_jugador())
        edificio = this -> mapa[fila][columna] -> obtener_puntero_edificio();
    return edificio;
}

Material* Mapa::obtener_material(int fila, int columna) {
    Material* material = nullptr;
    if (!this -> mapa[fila][columna] -> obtener_puntero_jugador())
        material = this -> mapa[fila][columna] -> obtener_puntero_material();
    return material;
}

void Mapa::mostrar_mapa() {
    cout << endl;
    this -> mostrar_simbologia();
    cout << endl;
    cout << "   ";
    for (int i = 0; i < this -> cantidad_columnas; i++)
        cout << i << "   ";
    
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
        for (int columna = 0; columna < this -> cantidad_columnas; columna++) {
            delete this -> mapa[fila][columna];
            this -> mapa[fila][columna] = nullptr;
        }
        delete [] this -> mapa[fila];
        this -> mapa[fila] = nullptr;
    }
    delete [] this -> mapa;
    this -> mapa = nullptr;
}