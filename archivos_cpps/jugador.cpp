#include "../archivos_h/jugador.h"

using namespace std;

Jugador::Jugador() {
    this -> cantidad_construidos = 0;
    this -> edificios_construidos = new Edificio* [this -> cantidad_construidos];
    this -> energia = Energia();
    this -> coordenadas = new int [MAX_COORDENADAS];
    this -> coordenadas[INDICE_FILA] = -1;
    this -> coordenadas[INDICE_COLUMNA] = -1;
    this -> inventario = new Inventario();
    this -> codigo_emoji = VACIO;
    this -> nombre = VACIO;
    this -> andycoins_juntados = 0;
    this -> bombas_usadas = 0;
    this -> bombas_compradas = 0;

}

void Jugador::establecer_nombre(string nombre) {
    this -> nombre = nombre;
}

void Jugador::inicializar_arreglo_objetivos() {
    for (int i = 0; i < CANTIDAD_OBJETIVOS_POR_JUGADOR; i++) {
        this -> objetivos[i] = nullptr;
    }
}

bool Jugador::el_objetivo_fue_asignado(Objetivo* objetivo_a_asignar, int indice) {
    bool existe = false;
    int i = 1;
    while(!existe && i <= indice) {
        existe = this -> objetivos[i] -> obtener_nombre() == objetivo_a_asignar -> obtener_nombre();
        i++;
    }
    return existe;
}

void Jugador::asignar_objetivos(int cantidad_escuelas_permitidos) {
    Objetivo* objetivo_asignado = nullptr;
    int objetivo = (rand() % CANTIDAD_OBJETIVOS_SECUNDARIOS);
    int i = 1;
    while (!objetivos[3]) {
        if(objetivo == NUMERO_OBJETIVO_EXTREMISTA)
            objetivo_asignado = new Objetivo_extremista();
        else if(objetivo == NUMERO_OBJETIVO_COMPRAR_ANDYCOINS)
            objetivo_asignado = new Objetivo_andycoins();
        else if(objetivo == NUMERO_OBJETIVO_PIEDRA)
            objetivo_asignado = new Objetivo_piedra();
        else if(objetivo == NUMERO_OBJETIVO_BOMBARDERO)
            objetivo_asignado = new Objetivo_bombardero();
        else if(objetivo == NUMERO_OBJETIVO_ENERGETICO)
            objetivo_asignado = new Objetivo_energetico();
        else if(objetivo == NUMERO_OBJETIVO_LETRADO)
            objetivo_asignado = new Objetivo_letrado(cantidad_escuelas_permitidos);
        else if(objetivo == NUMERO_OBJETIVO_MINERO)
            objetivo_asignado = new Objetivo_minero();
        else if(objetivo == NUMERO_OBJETIVO_CANSADO)
            objetivo_asignado = new Objetivo_cansado();
        else if(objetivo == NUMERO_OBJETIVO_CONSTRUCTOR)
            objetivo_asignado = new Objetivo_constructor();
        else if(objetivo == NUMERO_OBJETIVO_ARMADO)
            objetivo_asignado = new Objetivo_armado();
        if(!this -> el_objetivo_fue_asignado(objetivo_asignado, i)) {
            this -> objetivos[i] = objetivo_asignado;
            i++;
        }
    }

}

void Jugador::aumentar_andycoins_juntados(int cantidad_andycoins) {
    this -> andycoins_juntados += cantidad_andycoins;
}
void Jugador::aumentar_bombas_compradas(int cantidad_bombas) {
    this -> bombas_compradas += cantidad_bombas;
}

void Jugador::aumentar_bombas_usadas(int cantidad_bombas_usadas) {
    this -> bombas_usadas += cantidad_bombas_usadas;
}

void Jugador::cargar_objetivos(int cantidad_escuelas_permitidos) {
    this -> objetivos[0] = new Objetivo_obelisco();
    this -> asignar_objetivos(cantidad_escuelas_permitidos);
}

bool Jugador::hay_obelisco_construido() {
    bool hay_obelisco = false;
    int i = 0;
    while (!hay_obelisco && i < this -> cantidad_construidos) {
        if (this -> edificios_construidos[i] -> obtener_nombre() == NOMBRE_OBELISCO) {
            hay_obelisco = true;
        }
        i++;
    }   
    return hay_obelisco;
}

