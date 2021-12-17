#include "../../archivos_h/juego/auxiliares_andypolis.h"

using namespace std;

Auxiliares_andypolis::Auxiliares_andypolis() {}

void Auxiliares_andypolis::seleccionar_jugador(string & nombre_jugador_1, string & nombre_jugador_2) {
    do {
        cout << "¿Que jugador quieres ser? Ingrese 1 para ser el primer jugador, 2 para el segundo" << endl;
        cout << COLOR_DORADO << ">> " << COLOR_POR_DEFECTO;
        cin >> nombre_jugador_1;
        system(CLR_SCREEN);
    } while (stoi(nombre_jugador_1) < 1 || stoi(nombre_jugador_1) > 2);
    nombre_jugador_2 = nombre_jugador_1 != NUMERO_JUGADOR_1 ? NUMERO_JUGADOR_1 : NUMERO_JUGADOR_2;
}

Jugador* Auxiliares_andypolis::cambiar_turno(Jugador* jugador_actual, Jugador* jugador_1, Jugador* jugador_2) {
    return jugador_actual == jugador_1 ? jugador_2 : jugador_1;
}

void Auxiliares_andypolis::inicializar_arreglo_objetivos(Objetivo** objetivos) {
    for (int i = 0; i < CANTIDAD_OBJETIVOS_POR_JUGADOR; i++)
        objetivos[i] = nullptr;
}

void Auxiliares_andypolis::cargar_objetivos(Objetivo** objetivos, int permitidos_escuela) {
    objetivos[NUMERO_OBJETIVO_OBELISCO] = new Objetivo_obelisco();
    this -> asignar_objetivos(objetivos, permitidos_escuela);
}

bool Auxiliares_andypolis::el_objetivo_fue_asignado(Objetivo** objetivos, Objetivo* objetivo_a_asignar, int indice) {
    bool existe = false;
    int i = 1;
    while(!existe && i < indice) {
        existe = objetivos[i] -> obtener_nombre() == objetivo_a_asignar -> obtener_nombre();
        i++;
    }
    return existe;
}

void Auxiliares_andypolis::asignar_objetivos(Objetivo** objetivos, int permitidos_escuela) {
    Objetivo* objetivo_asignado = nullptr;
    int numero_objetivo = 0;
    int i = 1;
    while (i <= CANTIDAD_OBJETIVOS_SECUNDARIOS_JUGADOR) {
        numero_objetivo = 1 + (rand() % (CANTIDAD_OBJETIVOS_SECUNDARIOS));
        if (numero_objetivo == NUMERO_OBJETIVO_COMPRAR_ANDYCOINS)
            objetivo_asignado = new Objetivo_andycoins();
        else if (numero_objetivo == NUMERO_OBJETIVO_PIEDRA)
            objetivo_asignado = new Objetivo_piedra();
        else if (numero_objetivo == NUMERO_OBJETIVO_BOMBARDERO)
            objetivo_asignado = new Objetivo_bombardero();
        else if (numero_objetivo == NUMERO_OBJETIVO_ENERGETICO)
            objetivo_asignado = new Objetivo_energetico();
        else if (numero_objetivo == NUMERO_OBJETIVO_LETRADO)
            objetivo_asignado = new Objetivo_letrado(permitidos_escuela);
        else if (numero_objetivo == NUMERO_OBJETIVO_MINERO)
            objetivo_asignado = new Objetivo_minero();
        else if (numero_objetivo == NUMERO_OBJETIVO_CANSADO)
            objetivo_asignado = new Objetivo_cansado();
        else if (numero_objetivo == NUMERO_OBJETIVO_CONSTRUCTOR)
            objetivo_asignado = new Objetivo_constructor();
        else if (numero_objetivo == NUMERO_OBJETIVO_ARMADO)
            objetivo_asignado = new Objetivo_armado();
        else if (numero_objetivo == NUMERO_OBJETIVO_EXTREMISTA)
            objetivo_asignado = new Objetivo_extremista();

        if (!this -> el_objetivo_fue_asignado(objetivos, objetivo_asignado, i)) {
            objetivos[i] = objetivo_asignado;
            i++;
        }
        else 
            delete objetivo_asignado;
        objetivo_asignado = nullptr;
    }
}

