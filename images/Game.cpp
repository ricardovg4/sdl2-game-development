#include "Game.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

#include "TextureManager.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height,
                bool fullscreen) {
  int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) return false;
  std::cout << "SDL init sucess"
            << "\n";

  window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

  if (!window) return false;
  std::cout << "window created"
            << "\n";
  renderer = SDL_CreateRenderer(window, -1, 0);

  if (!renderer) return false;
  std::cout << "renderer created"
            << "\n";
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  running = true;

  // load
  if (!TextureManager::getInstance()->load("assets/animate-alpha.png",
                                           "animate", renderer)) {
    return false;
  }

  return true;
}

void Game::render() {
  SDL_RenderClear(renderer);

  // draw
  TextureManager::getInstance()->draw("animate", 0, 0, 128, 82, renderer);
  // TextureManager::getInstance()->drawFrame("animate", 0, 0, 128, 82, 1,
  // frame,
  //                                          renderer);

  SDL_RenderPresent(renderer);
}

void Game::update() {
  // sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
  // frame = int(((SDL_GetTicks() / 100) % 6));
}

void Game::clean() {
  std::cout << "cleaning up"
            << "\n";
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

void Game::handleEvents() {
  SDL_Event event;

  if (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;

      default:
        break;
    }
  }
}
