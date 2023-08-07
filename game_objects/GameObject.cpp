#include "GameObject.h"

#include <SDL2/SDL.h>

#include <string>

#include "TextureManager.h"

void GameObject::load(int x, int y, int width, int height,
                      std::string textureId) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
  this->textureId = textureId;

  currentRow = 1;
  currentFrame = 1;
}

void GameObject::draw(SDL_Renderer* renderer) {
  TextureManager::getInstance()->drawFrame(textureId, x, y, width, height,
                                           currentRow, currentFrame, renderer);
}

void GameObject::update() { this->x += 1; }

void GameObject::clean() {}