bool Auxiliares_andypolis::gano_la_partida(Jugador* jugador, Objetivo** objetivos) {
    bool obelisco_construido = objetivos[NUMERO_OBJETIVO_OBELISCO] -> se_cumplio_objetivo(jugador);
    int i = 1;
    int cantidad_cumplidos = 0;
    while (!obelisco_construido && i < CANTIDAD_OBJETIVOS_POR_JUGADOR) {
        if (objetivos[i] -> se_cumplio_objetivo(jugador))
            cantidad_cumplidos++;
        i++;
    }
    return obelisco_construido || cantidad_cumplidos >= MIN_CANTIDAD_OBJETIVOS_GANAR;
}

void Auxiliares_andypolis::aumentar_materiales_producidos(Jugador* jugador_actual) {
    Edificio** edificios = jugador_actual -> obtener_edificios_construidos();
    for(int i = 0; i < jugador_actual -> obtener_construidos(); i++)
        edificios[i] -> aumentar_material_producido();
    edificios = nullptr;
}

void Auxiliares_andypolis::cargar_grafo_auxiliar(Grafo* grafo, Mapa* mapa) {
    int* dimensiones_mapa = mapa -> obtener_dimensiones();
    for(int fila = 0; fila < dimensiones_mapa[INDICE_FILA]; fila++) {
        for (int columna = 0; columna < dimensiones_mapa[INDICE_COLUMNA]; columna++)
            grafo -> agregar_vertice(to_string(fila) + VACIO + to_string(columna));
    }
    dimensiones_mapa = nullptr;
}

void Auxiliares_andypolis::cargar_caminos(Grafo* grafo, Mapa* mapa, Jugador* jugador_actual) {
    int* dimensiones_mapa = mapa -> obtener_dimensiones();
    int costo_1 = 0;
    int costo_2 = 0;
    int fila_siguiente;
    int columna_siguiente;
    for(int fila = 0; fila < dimensiones_mapa[INDICE_FILA]; fila++) {
        for (int columna = 0; columna < dimensiones_mapa[INDICE_COLUMNA]; columna++) {

            fila_siguiente = fila + 1;
            columna_siguiente = columna + 1;
            if (fila_siguiente < dimensiones_mapa[INDICE_FILA] || columna_siguiente < dimensiones_mapa[INDICE_COLUMNA])
                costo_1 = this -> obtener_coste_camino(mapa, jugador_actual, fila, columna);

            if (columna_siguiente < dimensiones_mapa[INDICE_COLUMNA]) {
                costo_2 = this -> obtener_coste_camino(mapa, jugador_actual, fila, columna_siguiente);
                grafo -> agregar_camino(to_string(fila) + VACIO + to_string(columna), to_string(fila) + VACIO + to_string(columna_siguiente), costo_1, costo_2);
            }
            if (fila_siguiente < dimensiones_mapa[INDICE_FILA]) {
                costo_2 = this -> obtener_coste_camino(mapa, jugador_actual, fila_siguiente, columna);
                grafo -> agregar_camino(to_string(fila) + VACIO + to_string(columna), to_string(fila_siguiente) + VACIO + to_string(columna), costo_1, costo_2);
            }
        }
    }
    dimensiones_mapa = nullptr;
}

int Auxiliares_andypolis::obtener_coste_camino(Mapa* mapa, Jugador* jugador, int fila, int columna) {
    string nombre_jugador = jugador -> obtener_nombre() == NUMERO_JUGADOR_1 ? NUMERO_JUGADOR_1 : NUMERO_JUGADOR_2;
    char tipo_terreno =  mapa -> obtener_tipo_casillero(fila, columna);
    int costo = 0;
    if (tipo_terreno == TERRENO && mapa -> esta_ocupado(fila, columna))
        costo = INFINITO;
    else if (tipo_terreno == TERRENO)
        costo = COSTO_TERRENO;
    else if (tipo_terreno == LAGO)
        costo = nombre_jugador == NUMERO_JUGADOR_1 ? COSTO_LAGO_JUGADOR_1 : COSTO_LAGO_JUGADOR_2;
    else if (tipo_terreno == BETUN)
        costo = COSTO_BETUN;
    else if (tipo_terreno == CAMINO)
        costo = COSTO_CAMINO;
    else if (tipo_terreno == MUELLE)
        costo = nombre_jugador == NUMERO_JUGADOR_1 ? COSTO_MUELLE_JUGADOR_1 : COSTO_MUELLE_JUGADOR_2;

    return costo;
}

