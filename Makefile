 
CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-lm
EXEC=projet
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf *.o

cleanall: clean
	@rm -rf $(EXEC)
