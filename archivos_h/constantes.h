#ifndef _CONSTANTES_H_
#define _CONSTANTES_H_

#include <iostream>

// GRAFOS
const int POSICION_NO_ENCONTRADA = -1;
const std::string NOMBRE_NO_ENCONTRADO = "";
const int INFINITO = 99999999;

// DESICIONES
const std::string DECISION_SI = "s";

// MATERIALES
const std::string PIEDRA = "piedra";
const std::string METAL = "metal";
const std::string MADERA = "madera";
const std::string BOMBA = "bombas";
const std::string ANDYCOINS = "andycoins";
const std::string ENERGIA = "energia";
const char VACIO = ' ';
const int MATERIALES_DISPONIBLES = 5;
const int BRINDAR_MATERIALES_MINA = 15; //piedras
const int BRINDAR_MATERIALES_ASERRADERO = 25; //maderas
const int BRINDAR_MATERIALES_FABRICA = 40; //metales
const int BRINDAR_MATERIALES_PLANTA_ELECTRICA = 15; //energia
const int BRINDAR_MATERIALES_MINA_ORO = 50; //andycoins
const int BRINDAR_MATERIALES_ESCUELA = 25;  //andycoins
const int MAXIMO_ENERGIA = 100;
const int ENERGIA_INICIAL = 50;
const int MAX_VALOR_MATERIALES = 50000;
const int MIN_VALOR_MATERIAL = 0;
const int BOLSA_PIEDRA = 100;
const int BOLSA_MADERA = 50;
const int BOLSA_METAL = 50;
const int BOLSA_ANDYCOINS = 250;

// COLORES
const std::string COLOR_POR_DEFECTO = "\033[0m";
const std::string COLOR_ROJO = "\033[38;5;196m";
const std::string COLOR_VERDE = "\033[38;5;46m";
const std::string COLOR_VERDE_AGUA = "\033[38;5;35m";
const std::string COLOR_MARRON = "\033[38;5;136m";
const std::string COLOR_DORADO = "\x1b[33m";

const std::string FONDO_AZUL = "\033[48;5;27m";
const std::string FONDO_VERDE = "\033[48;5;28m";
const std::string FONDO_GRIS = "\033[48;5;239m";
const std::string FONDO_BLANCO = "\033[48;5;252m";
const std::string FONDO_MORADO_CLARO = "\033[48;5;5m";
const std::string FONDO_MARRON = "\033[48;5;94m";
const std::string FONDO_AQUA = "\033[48;5;23m";

// JUEGO
const int OPCION_EMPEZAR = 66;
const int OPCION_SALIR = 69;
const int OPCION_SALIR_JUEGO = 20;

// TIEMPOS DE ESPERA COMUNES PARA AMBOS MENUS
const int TIEMPO_GUARDAR_SALIR = 1;
const int TIEMPO_MOSTRAR_MAPA = 15;
const int TIEMPO_ERROR = 3;

// TIEMPOS DE ESPERA MENU DE CONFIGURACION
const int TIEMPO_MODIFICAR_EDIFICIO = 4;
const int TIEMPO_LISTAR_TOTAL_EDIFICIOS = 5;
const int TIEMPO_COMENZAR_PARTIDA = 4;

// TIEMPOS DE ESPERA MENU DE PARTIDA
const int TIEMPO_CONSTRUIR_EDIFICIO = 4;
const int TIEMPO_LISTAR_MIS_EDIFICIOS = 5;
const int TIEMPO_DEMOLER_EDIFICIO = 4;
const int TIEMPO_ATACAR_EDIFICIO_COORDENADA = 4;
const int TIEMPO_REPARAR_EDIFICIO_COORDENADA = 4;
const int TIEMPO_COMPRAR_BOMBAS = 4;
const int TIEMPO_CONSULTAR_COORDENADAS = 4;
const int TIEMPO_MOSTRAR_INVENTARIO = 5;
const int TIEMPO_MOSTRAR_OBJETIVOS = 12;
const int TIEMPO_RECOLECTAR_RECURSOS_PRODUCIDOS = 3;
const int TIEMPO_MOSTRAR_PREGUNTAS_FRECUENTES = 15;
const int TIEMPO_MOVERSE_UNA_COORDENADA = 8;
const int TIEMPO_FINALIZAR_TURNO = 2;

// OPCIONES MENU DE CONFIGURACION
const int OPCION_MODIFICAR_EDIFICIO_NOMBRE = 1;
const int OPCION_LISTAR_TOTAL_EDIFICIOS = 2;
const int OPCION_MOSTRAR_MAPA_CONFIGURACION = 3;
const int OPCION_COMENZAR_PARTIDA = 4;
const int OPCION_GUARDAR_SALIR_CONFIGURACION = 5;