int* Auxiliares_andypolis::pedir_coordenadas(Mapa* mapa) {
    int* coordenadas = new int[MAX_COORDENADAS];
    bool ubicado = false;
    while (!ubicado) {
        cout << "Ingrese la fila" << COLOR_DORADO << " >> " << COLOR_POR_DEFECTO;
        cin >> coordenadas[INDICE_FILA];
        cout << "Ingrese la columna" << COLOR_DORADO << " >> " << COLOR_POR_DEFECTO;
        cin >> coordenadas[INDICE_COLUMNA];
        ubicado = !mapa -> coordenadas_fuera_de_rango(coordenadas[INDICE_FILA], coordenadas[INDICE_COLUMNA]);
        sleep(TIEMPO_ERROR);
        system(CLR_SCREEN);
    }
    return coordenadas;
}

bool Auxiliares_andypolis::tiene_energia(Jugador* jugador_actual) {
    bool tiene_energia = jugador_actual -> obtener_energia_actual() > 0;
    if (!tiene_energia) {
        cout << jugador_actual -> obtener_codigo_emoji() << COLOR_ROJO << "Te quedaste sin energia :( Ahora es turno del siguiente jugador" << COLOR_POR_DEFECTO << endl;
        sleep(3);
    }
    return tiene_energia;
}

string Auxiliares_andypolis::pedir_nombre_edificio() {
    string nombre_edificio;
    cout << "Ingrese el nombre del edificio" << COLOR_DORADO << " >> " << COLOR_POR_DEFECTO;
    getline(cin.ignore(), nombre_edificio);
    transform(nombre_edificio.begin(), nombre_edificio.end(), nombre_edificio.begin(), ::tolower);
    return nombre_edificio;
}

int Auxiliares_andypolis::pedir_nueva_cantidad_material(string material) {
    int cantidad = -1;
    while (cantidad < MIN_VALOR_MATERIAL || cantidad > MAX_VALOR_MATERIALES) {
        cout << "Ingrese la nueva cantidad de " << material << " >> " << COLOR_DORADO << COLOR_POR_DEFECTO;
        cin >> cantidad;
    }
    return cantidad;
}

void Auxiliares_andypolis::modificar_materiales_necesarios(Edificio* edificio) {
    int nueva_cantidad_piedra = this -> pedir_nueva_cantidad_material(PIEDRA);
    int nueva_cantidad_madera = this -> pedir_nueva_cantidad_material(MADERA);
    int nueva_cantidad_metal = this -> pedir_nueva_cantidad_material(METAL);
    edificio -> establecer_nuevos_materiales(nueva_cantidad_piedra, nueva_cantidad_madera, nueva_cantidad_metal);
}

bool Auxiliares_andypolis::hay_energia_suficiente(int energia_necesaria, int energia_del_jugador) {
    bool energia_suficiente = energia_del_jugador >= energia_necesaria;
    if (!energia_suficiente)
        cout << COLOR_ROJO << "No hay energia suficiente" << COLOR_POR_DEFECTO << endl;
    return energia_suficiente;
}

bool Auxiliares_andypolis::es_posible_comprar_bombas(Inventario* inventario, int cantidad_de_bombas) {
    bool se_pudo_comprar = this -> hay_material_suficiente(ANDYCOINS, inventario, (cantidad_de_bombas * COSTO_ANDYCOINS_BOMBA));
    if (se_pudo_comprar)
        cout << COLOR_VERDE << "Compra realizada exitosamente" << COLOR_POR_DEFECTO << endl;
    return se_pudo_comprar;
}

