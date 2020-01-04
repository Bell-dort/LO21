
CC=gcc
EXEC = prog
SRC = $(willcard *.c)
OBJ = $(SRC:.c=.o)

all: $(EXEC)

%.o : %.c
	$(CC) -o $@ -c $<

$(EXEC) : $(OBJ)
		$(CC) -o $@ $^ -lm 

clean: 
	rm -rf *.o $(EXEC)