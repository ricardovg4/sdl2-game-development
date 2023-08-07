#include "Enemy.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

void Enemy::load(int x, int y, int width, int height, std::string textureId) {
  GameObject::load(x, y, width, height, textureId);
}

void Enemy::draw(SDL_Renderer* renderer) { GameObject::draw(renderer); }

void Enemy::update() {
  y += 1;
  x += 1;
  currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean() {}