bool Jugador::hay_minas_construidas(){
    bool hay_mina_oro = false;
    bool hay_mina = false;
    int i = 0;

    while(!hay_mina_oro && !hay_mina && i < this -> cantidad_construidos){
        string edificio = edificios_construidos[i] -> obtener_nombre();
        if(edificio == NOMBRE_MINA_ORO){
            hay_mina_oro = true;
        }else if(edificio == NOMBRE_MINA){
            hay_mina = true;
        }

        i++;
    }

    bool objetivo_cumplido = (hay_mina_oro && hay_mina);
    return objetivo_cumplido;
}

bool Jugador::objetivo_constructor_hecho(){
    bool hay_escuela = false;
    bool hay_planta = false;
    bool hay_aserradero = false;
    bool hay_fabrica = false;
    int i = 0;

    while(!hay_escuela && !hay_planta && !hay_aserradero && !hay_fabrica && i < this -> cantidad_construidos){
        string edificio = this -> edificios_construidos[i] -> obtener_nombre();
        if(edificio == NOMBRE_PLANTA){
            hay_planta = true;
        }else if(edificio == NOMBRE_ESCUELA){
            hay_escuela = true;
        }else if(edificio == NOMBRE_ASERRADERO){
            hay_aserradero = true;
        }else if(edificio == NOMBRE_FABRICA){
            hay_fabrica = true;
        }

        i++;
    }

    return(hay_planta && hay_escuela && hay_fabrica && hay_aserradero && hay_minas_construidas());

}

bool Jugador::objetivos_cumplidos() {
    bool gano_el_juego = false;
    if(this -> hay_obelisco_construido()){
        gano_el_juego = true;
    }
    else {
        int objetivos_cumplidos = 0;
        for (int i = 1; i < CANTIDAD_OBJETIVOS_POR_JUGADOR; i++) {
            bool objetivo_cumplido = false;
            if (this -> objetivos[i] -> obtener_nombre() == NOMBRE_OBJETIVO_ANDYCOINS) {
                objetivo_cumplido = this -> objetivos[i] -> se_cumplio_el_objetivo(this -> andycoins_juntados);
            }
            else if (this -> objetivos[i] -> obtener_nombre() == NOMBRE_OBJETIVO_ARMADO) {
                int cantidad_bombas = this -> inventario -> obtener_material(BOMBA) -> obtener_cantidad();
                objetivo_cumplido = this -> objetivos[i] -> se_cumplio_el_objetivo(cantidad_bombas);
            }
            else if (this -> objetivos[i] -> obtener_nombre() == NOMBRE_OBJETIVO_BOMBARDERO) {
                objetivo_cumplido = this -> objetivos[i] -> se_cumplio_el_objetivo(this -> bombas_usadas);
            }
            else if (this -> objetivos[i] -> obtener_nombre() == NOMBRE_OBJETIVO_CANSADO) {
                objetivo_cumplido = this -> objetivos[i] -> se_cumplio_el_objetivo(this -> energia.obtener_cantidad());
            }
            else if (this -> objetivos[i] -> obtener_nombre() == NOMBRE_OBJETIVO_CONSTRUCTOR) {
                objetivo_constructor_hecho;
            }
            else if (this -> objetivos[i] -> obtener_nombre() == NOMBRE_OBJETIVO_ENERGETICO) {
                objetivo_cumplido = this -> objetivos[i] -> se_cumplio_el_objetivo(this -> energia.obtener_cantidad());
            }
            else if (this -> objetivos[i] -> obtener_nombre() == NOMBRE_OBJETIVO_EXTREMISTA) {
                objetivo_cumplido = this -> objetivos[i] -> se_cumplio_el_objetivo(this -> bombas_compradas);
            }
            else if (this -> objetivos[i] -> obtener_nombre() == NOMBRE_OBJETIVO_LETRADO) {
                objetivo_cumplido = this -> objetivos[i] -> se_cumplio_el_objetivo(NOMBRE_OBJETIVO_CANSADO);
            }
            else if (this -> objetivos[i] -> obtener_nombre() == NOMBRE_OBJETIVO_MINERO) {
               objetivo_cumplido = hay_minas_construidas();
            }
            else if (this -> objetivos[i] -> obtener_nombre() == NOMBRE_OBJETIVO_PIEDRA) {
                int cantidad_piedra = this -> inventario ->obtener_material(PIEDRA) -> obtener_cantidad();
                objetivo_cumplido = this -> objetivos[i] -> se_cumplio_el_objetivo(NOMBRE_OBJETIVO_CANSADO);
            }

            if(objetivo_cumplido){
                objetivos_cumplidos++;
            }
        }
    }
}

string Jugador::obtener_nombre() {
    return this -> nombre;
}

