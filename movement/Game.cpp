#include "Game.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keyboard.h>

#include <iostream>

#include "Enemy.h"
#include "InputHandler.h"
#include "LoaderParams.h"
#include "Player.h"
#include "TextureManager.h"

Game* Game::instance = nullptr;

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

  GameObjects.push_back(
      new Player(new LoaderParams(100, 100, 128, 82, "animate")));
  GameObjects.push_back(
      new Enemy(new LoaderParams(100, 100, 128, 82, "animate")));

  return true;
}

void Game::render() {
  SDL_RenderClear(renderer);

  // loop through GameObjects and drwa them
  for (std::vector<GameObject*>::size_type i = 0; i != GameObjects.size();
       i++) {
    GameObjects[i]->draw();
  }

  SDL_RenderPresent(renderer);
}

void Game::update() {
  for (std::vector<GameObject*>::size_type i = 0; i != GameObjects.size();
       i++) {
    GameObjects[i]->update();
  }
}

void Game::clean() {
  std::cout << "cleaning up"
            << "\n";
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

void Game::quit() { running = false; }

void Game::handleEvents() {
  InputHandler::getInstance()->update();
}
