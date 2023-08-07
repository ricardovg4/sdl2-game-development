#include <SDL2/SDL_timer.h>

#include "Game.h"

Game* game = nullptr;

int main() {
  game = new Game();

  game->init("skeleton", 100, 100, 640, 480, true);

  while (game->getRunning()) {
    game->handleEvents();
    game->update();
    game->render();

    SDL_Delay(10);
  }

  game->clean();

  return 0;
}