void Jugador::establecer_coordenadas(int fila, int columna) {
    this -> coordenadas[INDICE_FILA] =  fila;
    this -> coordenadas[INDICE_COLUMNA] = columna;
}

void Jugador::establecer_codigo_emoji(string codigo_emoji) {
    this -> codigo_emoji = codigo_emoji;
}

void Jugador::cargar_edificio(Edificio* edificio) {
    redimensionar_edificio(this -> cantidad_construidos + 1);
    this -> edificios_construidos[this -> cantidad_construidos] = edificio;
    this -> cantidad_construidos++;

}

void Jugador::redimensionar_edificio(int nueva_longitud) {
    Edificio** nuevo_vector_edificios = new Edificio*[nueva_longitud];
    int indice = 0;
    for (int i = 0; i < this -> cantidad_construidos; i++) {
        if (this -> edificios_construidos[i]) {
            nuevo_vector_edificios[indice] = this -> edificios_construidos[i];
            indice++;
        }
    }
    delete [] this -> edificios_construidos;
    this -> edificios_construidos = nuevo_vector_edificios;
}

bool Jugador::existe_el_edificio(int fila, int columna) {
    bool existe = false;
    int i = 0;
    int* coordenadas = 0;
    while(!existe && i < this -> cantidad_construidos) {
        coordenadas = edificios_construidos[i] -> obtener_coordenadas();
        existe = coordenadas[INDICE_FILA] == fila && coordenadas[INDICE_COLUMNA] == columna;
        i++;
    }
    return existe;
}

bool Jugador::eliminar_edificio(int fila, int columna) {
    bool se_elimino = false;
    int i = 0;
    while (i < this -> cantidad_construidos && !se_elimino) {
        if (this -> existe_el_edificio(fila, columna)) {
            delete this -> edificios_construidos[i];
            this -> edificios_construidos[i] = nullptr;
            se_elimino = true;
            this -> redimensionar_edificio(this -> cantidad_construidos - 1);
            this -> cantidad_construidos--;
        }
        i++;
    }
    return se_elimino;
}

string Jugador::obtener_codigo_emoji() {
    return this -> codigo_emoji;
}

int* Jugador::obtener_coordenadas() {
    return this -> coordenadas;
}

int Jugador::obtener_energia_actual() {
    return this -> energia.obtener_energia_actual();
}

int Jugador::obtener_cantidad_edificio(string nombre_edificio) {
    int construidos = 0;
    for (int i = 0; i < this -> cantidad_construidos; i++) {
        if (this -> edificios_construidos[i] -> obtener_nombre() == nombre_edificio)
            construidos++;
    }
    return construidos;
}

Edificio** Jugador::obtener_edificios_construidos() {
    return this -> edificios_construidos;
}

int Jugador::obtener_construidos() {
    return this -> cantidad_construidos;
}

void Jugador::mover(int fila, int columna) {
    /* HACER A FUTURO CON GRAFOS (CAMINOS MINIMOS). */
}

void Jugador::modificar_energia(int cantidad_energia) { 
    this -> energia.modificar_cantidad(cantidad_energia);
}

void Jugador::cargar_material(Material* material) {
    this -> inventario -> agregar_material(material);
}

void Jugador::modificar_inventario(string material, int cantidad) {
    this -> inventario -> modificar_cantidad_material(material, cantidad);
    if (material == ANDYCOINS) {
        this -> aumentar_andycoins_juntados(cantidad);
    }
    else if (material == BOMBA)
        this -> aumentar_bombas_compradas(cantidad);
}

void Jugador::listar_construidos() {
    string esta_afectado;
    int* coordenadas = 0;
    for (int i = 0; i < this -> cantidad_construidos; i++) {
        esta_afectado = this -> edificios_construidos[i] -> esta_afectado() ? "SI" : "NO";
        coordenadas = edificios_construidos[i] -> obtener_coordenadas();
        cout << this -> edificios_construidos[i] -> obtener_nombre() << endl;
        cout << "Afectado: " << esta_afectado << endl;
        cout << "Coordenadas: " << '(' << coordenadas[INDICE_FILA] << "," << coordenadas[INDICE_COLUMNA] << ')' << endl;
        cout << COLOR_MARRON << LINEA_DIVISORIA << COLOR_POR_DEFECTO << endl;
    }
}

Inventario* Jugador::obtener_inventario() {
    return this -> inventario;
}

Jugador::~Jugador() {
    // delete [] this -> edificios_construidos;
    delete [] this -> inventario;
    // delete [] this -> coordenadas;
    // this -> coordenadas = nullptr;
}