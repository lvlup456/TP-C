CC=gcc -Wall
RM=rm -rf
PROG=toto

SRCDIR = src/
BINDIR = bin/
DOCDIR = doc/
SAVEDIR = save/

SRC = $(wildcard $(SRCDIR)*.c)
HEAD= $(wildcard $(SRCDIR)*.h)
OBJ = $(subst $(SRCDIR), $(BINDIR),$(SRC:.c=.o))

all: $(PROG)

toto:$(OBJ)
	$(CC) -o $@ $^

./$(BINDIR)%.o: ./$(SRCDIR)%.c
	$(CC) -o $@ -c $< 
	
.PHONY: clean save

clean:
	$(RM) $(BINDIR)*.o

save:
	$(RM) $(SAVEDIR)* | cp $(SRCDIR)* $(SAVEDIR)
