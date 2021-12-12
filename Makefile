CC = g++
CFLAGS = -Wall -Werror -Wconversion
SRCDIR = archivos_cpps/
DIR_MATERIALES = archivos_cpps/materiales/
DIR_CONSTRUCCIONES = archivos_cpps/construcciones/
DIR_CASILLEROS = archivos_cpps/casillero/
DIR_MENU = archivos_cpps/menu/
DIR_OBJETIVOS = archivos_cpps/objetivos/
DIR_DATOS = archivos_cpps/carga_de_datos/
DIR_ABB = archivos_cpps/arbol/
DIR_JUEGO = archivos_cpps/juego/
DIR_PROGRAMA = archivos_cpps/programa/
DIR_GRAFOS = archivos_cpps/grafos/

main:
	g++ $(CFLAGS) $(SRCDIR)*.cpp $(DIR_PROGRAMA)*.cpp $(DIR_JUEGO)*.cpp $(DIR_MATERIALES)*.cpp $(DIR_DATOS)*.cpp $(DIR_CONSTRUCCIONES)*.cpp $(DIR_CASILLEROS)*.cpp $(DIR_MENU)*.cpp $(DIR_OBJETIVOS)*.cpp $(DIR_GRAFOS)*.cpp $(DIR_ABB)*.cpp -g -o Andypolis

valgrind: 
	valgrind --tool=memcheck --track-origins=yes --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./Andypolis
