#include "Player.h"

#include <SDL2/SDL.h>

Player::Player(const LoaderParams* params) : SDLGameObject(params){};

void Player::draw() { SDLGameObject::draw(); }

void Player::update() {
  // position.setX(position.getX() - 1);
  currentFrame = int(((SDL_GetTicks() / 100) % 6));
  acceleration.setX(1);
  SDLGameObject::update();
}

void Player::clean() {}
