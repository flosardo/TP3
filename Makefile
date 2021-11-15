CC = g++
CFLAGS = -Wall -Werror -Wconversion
SRCDIR = archivos_cpps/
DIR_MATERIALES = archivos_cpps/materiales/

main:
	g++ $(CFLAGS) $(SRCDIR)*.cpp $(DIR_MATERIALES)*.cpp -o Andypolis

valgrind: 
	valgrind --tool=memcheck --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./Andypolis