void Auxiliares_andypolis::construir_edificio_auxiliar(Abb* edificios_disponibles, Mapa* mapa, Jugador* jugador_actual, string edificio_a_construir) {
    Edificio* edificio = edificios_disponibles -> buscar_edificio(edificio_a_construir);
    if (!edificio)
        cout << COLOR_ROJO << "El edificio ingresado no existe, intente nuevamente" << COLOR_POR_DEFECTO << endl;
    else if (this -> se_alcanzo_maximo_permitido(edificio, jugador_actual))
        cout << COLOR_ROJO << "Ya estan construidos la cantidad maxima de " << edificio_a_construir << " posibles" << COLOR_POR_DEFECTO << endl;
    else {
        Inventario* inventario = jugador_actual -> obtener_inventario();
        int piedra_necesaria = edificio -> obtener_cantidad_necesaria(PIEDRA);
        int madera_necesaria = edificio -> obtener_cantidad_necesaria(MADERA);
        int metal_necesario = edificio -> obtener_cantidad_necesaria(METAL);
        if (this -> confirmar_construccion(edificio_a_construir) && this -> hay_material_suficiente(PIEDRA, inventario, piedra_necesaria) && this -> hay_material_suficiente(MADERA, inventario, madera_necesaria) && this -> hay_material_suficiente(METAL, inventario, metal_necesario)) {
            int* coordenadas = this -> pedir_coordenadas(mapa);
            Edificio* nuevo_edificio = this -> crear_edificio(edificio_a_construir, coordenadas[INDICE_FILA], coordenadas[INDICE_COLUMNA]);
            if (mapa -> se_ubico_edificio(nuevo_edificio, coordenadas[INDICE_FILA], coordenadas[INDICE_COLUMNA])) { 
                this -> actualizar_inventario(jugador_actual -> obtener_inventario(), - piedra_necesaria, - madera_necesaria, - metal_necesario);
                jugador_actual -> cargar_edificio(nuevo_edificio);
                jugador_actual -> modificar_energia(-ENERGIA_CONSTRUIR_EDIFICIO);
                cout << COLOR_VERDE << edificio_a_construir << " fue construido satisfactoriamente" << COLOR_POR_DEFECTO << endl;
            }
            else
                delete nuevo_edificio;
            delete [] coordenadas;
            coordenadas = nullptr;
            nuevo_edificio = nullptr;
        }
        inventario = nullptr;
    }
    edificio = nullptr;
}

bool Auxiliares_andypolis::se_alcanzo_maximo_permitido(Edificio* edificio_a_construir, Jugador* jugador_actual) {
    return jugador_actual -> obtener_cantidad_edificio(edificio_a_construir -> obtener_nombre()) == edificio_a_construir -> obtener_permitidos();
}

bool Auxiliares_andypolis::hay_material_suficiente(string material, Inventario* inventario, int cantidad_material) {
    int cantidad_guardada = inventario -> obtener_material(material) -> obtener_cantidad();
    bool cantidad_suficiente = cantidad_guardada >= cantidad_material;
    if (!cantidad_suficiente)
        cout << COLOR_ROJO << "Falta " << material << ", Tienes: " << cantidad_guardada << "| Necesitas: " << cantidad_material << COLOR_POR_DEFECTO << endl;
    return cantidad_suficiente;
}

void Auxiliares_andypolis::actualizar_inventario(Inventario* inventario, int piedra, int madera, int metal) {
    inventario -> modificar_cantidad_material(PIEDRA, piedra);
    inventario -> modificar_cantidad_material(MADERA, madera);
    inventario -> modificar_cantidad_material(METAL, metal);
}

bool Auxiliares_andypolis::confirmar_construccion(string edificio_a_construir) {
    string decision;
    cout << "Está seguro que quiere construir un/a " << edificio_a_construir << " ?(s/n): ";
    cin >> decision;
    transform(decision.begin(), decision.end(), decision.begin(), ::tolower);
    bool confirmado = decision == DECISION_SI;
    if (!confirmado)
        cout << COLOR_VERDE << "Operacion cancelada" << COLOR_POR_DEFECTO << endl;
    return confirmado;
}

