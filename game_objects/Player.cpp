#include "Player.h"

#include <SDL2/SDL.h>

void Player::load(int x, int y, int width, int height, std::string textureId) {
  GameObject::load(x, y, width, height, textureId);
}

void Player::draw(SDL_Renderer* renderer) { GameObject::draw(renderer); }

void Player::update() { x -= 1; }

void Player::clean() {}
