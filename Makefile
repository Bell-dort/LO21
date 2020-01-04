DEBUG=yes
CC=gcc
ifeq ($(DEBUG), yes)
	CFLAGS=-W -Wall -pedantic -g
	LDFLAGS=-lm
else
	CFLAGS=-W -Wall -pedantic
	LDFLAGS=-lm
endif
EXEC=projet
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)


all: $(EXEC)
ifeq ($(DEBUG), yes)
	@echo "Génération en mode debug"
else
	@echo "Génération en mode release"
endif

$(EXEC): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
