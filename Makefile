CC=gcc
C_STANDARD = -std=c99
CFLAGS = -c -Wall ${C_STANDARD}

all: executable

executable: main.o BibIndiv.o BibPop.o
		$(CC) -o executable main.o BibIndiv.o BibPop.o -lm 

main.o: main.c BibIndiv.h BibPop.h BibGeneral.h
		$(CC) -o main.o $(CFLAGS) main.c 

BibIndiv.o: BibIndiv.c BibIndiv.h BibGeneral.h
		$(CC) -o BibIndiv.o $(CFLAGS) BibIndiv.c 

BibPop.o: BibPop.c BibIndiv.h BibPop.h BibGeneral.h
	  $(CC) -o BibPop.o $(CFLAGS) BibPop.c 

clean: 
	rm -rf *.o executable