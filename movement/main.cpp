#include <SDL2/SDL_error.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>

#include <iostream>

#include "Game.h"

// Game* game = nullptr;

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main() {
  Uint32 frameStart;
  Uint32 frameTime;

  std::cout << "game initializing...\n";
  if (Game::getInstance()->init("Chapter 4", 100, 100, 640, 480, false)) {
    std::cout << "game init success\n";
    while (Game::getInstance()->getRunning()) {
      frameStart = SDL_GetTicks();

      Game::getInstance()->handleEvents();
      Game::getInstance()->update();
      Game::getInstance()->render();

      frameTime = SDL_GetTicks() - frameStart;

      if (frameTime < DELAY_TIME) {
        SDL_Delay((int)(DELAY_TIME - frameTime));
      }
    }
  } else {
    std::cout << "game initialization failed - " << SDL_GetError() << "\n";
    return -1;
  }

  std::cout << "game closing...\n";
  Game::getInstance()->clean();

  return 0;
}
