COMPILER=gcc
OUTPUT_FILE=final.out

all: compile
	rm -r *.o *.h.gch

compile: TAD.o validaciones.o
	$(COMPILER) -pedantic -std=c99 -Wall -fsanitize=address -o $(OUTPUT_FILE) main.c TAD.o validaciones.o

TAD.o: TAD.c TAD.h
	$(COMPILER) -c TAD.c TAD.h

validaciones.o:  validaciones.c validaciones.h
	$(COMPILER) -c validaciones.c validaciones.h