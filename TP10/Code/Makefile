CC=gcc -Wall
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
	$(CC) -o $@ $^ -lm

./$(BINDIR)%.o: ./$(SRCDIR)%.c
	$(CC) -o $@ -c $< -lm
	
.PHONY: clean save restore doc

clean:
	$(RM) $(BINDIR)*.o

save:
	$(RM) $(SAVEDIR)* | cp $(SRCDIR)* $(SAVEDIR)

restore:
	$(RM) $(SRCDIR)* | cp $(SAVEDIR)* $(SRCDIR)

doc:
	doxygen Doxyfile