#include "InputHandler.h"

#include "Game.h"

InputHandler* InputHandler::instance = nullptr;

void InputHandler::update() {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    // keystates = SDL_GetKeyboardState(0);

    if (event.type == SDL_QUIT) {
      Game::getInstance()->quit();
    }
    switch (event.type) {
      case SDL_QUIT:
        Game::getInstance()->quit();
        break;
      case SDL_KEYDOWN:
        onKeyDown();
        break;
      case SDL_KEYUP:
        onKeyUp();
        break;
      default:
        break;
    }
  }
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
  if (keystates != 0) {
    if (keystates[key] == 1) {
      return true;
    } else {
      return false;
    }
  }
  return false;
}

void InputHandler::onKeyUp(){
  keystates = SDL_GetKeyboardState(0);
}

void InputHandler::onKeyDown(){
  keystates = SDL_GetKeyboardState(0);
}
