PROGFILE=fibonacci_experiments
EXT=cpp
CC=g++
OPT= -o
LIBS=

########################################
all:$(PROGFILE)

test: $(PROGFILE)
	./$(PROGFILE)

$(PROGFILE): $(PROGFILE).$(EXT)
	$(CC) $(PROGFILE).$(EXT) $(OPT) $(PROGFILE)

clean:
	rm $(PROGFILE)