// OPCIONES MENU DE PARTIDA
const int OPCION_CONSTRUIR_EDIFICIO = 1;
const int OPCION_LISTAR_MIS_EDIFICIOS = 2;
const int OPCION_DEMOLER_EDIFICIO = 3;
const int OPCION_ATACAR_EDIFICIO_COORDENADA = 4;
const int OPCION_REPARAR_EDIFICO_COODENADA = 5;
const int OPCION_COMPRAR_BOMBAS = 6;
const int OPCION_CONSULTAR_COORDENADAS = 7;
const int OPCION_MOSTRAR_INVENTARIO = 8;
const int OPCION_MOSTRAR_OBJETIVOS = 9;
const int OPCION_RECOLECTAR_RECURSOS_PRODUCIOS = 10;
const int OPCION_MOVERSE_UNA_COORDENADA = 11;
const int OPCION_MOSTRAR_MAPA_JUEGO = 12;
const int OPCION_MOSTRAR_PREGUNTAS_FRECUENTES = 13;
const int OPCION_FINALIZAR_TURNO = 14;
const int OPCION_GUARDAR_SALIR_PARTIDA = 15;

// EMOJIS MENUS
const std::string EMOJI_CRONOMETRO = "\u23F1";

// PRIMER MENU
const std::string EMOJI_MODIFICAR_EDIFICIO_POR_NOMBRE = "\u270D";
const std::string EMOJI_LISTAR_TODOS_LOS_EDIFICIOS = "\U0001f3d9";
const std::string EMOJI_MOSTRAR_MAPA = "\U0001f30e";
const std::string EMOJI_COMENZAR_PARTIDA = "\u25B6";

// SEGUNDO MENU
const std::string EMOJI_CONSTRUIR_EDIFICIO_POR_NOMBRE = "\U0001f3d7";
const std::string EMOJI_CHECK = "\u2705";
const std::string EMOJI_DEMOLER_POR_COORDENADA = "\U0001f6a7";
const std::string EMOJI_ATACAR_POR_COORDENADA = "\U0001f480";
const std::string EMOJI_REPARAR_POR_COORDENADA = "\U0001f527";
const std::string EMOJI_COMPRAR_BOMBAS = "\U0001f9e8";
const std::string EMOJI_CONSULTAR_COORDENADAS = "\U0001f5fa";
const std::string EMOJI_INVENTARIO = "\U0001f9f0";
const std::string EMOJI_OBJETIVOS = "\U0001f3c1";
const std::string EMOJI_RECURSOS_PRODUCIDOS = "\u26CF";
const std::string EMOJI_MOVERSE_A_UNA_COORDENADA = "\U0001f3c3";//alternativa: U0001f9ed(brujula)
const std::string EMOJI_REGLAS_JUEGO = "\U0001f3c6";
const std::string EMOJI_FINALIZAR_TURNO = "\U0001f51a";
const std::string EMOJI_GUARDAR_Y_SALIR = "\U0001f4be";

// EMOJIS MATERIALES
const std::string EMOJI_PIEDRA = "\U0001f311";
const std::string EMOJI_METAL = "\U0001f529";
const std::string EMOJI_MADERA = "\U0001f954";
const std::string EMOJI_ENERGIA = "\u26A1";
const std::string EMOJI_ANDYCOINS = "\U0001f4b0";
const std::string EMOJI_BOMBA = "\U0001f4a3";
const std::string EMOJI_CAMINO = "\U0001f6e4";
const int LIMITE_INFERIOR_PIEDRA = 1;
const int LIMITE_SUPERIOR_PIEDRA = 2;
const int CANTIDAD_PRODUCIDA_PIEDRA = 100;
const int LIMITE_INFERIOR_MADERA = 0;
const int LIMITE_SUPERIOR_MADERA = 3;
const int CANTIDAD_PRODUCIDA_MADERA = 50;
const int LIMITE_INFERIOR_METAL = 2;
const int LIMITE_SUPERIOR_METAL = 4;
const int CANTIDAD_PRODUCIDA_METAL = 50;
const int LIMITE_INFERIOR_ANDYCOINS = 0;
const int LIMITE_SUPERIOR_ANDYCOINS = 1;
const int CANTIDAD_PRODUCIDA_ANDYCOINS = 250;
const int MIN_CANTIDAD_MATERIAL_PRODUCIDO = 0;
const int POS_PIEDRA = 0;
const int POS_MADERA = 1;
const int POS_METAL = 2;
const int MAX_MATERIALES = 3;