void Auxiliares_andypolis::demoler_edificio_auxiliar(Abb* edificios_disponibles, Mapa* mapa, Jugador* jugador_actual, int fila, int columna) {
    Edificio* edificio = mapa -> obtener_edificio(fila, columna);
    if (mapa -> obtener_tipo_casillero(fila, columna) != TERRENO)
        cout << COLOR_ROJO << "En las coordenadas ingresadas no se puede demoler dado que no es un casillero de tipo Terreno" << COLOR_POR_DEFECTO << endl;
    else if (!edificio)
        cout << COLOR_ROJO << "En las coordenadas ingresadas no hay un edificio por demoler" << COLOR_POR_DEFECTO << endl;
    else if (!jugador_actual -> existe_el_edificio(fila, columna))
        cout << COLOR_ROJO << "No puede demoler un edificio que no le pertenece" << COLOR_POR_DEFECTO << endl;
    else {
        string nombre_edificio = edificio -> obtener_nombre();
        Edificio* edificio_a_demoler = edificios_disponibles -> buscar_edificio(nombre_edificio);
        int piedra_necesaria = edificio_a_demoler -> obtener_cantidad_necesaria(PIEDRA);
        int madera_necesaria = edificio_a_demoler -> obtener_cantidad_necesaria(MADERA);
        int metal_necesario = edificio_a_demoler -> obtener_cantidad_necesaria(METAL);
        this -> actualizar_inventario(jugador_actual -> obtener_inventario(), piedra_necesaria / 2, madera_necesaria / 2, metal_necesario / 2);
        jugador_actual -> eliminar_edificio(fila, columna);
        mapa -> liberar_posicion(fila, columna);
        jugador_actual -> modificar_energia(-ENERGIA_DEMOLER_EDIFICIO_COORDENADA);
        cout << COLOR_VERDE << nombre_edificio << " fue demolido statisfactoriamente!" << COLOR_POR_DEFECTO << endl;
        edificio_a_demoler = nullptr;
    }
    edificio = nullptr;
}

void Auxiliares_andypolis::reparar_edificio_auxiliar(Abb* edificios_disponibles, Mapa* mapa, Jugador* jugador, int fila, int columna) {
    Edificio* edificio = mapa -> obtener_edificio(fila, columna);
    if (mapa -> obtener_tipo_casillero(fila, columna) != TERRENO)
        cout << COLOR_ROJO << "En las coordenadas ingresadas no se puede reparar dado que no es un casillero de tipo Terreno" << COLOR_POR_DEFECTO << endl;
    else if (!edificio)
        cout << COLOR_ROJO << "En las coordenadas ingresadas no hay un edificio por reparar" << COLOR_POR_DEFECTO << endl;
    else if (!jugador -> existe_el_edificio(fila, columna))
        cout << COLOR_ROJO << "No puede reparar un edificio que no le pertenece" << COLOR_POR_DEFECTO << endl;
    else if (!edificio -> esta_afectado())
        cout << COLOR_ROJO << "No puede reparar un edificio que no esta afectado" << COLOR_POR_DEFECTO << endl;
    else {
        Edificio* receta_edificio = edificios_disponibles -> buscar_edificio(edificio -> obtener_nombre());
        Inventario* inventario = jugador -> obtener_inventario();
        int piedra_necesaria = (int) (receta_edificio -> obtener_cantidad_necesaria(PIEDRA) * PORCENTAJE_PIEDRA);
        int madera_necesaria = (int) (receta_edificio -> obtener_cantidad_necesaria(MADERA) * PORCENTAJE_MADERA);
        int metal_necesario = (int) (receta_edificio -> obtener_cantidad_necesaria(METAL) * PORCENTAJE_METAL);
        if (this -> hay_material_suficiente(PIEDRA, inventario, piedra_necesaria) && this -> hay_material_suficiente(MADERA, inventario, madera_necesaria) && this -> hay_material_suficiente(METAL, inventario, metal_necesario)) {
            this -> actualizar_inventario(inventario, piedra_necesaria, madera_necesaria, metal_necesario);
            edificio -> cambiar_estado_afectado();
            jugador -> modificar_energia(-ENERGIA_REPARAR_EDIFICIO);
            cout << COLOR_VERDE << edificio -> obtener_nombre() << " fue reparado satisfactoriamente" << COLOR_POR_DEFECTO << endl;
        }
        receta_edificio = nullptr;
        inventario = nullptr;
    }
}

