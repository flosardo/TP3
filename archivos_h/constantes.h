#include <iostream>

const char PIEDRA = 'S';
const int CANTIDAD_MAX_PIEDRA_GENERADA = 1;
const std::string EMOJI_PIEDRA = "\U0001f311";

const char METAL = 'I';
const int CANTIDAD_MAX_METAL_GENERADO = 1;
const std::string EMOJI_METAL = "\u2699";
const char DELIMITADOR = ' ';
const char MADERA = 'W';
const int CANTIDAD_MAX_MADERA_GENERADA = 1;
const char BOMBA = 'Z';
const char ANDYCOINS = 'C';
const int BRINDAR_MATERIALES_MINA = 15;//piedras
const int BRINDAR_MATERIALES_ASERRADERO = 25;//maderas
const int BRINDAR_MATERIALES_FABRICA = 40;//metales

const std::string EMOJI_MADERA = "\U0001f954";
const std::string RUTA_MATERIALES = "archivos_de_texto/materiales.txt";
const std::string RUTA_EDIFICIOS = "archivos_de_texto/edificios.txt";
const std::string RUTA_MAPA = "archivos_de_texto/mapa.txt";
const std::string RUTA_UBICACIONES = "archivos_de_texto/ubicaciones.txt";

const std::string LINEA_DIVISORIA = "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550";
const std::string COLOR_ROJO = "\033[38;5;196m";
const std::string COLOR_POR_DEFECTO = "\033[0m";
const std::string COLOR_VERDE = "\033[38;5;46m";
const std::string COLOR_VERDE_AGUA = "\033[38;5;35m";
const std::string COLOR_MARRON = "\033[38;5;136m";
const std::string FONDO_AZUL = "\033[48;5;27m";
const std::string FONDO_VERDE = "\033[48;5;2m";
const std::string FONDO_GRIS = "\033[48;5;240m";