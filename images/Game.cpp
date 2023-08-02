#include "Game.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  running = true;

  SDL_Surface* tempSurface = IMG_Load("assets/animate-alpha.png");
  texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
  SDL_FreeSurface(tempSurface);

  // SDL_QueryTexture(texture, NULL, NULL, &sourceRectangle.w,
  // &sourceRectangle.h);
  sourceRectangle.w = 128;
  sourceRectangle.h = 82;
  destinationRectangle.x = sourceRectangle.x = 0;
  destinationRectangle.y = sourceRectangle.y = 0;
  destinationRectangle.w = sourceRectangle.w;
  destinationRectangle.h = sourceRectangle.h;

  return true;
}

void Game::render() {
  SDL_RenderClear(renderer);

  // SDL_RenderCopy(renderer, texture, &sourceRectangle, &destinationRectangle);
  SDL_RenderCopyEx(renderer, texture, &sourceRectangle, &destinationRectangle,
                   0, 0, SDL_FLIP_HORIZONTAL);

  SDL_RenderPresent(renderer);
}

void Game::update() {
  sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
  std::cout << sourceRectangle.x << "\n";
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