// EMOJIS EDIFICIOS
const std::string EMOJI_PLANTA_ELECTRICA = "\U0001f3e4";
const std::string EMOJI_MINA_ORO = "\U0001f682";
const std::string EMOJI_MINA = "\U0001f68a";
const std::string EMOJI_ASERRADERO = "\U0001f3ec";
const std::string EMOJI_ESCUELA = "\U0001f3eb";
const std::string EMOJI_FABRICA = "\U0001f3ed";
const std::string EMOJI_OBELISCO = "\U0001f5fc";
const double PORCENTAJE_PIEDRA = 0.25;
const double PORCENTAJE_MADERA = 0.25;
const double PORCENTAJE_METAL = 0.25;

// RUTAS ARCHIVOS
const std::string RUTA_MATERIALES = "archivos_de_texto/materiales.txt";
const std::string RUTA_EDIFICIOS = "archivos_de_texto/edificios.txt";
const std::string RUTA_MAPA = "archivos_de_texto/mapa.txt";
const std::string RUTA_UBICACIONES = "archivos_de_texto/ubicaciones.txt";

// ENERGÍA
const int ENERGIA_FINALIZAR_TURNO = 20;
const int MAX_EDIFICIOS_DISPONIBLES = 7;
const int ENERGIA_CONSTRUIR_EDIFICIO = 15;
const int ENERGIA_DEMOLER_EDIFICIO_COORDENADA = 15;
const int ENERGIA_ATACAR_EDIFICIO_COORDENADA = 30;
const int ENERGIA_REPARAR_EDIFICIO = 25;
const int ENERGIA_COMPRAR_BOMBA = 5;
const int ENERGIA_RECOLECTAR_RECURSOS = 20;

// EDIFICIOS
const std::string PLANTA_ELECTRICA = "planta electrica";
const std::string NOMBRE_ASERRADERO = "aserradero";
const std::string NOMBRE_ESCUELA = "escuela";
const std::string NOMBRE_FABRICA = "fabrica";
const std::string NOMBRE_OBELISCO = "obelisco";
const std::string NOMBRE_MINA = "mina";
const std::string NOMBRE_MINA_ORO = "mina oro";
const std::string NOMBRE_ORO = "oro";
const std::string NOMBRE_PLANTA = "planta";

// OBJETIVOS 
const std::string NOMBRE_OBJETIVO_ANDYCOINS = "Andycoins por los cielos";
const std::string NOMBRE_OBJETIVO_OBELISCO = "Mas alto que las nubes";
const std::string NOMBRE_OBJETIVO_PIEDRA = "Edad de piedra";
const std::string NOMBRE_OBJETIVO_MINERO = "Minero";
const std::string NOMBRE_OBJETIVO_BOMBARDERO = "Bombardero";
const std::string NOMBRE_OBJETIVO_EXTREMISTA = "Extremista taliban";
const std::string NOMBRE_OBJETIVO_ENERGETICO = "Energetico";
const std::string NOMBRE_OBJETIVO_LETRADO = "Intelectual";
const std::string NOMBRE_OBJETIVO_CANSADO = "Cansado";
const std::string NOMBRE_OBJETIVO_CONSTRUCTOR = "Many a la obra (bob constructor)";
const std::string NOMBRE_OBJETIVO_ARMADO = "Terrorista (full armado)";
const int CANTIDAD_OBJETIVOS_SECUNDARIOS = 10;
const int NUMERO_OBJETIVO_OBELISCO = 0;
const int NUMERO_OBJETIVO_COMPRAR_ANDYCOINS = 1;
const int NUMERO_OBJETIVO_PIEDRA = 2;
const int NUMERO_OBJETIVO_BOMBARDERO = 3;
const int NUMERO_OBJETIVO_ENERGETICO = 4;
const int NUMERO_OBJETIVO_LETRADO = 5;
const int NUMERO_OBJETIVO_MINERO = 6;
const int NUMERO_OBJETIVO_CANSADO = 7;
const int NUMERO_OBJETIVO_CONSTRUCTOR = 8;
const int NUMERO_OBJETIVO_ARMADO = 9;
const int NUMERO_OBJETIVO_EXTREMISTA = 10;
const int MIN_CANTIDAD_OBJETIVOS_GANAR = 2;

const int OBJETIVO_ANDYCOINS = 100000;
const int OBJETIVO_PIEDRA = 50000;
const int OBJETIVO_BOMBARDERO = 5;
const int OBJETIVO_ENERGETICO = 100;
const int OBJETIVO_CANSADO = 0;
const int OBJETIVO_ARMADO = 10;
const int OBJETIVO_EXTREMISTA = 500;