void Auxiliares_andypolis::recolectar_recursos_auxiliares(Jugador* jugador_actual) {
    string material;
    int cantidad_material = 0;
    Edificio** edificios_construidos = jugador_actual -> obtener_edificios_construidos();
    for (int i = 0; i < jugador_actual -> obtener_construidos(); i++) {
        material = edificios_construidos[i] -> obtener_tipo_material_producido();
        cantidad_material = edificios_construidos[i] -> obtener_cantidad_de_material_producido();
        if (material == ENERGIA)
            jugador_actual -> modificar_energia(cantidad_material);
        else
            jugador_actual -> modificar_inventario(material, cantidad_material);
    }
    edificios_construidos = nullptr;
    jugador_actual -> modificar_energia(-ENERGIA_RECOLECTAR_RECURSOS);
    cout << COLOR_VERDE_AGUA << "Los recursos producidos por los edificios fueron recolectados satisfactoriamente" << COLOR_POR_DEFECTO << endl;
}

void Auxiliares_andypolis::atacar_edificio_auxiliar(Mapa* mapa, Jugador* jugador_actual, Jugador* jugador_1, Jugador* jugador_2, int fila, int columna) {
    Jugador* jugador_atacado = jugador_actual == jugador_1 ? jugador_2 : jugador_1;
    Inventario* inventario = jugador_actual -> obtener_inventario();
    Edificio* edificio = mapa -> obtener_edificio(fila, columna);

    if (mapa -> obtener_tipo_casillero(fila, columna) != TERRENO)
        cout << COLOR_ROJO << "En las coordenadas ingresadas no se puede atacar dado que no es un casillero de tipo Terreno" << endl;
    else if (!edificio)
        cout << COLOR_ROJO << "En las coordenadas ingresadas no hay un edificio por atacar" << endl;
    else if (jugador_actual -> existe_el_edificio(fila, columna))
        cout << COLOR_ROJO << "Sos suicida???, estas atacandote a vos mismo" << endl;
    else if (this -> hay_material_suficiente(BOMBA, inventario, 1)) {
        if ((edificio -> obtener_nombre() == NOMBRE_MINA || edificio -> obtener_nombre() == NOMBRE_FABRICA) && !edificio -> esta_afectado()) {
            edificio -> cambiar_estado_afectado();
            cout << COLOR_VERDE << edificio -> obtener_nombre() << " fue dañado" << endl;
        }
        else {
            mapa -> liberar_posicion(fila, columna);
            cout << COLOR_VERDE << edificio -> obtener_nombre() << " fue destruido" << endl;
            jugador_atacado -> eliminar_edificio(fila, columna);
        }
        jugador_actual -> modificar_energia(-ENERGIA_ATACAR_EDIFICIO_COORDENADA);
        inventario -> modificar_cantidad_material(BOMBA, -1);
        jugador_actual -> aumentar_bombas_usadas();
    }
    cout << COLOR_POR_DEFECTO;
    jugador_atacado = nullptr;
    inventario = nullptr;
    edificio = nullptr;
}

void Auxiliares_andypolis::lluvia_materiales(Mapa* mapa) {
    int piedra_a_generar = 1 + (rand() % 2);
    int madera_a_generar = (rand() % 4);
    int metal_a_generar = 2 + (rand() % 4);
    int andycoins_a_generar = (rand() % 2);
    this -> lluvia_material(PIEDRA, piedra_a_generar, mapa);
    this -> lluvia_material(MADERA, madera_a_generar, mapa);
    this -> lluvia_material(METAL, metal_a_generar, mapa);
    this -> lluvia_material(ANDYCOINS, andycoins_a_generar, mapa);
}

