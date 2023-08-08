#include <SDL2/SDL_error.h>
#include <SDL2/SDL_timer.h>

#include <iostream>

#include "Game.h"

// Game* game = nullptr;

int main() {
  std::cout << "game initializing...\n";
  if (Game::getInstance()->init("Chapter 4", 100, 100, 640, 480, false)) {
    std::cout << "game init success\n";
    while (Game::getInstance()->getRunning()) {
      Game::getInstance()->handleEvents();
      Game::getInstance()->update();
      Game::getInstance()->render();

      SDL_Delay(10);
    }
  } else {
    std::cout << "game initialization failed - " << SDL_GetError() << "\n";
    return -1;
  }

  std::cout << "game closing...\n";
  Game::getInstance()->clean();

  return 0;
}
