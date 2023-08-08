#include "SDLGameObject.h"

#include "Game.h"
#include "TextureManager.h"

SDLGameObject::SDLGameObject(const LoaderParams* params) : GameObject(params) {
  x = params->getX();
  y = params->getY();
  width = params->getWidth();
  height = params->getHeight();
  textureId = params->getTextureId();

  currentRow = 1;
  currentFrame = 1;
}

void SDLGameObject::draw() {
  TextureManager::getInstance()->drawFrame(textureId, x, y, width, height,
                                           currentRow, currentFrame,
                                           Game::getInstance()->getRenderer());
}

void SDLGameObject::update() {}
void SDLGameObject::clean() {}
