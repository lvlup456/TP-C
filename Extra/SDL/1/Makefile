CC=gcc -Wall -Wextra
SDL=`sdl2-config --cflags --libs`
RM=rm -rf
PROG=prgm

SRCDIR = src/
BINDIR = bin/
DOCDIR = doc/
SAVEDIR = save/

SRC = $(wildcard $(SRCDIR)*.c)
HEAD= $(wildcard $(SRCDIR)*.h)
OBJ = $(subst $(SRCDIR), $(BINDIR),$(SRC:.c=.o))

all: $(PROG)

prgm:$(OBJ)
	$(CC) -o $@ $^ $(SDL)

./$(BINDIR)%.o: ./$(SRCDIR)%.c
	$(CC) -o $@ -c $< $(SDL)
	
.PHONY: clean save restore doc

clean:
	$(RM) $(BINDIR)*.o

save:
	$(RM) $(SAVEDIR)* | cp $(SRCDIR)* $(SAVEDIR)

restore:
	$(RM) $(SRCDIR)* | cp $(SAVEDIR)* $(SRCDIR)

doc:
	doxygen Doxyfile