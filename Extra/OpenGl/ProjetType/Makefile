CC=gcc -Wall
RM=rm -rf
PROG=prgm
OPENGL=-lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl

SRCDIR = src/
BINDIR = bin/
DOCDIR = doc/
SAVEDIR = save/

SRC = $(wildcard $(SRCDIR)*.c)
HEAD= $(wildcard $(SRCDIR)*.h)
OBJ = $(subst $(SRCDIR), $(BINDIR),$(SRC:.c=.o))

all: $(PROG)

prgm:$(OBJ)
	$(CC) -o $@ $^ $(OPENGL)

./$(BINDIR)%.o: ./$(SRCDIR)%.c
	$(CC) -o $@ -c $< $(OPENGL)
	
.PHONY: clean save restore doc

clean:
	$(RM) $(BINDIR)*.o

save:
	$(RM) $(SAVEDIR)* | cp $(SRCDIR)* $(SAVEDIR)

restore:
	$(RM) $(SRCDIR)* | cp $(SAVEDIR)* $(SRCDIR)

doc:
	doxygen Doxyfile