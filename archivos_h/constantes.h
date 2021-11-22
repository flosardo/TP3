#ifndef _CONSTANTES_H_
#define _CONSTANTES_H_

#include <iostream>

//MATERIALES
const char PIEDRA = 'S';
const char METAL = 'I';
const char MADERA = 'W';
const char BOMBA = 'Z';
const char ANDYCOINS = 'C';
const char ENERGIA = 'X';
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

//COLORES
const std::string COLOR_POR_DEFECTO = "\033[0m";
const std::string COLOR_ROJO = "\033[38;5;196m";
const std::string COLOR_VERDE = "\033[38;5;46m";
const std::string COLOR_VERDE_AGUA = "\033[38;5;35m";
const std::string COLOR_MARRON = "\033[38;5;136m";
const std::string COLOR_DORADO = "\x1b[33m";

const std::string FONDO_AZUL = "\033[48;5;27m";
const std::string FONDO_VERDE = "\033[48;5;2m";
const std::string FONDO_GRIS = "\033[48;5;240m";

//EMOJIS MATERIALES
const std::string EMOJI_PIEDRA = "\U0001f311";
const std::string EMOJI_METAL = "\u2699";
const std::string EMOJI_MADERA = "\U0001f954";
const std::string EMOJI_ENERGIA = "\u26A1";
const std::string EMOJI_ANDYCOIN = "\U0001fa99";
const std::string EMOJI_BOMBA = "\U0001f4a3";
const std::string EMOJI_CAMINO = "\U0001f6e4";
const int LIMITE_INFERIOR_PIEDRA = 1;
const int LIMITE_SUPERIOR_PIEDRA = 2;
const int CANTIDAD_PRODUCIDA_PIEDRA = 100;
const int LIMITE_INFERIOR_MADERA = 0;
const int LIMITE_SUPERIOR_MADERA =3;
const int CANTIDAD_PRODUCIDA_MADERA = 50;
const int LIMITE_INFERIOR_METAL = 2;
const int LIMITE_SUPERIOR_METAL = 4;
const int CANTIDAD_PRODUCIDA_METAL = 50;
const int LIMITE_INFERIOR_ANDYCOINS = 0;
const int LIMITE_SUPERIOR_ANDYCOINS = 1;
const int CANTIDAD_PRODUCIDA_ANDYCOINS = 250;
const int MIN_CANTIDAD_MATERIAL_PRODUCIDO = 0;

//EMOJIS EDIFICIOS
const std::string EMOJI_PLANTA_ELECTRICA = "\U0001f3e4";
const std::string EMOJI_MINA_ORO = "\U0001f682";
const std::string EMOJI_MINA = "\U0001f68a";
const std::string EMOJI_ASERRADERO = "\U0001f3ec";
const std::string EMOJI_ESCUELA = "\U0001f3eb";
const std::string EMOJI_FABRICA = "\U0001f3ed";
const std::string EMOJI_OBELISCO = "\U0001f5fc";
const std::string EMOJI_TERRENO = "\U0001f3d7";

//RUTAS ARCHIVOS
const std::string RUTA_MATERIALES = "archivos_de_texto/materiales.txt";
const std::string RUTA_EDIFICIOS = "archivos_de_texto/edificios.txt";
const std::string RUTA_MAPA = "archivos_de_texto/mapa.txt";
const std::string RUTA_UBICACIONES = "archivos_de_texto/ubicaciones.txt";

//EDIFICIOS
const char FABRICA = 'F';
const char OBELISCO = 'O';
const char MINA_ORO = 'G';
const char PLANTA_ELECTRICA = 'P';
const char ESCUELA = 'E';
const char MINA = 'M';
const char ASERRADERO = 'A';
const int MAX_EDIFICIOS_DISPONIBLES = 7;
const int ENERGIA_CONSTRUIR_EDIFICIO = 15;
const int ENERGIA_DEMOLER_EDIFICIO_COORDENADA = 15;
const int ENERGIA_ATACAR_EDIFICIO_COORDENADA = 30;
const int ENERGIA_REPARAR_EDIFICIO = 25;
const int ENERGIA_COMPRAR_BOMBA = 5;
const int ENERGIA_RECOLECTAR_RECURSOS = 20;
const std::string NOMBRE_PLANTA_ELECTRICA = "planta electrica";
const std::string NOMBRE_ASERRADERO = "aserradero";
const std::string NOMBRE_ESCUELA = "escuela";
const std::string NOMBRE_FABRICA = "fabrica";
const std::string NOMBRE_OBELISCO = "obelisco";
const std::string NOMBRE_MINA = "mina";
const std::string NOMBRE_MINA_ORO = "mina oro";

//OBJETIVOS 
const std::string NOMBRE_OBJETIVO_ANDYCOINS = "andycoins por los cielos";
const std::string NOMBRE_OBJETIVO_OBELISCO = "mas alto que las nubes";
const std::string NOMBRE_OBJETIVO_PIEDRA = "edad de piedra";
const std::string NOMBRE_OBJETIVO_MINERO = "minero";
const std::string NOMBRE_OBJETIVO_BOMBARDERO = "bombardero";
const std::string NOMBRE_OBJETIVO_EXTREMISTA = "extremista taliban";
const std::string NOMBRE_OBJETIVO_ENERGETICO = "energetico";
const std::string NOMBRE_OBJETIVO_LETRADO = "intelectual";
const std::string NOMBRE_OBJETIVO_CANSADO = "cansado";
const std::string NOMBRE_OBJETIVO_CONSTRUCTOR = "many a la obra (bob constructor)";
const std::string NOMBRE_OBJETIVO_ARMADO = "terrorista (full armado)";

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

//DISEÑOS
const std::string LINEA_DIVISORIA = "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550";
const std::string LINEA_DIVISORIA_DISENIO = "══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð══ð\n";

//JUGADORES
const char JUGADOR_1 = 'J';
const char JUGADOR_2 = 'U';
const int MAX_COORDENADAS = 2;
const int POSICION_FILA = 0;
const int POSICION_COLUMNA = 1;

//CASILLEROS
const char LAGO = 'L';
const char TERRENO = 'T';
const char CAMINO = 'C';
const char BETUN = 'B';
const char MUELLE = 'M';

#endif // _CONSTANTES_H_