const int POS_PLANTA_ELECTRICA = 0;
const int POS_ASERRADERO = 1;
const int POS_FABRICA = 2;
const int POS_ESCUELA = 3;
const int POS_MINA_ORO = 4;
const int POS_MINA = 5;

// JUGADORES
const std::string JUGADOR_1 = "\U0001f473";
const std::string JUGADOR_2 = "\U0001f9dc";
const std::string NUMERO_JUGADOR_1 = "1";
const std::string NUMERO_JUGADOR_2 = "2";
const int MAX_COORDENADAS = 2;
const int INDICE_FILA = 0;
const int INDICE_COLUMNA = 1;
const int CANTIDAD_OBJETIVOS_SECUNDARIOS_JUGADOR = 3;
const int CANTIDAD_OBJETIVOS_POR_JUGADOR = 4;

// CASILLEROS
const char LAGO = 'L';
const char TERRENO = 'T';
const char CAMINO = 'C';
const char BETUN = 'B';
const char MUELLE = 'M';

// COSTOS DE CAMINOS(energia)
const int COSTO_CAMINO = 4;
const int COSTO_BETUN = 0;
const int COSTO_LAGO_JUGADOR_1 = 2;
const int COSTO_LAGO_JUGADOR_2 = 5;
const int COSTO_MUELLE_JUGADOR_1 = 5;
const int COSTO_MUELLE_JUGADOR_2 = 2;
const int COSTO_TERRENO = 25;

// PRECIOS
const int COSTO_ANDYCOINS_BOMBA = 100;

// SIMBOLOGÍA TERRENOS
const std::string SIMBOLO_MUELLE = FONDO_MARRON + VACIO + VACIO + COLOR_POR_DEFECTO;
const std::string SIMBOLO_TERRENO = FONDO_VERDE + VACIO + VACIO + COLOR_POR_DEFECTO;
const std::string SIMBOLO_LAGO = FONDO_AZUL + VACIO + VACIO + COLOR_POR_DEFECTO;
const std::string SIMBOLO_CAMINO = FONDO_GRIS + VACIO + VACIO + COLOR_POR_DEFECTO;
const std::string SIMBOLO_BETUN = FONDO_BLANCO + VACIO + VACIO + COLOR_POR_DEFECTO;

// DISEÑOS
const std::string LINEA_DIVISORIA = "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550";
const std::string LINEA_DIVISORIA_DISENIO = "ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð\n";
const std::string LINEA_SUPERIOR_SIMBOLOGIA = COLOR_DORADO + " ╔■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■╗\n" + COLOR_POR_DEFECTO;
const std::string LINEA_INFERIOR_SIMBOLOGIA = COLOR_DORADO + " ╚■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■═■╝\n" + COLOR_POR_DEFECTO;
const std::string LINEA_DIVISORIA_MENSAJE_MENU = "───────────────────────────────────────────";

// MENSAJES ASCII
const std::string MENSAJE_ANDYPOLIS = R"(
░█████╗░███╗░░██╗██████╗░██╗░░░██╗██████╗░░█████╗░██╗░░░░░██╗░██████╗
██╔══██╗████╗░██║██╔══██╗╚██╗░██╔╝██╔══██╗██╔══██╗██║░░░░░██║██╔════╝
███████║██╔██╗██║██║░░██║░╚████╔╝░██████╔╝██║░░██║██║░░░░░██║╚█████╗░
██╔══██║██║╚████║██║░░██║░░╚██╔╝░░██╔═══╝░██║░░██║██║░░░░░██║░╚═══██╗
██║░░██║██║░╚███║██████╔╝░░░██║░░░██║░░░░░╚█████╔╝███████╗██║██████╔╝
╚═╝░░╚═╝╚═╝░░╚══╝╚═════╝░░░░╚═╝░░░╚═╝░░░░░░╚════╝░╚══════╝╚═╝╚═════╝░
)";

const std::string MENSAJE_JUGADOR_1 = R"( 
░░░▒█ ▒█░▒█ ▒█▀▀█ ░█▀▀█ ▒█▀▀▄ ▒█▀▀▀█ ▒█▀▀█ 　 ▄█░
░▄░▒█ ▒█░▒█ ▒█░▄▄ ▒█▄▄█ ▒█░▒█ ▒█░░▒█ ▒█▄▄▀ 　 ░█░
▒█▄▄█ ░▀▄▄▀ ▒█▄▄█ ▒█░▒█ ▒█▄▄▀ ▒█▄▄▄█ ▒█░▒█ 　 ▄█▄
)"; 

