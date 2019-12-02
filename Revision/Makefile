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
	$(CC) -o $@ $^

./$(BINDIR)%.o: ./$(SRCDIR)%.c
	$(CC) -o $@ -c $< 
	
.PHONY: clean save restore doc

clean:
	$(RM) $(BINDIR)*.o

save:
	$(RM) $(SAVEDIR)* | cp $(SRCDIR)* $(SAVEDIR)

restore:
	$(RM) $(SRCDIR)* | cp $(SAVEDIR)* $(SRCDIR)

doc:
	doxygen Doxyfile