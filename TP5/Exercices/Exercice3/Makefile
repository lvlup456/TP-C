all: toto

toto: main.c gui.o
	gcc -o toto main.c gui.o 

gui.o: gui.c
	gcc -o gui.o -c gui.c

clean:
	rm -rf *.o