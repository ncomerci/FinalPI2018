COMPILER=gcc
OUTPUT_FILE=final.out

all: TAD.o getnum.o
	$(COMPILER) -pedantic -std=c99 -Wall -fsanitize=address -o $(OUTPUT_FILE) main.c TAD.o getnum.o

TAD.o: TAD.c header.h
	$(COMPILER) -c TAD.c header.h

getnum.o:  getnum.c getnum.h
	$(COMPILER) -c getnum.c getnum.h

clean:
	rm -rv $(OUTPUT_FILE) *.o *.h.gch