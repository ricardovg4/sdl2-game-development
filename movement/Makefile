CC=g++
CFLAGS=-Wall
# OBJECTS=main.o
SOURCES=main.cpp Game.cpp TextureManager.cpp Player.cpp Enemy.cpp LoaderParams.cpp SDLGameObject.cpp InputHandler.cpp
BIN=./bin/
LIBS=-l SDL2 -l SDL2_image
DEBUG_FLAG=-g
PROGRAM=movement

all: $(PROGRAM) run

$(PROGRAM): $(SOURCES)
	$(CC) $(SOURCES) -o $(BIN)$@ $(LIBS)

run: $(PROGRAM)
	$(BIN)$(PROGRAM)

clean:
	rm -rf $(BIN)$(PROGRAM) ./*.o