Material* Auxiliares_andypolis::generar_material(string nombre_material) {
    Material* material = nullptr;
    if (nombre_material == PIEDRA)
        material = new Piedra();
    else if (nombre_material == MADERA)
        material = new Madera();
    else if (nombre_material == METAL)
        material = new Metal();
    else
        material = new Andycoins();
    return material;
}

void Auxiliares_andypolis::lluvia_material(string nombre_material, int cantidad_a_generar, Mapa* mapa) {
    if (!mapa -> es_posible_insertar_materiales(cantidad_a_generar))
        cout << COLOR_ROJO << "No hay suficientes casilleros disponibles para generar " << nombre_material << COLOR_POR_DEFECTO << endl;
    else {
        int* coordenadas = 0;
        for (int i = 0; i < cantidad_a_generar; i++) {
            coordenadas = mapa -> generar_coordenadas_validas();
            mapa -> se_ubico_material(this -> generar_material(nombre_material), coordenadas[INDICE_FILA], coordenadas[INDICE_COLUMNA]);
            delete [] coordenadas;
            coordenadas = nullptr;
        }
    }
}

void Auxiliares_andypolis::realizar_movimiento(Jugador* jugador, Mapa* mapa, int fila, int columna) {
    int* coordenadas_viejas = jugador -> obtener_coordenadas();
    int fila_vieja = coordenadas_viejas[INDICE_FILA];
    int columna_vieja = coordenadas_viejas[INDICE_COLUMNA];
    mapa -> se_ubico_jugador(jugador, fila, columna);
    mapa -> liberar_posicion(fila_vieja, columna_vieja);
}

void Auxiliares_andypolis::recolectar_materiales(Jugador* jugador, Mapa* mapa, int fila, int columna) {
    Material* material = mapa -> obtener_material(fila, columna);
    Inventario* inventario = jugador -> obtener_inventario();
    inventario -> modificar_cantidad_material(material -> obtener_nombre_material(), material -> obtener_cantidad());
    delete material;
    mapa -> liberar_posicion(fila, columna);
    material = nullptr;
    inventario = nullptr;
}

void Auxiliares_andypolis::mover_jugador(Jugador* jugador, Mapa* mapa, int fila, int columna, int energia_consumida) {
    if (mapa -> obtener_tipo_casillero(fila, columna) == LAGO)
        cout << COLOR_ROJO << "No se puede mover el jugador :(, es un lago, te quieres ahogar papu?" << COLOR_POR_DEFECTO << endl;
    else if (mapa -> obtener_jugador(fila, columna) != nullptr)
        cout << COLOR_ROJO << "No se puede mover el jugador :(, porque hay un jugador en esa posición" << COLOR_POR_DEFECTO << endl;
    else if (mapa -> obtener_edificio(fila, columna) != nullptr)
        cout << COLOR_ROJO << "No se puede mover el jugador :(, porque hay un edificio en esa posición" << COLOR_POR_DEFECTO << endl;
    else {
        if (mapa -> obtener_material(fila, columna)) {
            this -> recolectar_materiales(jugador, mapa, fila, columna);
            cout << COLOR_VERDE << "Se movio el jugador (:, se recolecto el material que estaba en lugar de destino" << COLOR_POR_DEFECTO << endl;
        }
        this -> realizar_movimiento(jugador, mapa, fila, columna);
        jugador -> modificar_energia(-energia_consumida);
    }
}

void Auxiliares_andypolis::moverse_auxiliar(Grafo* grafo, Mapa* mapa, Jugador* jugador_actual) {
    int energia_consumida = 0;
    this -> cargar_caminos(grafo, mapa, jugador_actual);
    int* coordenadas = this -> pedir_coordenadas(mapa);
    int* coordenadas_jugador = jugador_actual -> obtener_coordenadas();
    string coordenadas_origen = to_string(coordenadas_jugador[INDICE_FILA]) + VACIO + to_string(coordenadas_jugador[INDICE_COLUMNA]);
    string coordenadas_destino = to_string(coordenadas[INDICE_FILA]) + VACIO + to_string(coordenadas[INDICE_COLUMNA]);
    grafo -> camino_minimo(energia_consumida, coordenadas_origen, coordenadas_destino);

    if (this -> hay_energia_suficiente(energia_consumida, jugador_actual -> obtener_energia_actual()))
        this -> mover_jugador(jugador_actual, mapa, coordenadas[INDICE_FILA], coordenadas[INDICE_COLUMNA], energia_consumida);
    
    delete [] coordenadas;
    coordenadas = nullptr;
    coordenadas_jugador = nullptr;
}

