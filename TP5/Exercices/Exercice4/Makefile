CC=gcc -Wall
RM=rm -rf
SRC=main.c gui.c
HEAD=gui.h
OBJ=gui.o main.o
PROG=toto

all: $(PROG)

toto:$(OBJ)
	$(CC) -o $@ $^

main.o: main.c gui.o
	$(CC) -o $@ -c $< 

gui.o: gui.c
	$(CC) -o $@ -c $<

clean:
	$(RM) *.o