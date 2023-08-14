#include "Player.h"
#include "InputHandler.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_scancode.h>

Player::Player(const LoaderParams* params) : SDLGameObject(params){};

void Player::draw() { SDLGameObject::draw(); }

void Player::update() {
  currentFrame = int(((SDL_GetTicks() / 100) % 6));
  // acceleration.setX(1);
  if (InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_RIGHT)){
    velocity.setX(2);
  }
  if (InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_LEFT)){
    velocity.setX(-2);
  }
  if (InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_UP)){
    velocity.setY(-2);
  }
  if (InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_DOWN)){
    velocity.setY(2);
  }

  SDLGameObject::update();
}

void Player::clean() {}
