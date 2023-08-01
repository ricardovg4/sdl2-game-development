CC=g++
CFLAGS=-Wall
# OBJECTS=main.o
SOURCES=main.cpp Game.cpp
BIN=./bin/
LIBS=-l SDL2
DEBUG_FLAG=-g
PROGRAM=skeleton

all: $(PROGRAM) run

$(PROGRAM): $(SOURCES)
	$(CC) $(SOURCES) -o $(BIN)$@ $(LIBS)

run: $(PROGRAM)
	$(BIN)$(PROGRAM)

clean:
	rm -rf $(PROGRAM) ./*.o
