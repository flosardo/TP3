CC = g++
CFLAGS = -Wall -Werror -Wconversion
SRCDIR = archivos_cpps/
DIR_MATERIALES = archivos_cpps/materiales/
DIR_CONSTRUCCIONES = archivos_cpps/construcciones/
DIR_CASILLEROS = archivos_cpps/casillero/
DIR_MENU = archivos_cpps/menu/
DIR_OBJETIVOS = archivos_cpps/objetivos/

main:
	g++ $(CFLAGS) $(SRCDIR)*.cpp $(DIR_MATERIALES)*.cpp $(DIR_CONSTRUCCIONES)*.cpp $(DIR_CASILLEROS)*.cpp $(DIR_MENU)*.cpp  $(DIR_OBJETIVOS)*.cpp -o Andypolis

valgrind: 
	valgrind --tool=memcheck --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./Andypolis
