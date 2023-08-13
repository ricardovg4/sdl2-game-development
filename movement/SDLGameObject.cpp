#include "SDLGameObject.h"

#include "Game.h"
#include "TextureManager.h"

SDLGameObject::SDLGameObject(const LoaderParams* params)
    : GameObject(params),
      position(params->getX(), params->getY()),
      velocity(0, 0),
      acceleration(0, 0) {
  width = params->getWidth();
  height = params->getHeight();
  textureId = params->getTextureId();

  currentRow = 1;
  currentFrame = 1;
}

void SDLGameObject::draw() {
  TextureManager::getInstance()->drawFrame(
      textureId, (int)position.getX(), (int)position.getY(), width, height,
      currentRow, currentFrame, Game::getInstance()->getRenderer());
}

void SDLGameObject::update() {
  position += velocity;
  velocity += acceleration;
}
void SDLGameObject::clean() {}
