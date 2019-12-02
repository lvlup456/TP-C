CC=gcc -Wall
RM=rm -rf
SRC= $(wildcard *.c)
HEAD= $(wildcard *.h)
OBJ= $(SRC:.c=.o)
PROG=toto

all: $(PROG)

toto:$(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $< 


.PHONY: clean

clean:
	$(RM) *.o