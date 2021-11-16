CC = g++
CFLAGS = -Wall -Werror -Wconversion
SRCDIR = archivos_cpps/
DIR_MATERIALES = archivos_cpps/materiales/
DIR_CONSTRUCCIONES = archivos_cpps/construcciones/
DIR_CASILLEROS = archivos_cpps/casillero/

main:
	g++ $(CFLAGS) $(SRCDIR)*.cpp $(DIR_MATERIALES)*.cpp $(DIR_CONSTRUCCIONES)*.cpp $(DIR_CASILLEROS)*.cpp -o Andypolis

valgrind: 
	valgrind --tool=memcheck --tool=track-origins=yes --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./Andypolis