void Auxiliares_andypolis::mostrar_preguntas_frecuentes_auxiliares() {
    cout << FONDO_MARRON << "¿Qué se debe hacer para ganar?" << COLOR_POR_DEFECTO << endl;
    cout << COLOR_DORADO << "-> " << COLOR_POR_DEFECTO << "Opción 1: Que se cumplan 2 de los 3 objetivos random que le toca a cada jugador." << endl;
    cout << COLOR_DORADO << "-> " << COLOR_POR_DEFECTO << "Opción 2: Que el jugador consiga construir un Obelisco." << endl << endl;

    cout << FONDO_AQUA << "¿Qué hacer si la energía llega a 0 ó si se necesita más energía?" << COLOR_POR_DEFECTO << endl;
    cout << "Después de cada turno se le otorgarán 20 puntos de energía a cada jugador, independientemente de si se quedo sin energía o no." << endl << endl;

    cout << FONDO_VERDE << "¿Cuantos tipos de edificios existen en el juego?" << COLOR_POR_DEFECTO << endl;
    cout << "Existen 7 tipos de edificios posibles por construir y son:" << endl;
    cout << "Aserradero " << EMOJI_ASERRADERO << " - Mina " << EMOJI_MINA << " - Mina Oro " << EMOJI_MINA_ORO << " - Fábrica " << EMOJI_FABRICA
         << " - Planta Electrica " << EMOJI_PLANTA_ELECTRICA << " - Escuela " << EMOJI_ESCUELA << " - Obelisco " << EMOJI_OBELISCO << endl << endl;

    cout << FONDO_AZUL << "¿Se pueden construir cantidades ilimitadas de edificios?" << COLOR_POR_DEFECTO << endl;
    cout << "No hay una cantidad ilimitada de edificios para construir, ya que cada tipo de edificio tiene su propio limite de construcciones posibles." << endl << endl;

    cout << FONDO_MORADO_CLARO << "¿Cuantos tipos de materiales hay en el juego?" << COLOR_POR_DEFECTO << endl;
    cout << "Hay 6 tipos de materiales en el juego y son:" << endl;
    cout << "Piedra " << EMOJI_PIEDRA << " - Metal " << EMOJI_METAL << " - Madera " << EMOJI_MADERA << " - Bomba " << EMOJI_BOMBA
         << " - Andycoin " << EMOJI_ANDYCOINS << " - Energía " << EMOJI_ENERGIA << endl << endl;

    cout << FONDO_GRIS << "¿Que pasa si ataco uno de mis edificios construídos por error?" << COLOR_POR_DEFECTO << endl;
    cout << "No se realizará el ataque, y se mostrará un mensaje por consola informandole al jugador." << endl << endl;
}

Edificio* Auxiliares_andypolis::crear_edificio(string nombre, int fila, int columna) {
    Edificio* edificio_creado = nullptr;

    if (nombre == NOMBRE_ASERRADERO)
        edificio_creado = new Aserradero(fila, columna);
    else if (nombre == NOMBRE_ESCUELA) 
        edificio_creado = new Escuela(fila, columna);
    else if (nombre == NOMBRE_FABRICA) 
        edificio_creado = new Fabrica(fila, columna);
    else if (nombre == NOMBRE_MINA) 
        edificio_creado = new Mina(fila, columna);
    else if (nombre == NOMBRE_OBELISCO) 
        edificio_creado = new Obelisco(fila, columna);
    else if (nombre == PLANTA_ELECTRICA) 
        edificio_creado = new Planta_electrica(fila, columna);
    else if (nombre == NOMBRE_MINA_ORO) 
        edificio_creado = new Mina_oro(fila, columna);

    return edificio_creado;
}