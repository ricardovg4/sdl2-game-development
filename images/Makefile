CC=g++
CFLAGS=-Wall
# OBJECTS=main.o
SOURCES=main.cpp Game.cpp
BIN=./bin/
LIBS=-l SDL2 -l SDL2_image
DEBUG_FLAG=-g
PROGRAM=images

all: $(PROGRAM) run

$(PROGRAM): $(SOURCES)
	$(CC) $(SOURCES) -o $(BIN)$@ $(LIBS)

run: $(PROGRAM)
	$(BIN)$(PROGRAM)

clean:
	rm -rf $(BIN)$(PROGRAM) ./*.o
