#include "Enemy.h"

#include <SDL2/SDL.h>

Enemy::Enemy(const LoaderParams* params) : SDLGameObject(params){};

void Enemy::draw() { SDLGameObject::draw(); }

void Enemy::update() {
  position.setX(position.getX() + 1);
  position.setY(position.getY() + 1);
  currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean() {}
