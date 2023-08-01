#include "Game.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

#include <iostream>

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
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  running = true;

  return true;
}

void Game::render() {
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
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