const std::string MENSAJE_JUGADOR_2 = R"(
░░░▒█ ▒█░▒█ ▒█▀▀█ ░█▀▀█ ▒█▀▀▄ ▒█▀▀▀█ ▒█▀▀█ 　 █▀█
░▄░▒█ ▒█░▒█ ▒█░▄▄ ▒█▄▄█ ▒█░▒█ ▒█░░▒█ ▒█▄▄▀ 　 ░▄▀
▒█▄▄█ ░▀▄▄▀ ▒█▄▄█ ▒█░▒█ ▒█▄▄▀ ▒█▄▄▄█ ▒█░▒█ 　 █▄▄
)"; 

const std::string MENSAJE_FELICIDADES = R"(
▒█▀▀▀ ▒█▀▀▀ ▒█░░░ ▀█▀ ▒█▀▀█ ▀█▀ ▒█▀▀▄ ░█▀▀█ ▒█▀▀▄ ▒█▀▀▀ ▒█▀▀▀█  ░█▀▀█ ─█▀▀█ ░█▄─░█ ─█▀▀█ ░█▀▀▀█ ▀▀█▀▀ ░█▀▀▀
▒█▀▀▀ ▒█▀▀▀ ▒█░░░ ▒█░ ▒█░░░ ▒█░ ▒█░▒█ ▒█▄▄█ ▒█░▒█ ▒█▀▀▀ ░▀▀▀▄▄  ░█─▄▄ ░█▄▄█ ░█░█░█ ░█▄▄█ ─▀▀▀▄▄ ─░█── ░█▀▀▀
▒█░░░ ▒█▄▄▄ ▒█▄▄█ ▄█▄ ▒█▄▄█ ▄█▄ ▒█▄▄▀ ▒█░▒█ ▒█▄▄▀ ▒█▄▄▄ ▒█▄▄▄█  ░█▄▄█ ░█─░█ ░█──▀█ ░█─░█ ░█▄▄▄█ ─░█── ░█▄▄▄
)";

const std::string MENSAJE_CREDITOS = R"(
───────────────────────────────────────────
██████████████████████████████████████████████
█─▄▄▄─█▄─▄▄▀█▄─▄▄─█▄─▄▄▀█▄─▄█─▄─▄─█─▄▄─█─▄▄▄▄█
█─███▀██─▄─▄██─▄█▀██─██─██─████─███─██─█▄▄▄▄─█
▀▄▄▄▄▄▀▄▄▀▄▄▀▄▄▄▄▄▀▄▄▄▄▀▀▄▄▄▀▀▄▄▄▀▀▄▄▄▄▀▄▄▄▄▄▀
───────────────────────────────────────────
)";

const std::string MENSAJE_BRAYAN = R"(
█▄▄ █▀█ ▄▀█ █▄█ ▄▀█ █▄█   █▀ ▄▀█ █ ▄▀█ █▀▀ █▀█
█▄█ █▀▄ █▀█  █  █▀█ █▀█   ▄█ █▀█ █ █▀█ █▄█ █▄█
)";

const std::string MENSAJE_SEBASTIAN = R"(
█▀ █▀▀ █▄▄ ▄▀█ █▀ ▀█▀ █ ▄▀█ █▄█   █▄▄ █▀█ █ ▀█ █ █ █▀▀ █   ▄▀█
▄█ ██▄ █▄█ █▀█ ▄█  █  █ █▀█ █▀█   █▄█ █▀▄ █ █▄ █▄█ ██▄ █▄▄ █▀█
)";

const std::string MENSAJE_FRANCO = R"(
█▀▀ █▀█ ▄▀█ █▄█ █▀▀ █▀█   █   █▀█ █▀ ▄▀█ █▀█ █▀▄ █▀█
█▀  █▀▄ █▀█ █▀█ █▄▄ █▄█   █▄▄ █▄█ ▄█ █▀█ █▀▄ █▄▀ █▄█
)";

const std::string MENSAJE_EZEQUIEL = R"(
█▀▀ ▀█ █▀▀ █▀█ █ █ █ █▀▀ █     █   ▄▀█ █▀ █▀ ▄▀█ █   █   █▀▀
██▄ █▄ ██▄ ▀▀█ █▄█ █ ██▄ █▄▄   █▄▄ █▀█ ▄█ ▄█ █▀█ █▄▄ █▄▄ ██▄
)";

#endif //_CONSTANTES_H_