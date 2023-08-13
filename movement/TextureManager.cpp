#include <SDL2/SDL_image.h>

#include <iostream>
#include <string>

#include "TextureManager.h"

TextureManager* TextureManager::instance = nullptr;

bool TextureManager::load(std::string fileName, std::string id,
                          SDL_Renderer* renderer) {
  SDL_Surface* tempSurface = IMG_Load(fileName.c_str());

  if (tempSurface == nullptr) return false;

  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);

  SDL_FreeSurface(tempSurface);

  if (texture) {
    textureMap[id] = texture;
    return true;
  }

  return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height,
                          SDL_Renderer* renderer, SDL_RendererFlip flip) {
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = 0;
  srcRect.y = 0;
  destRect.w = srcRect.w = width;
  destRect.h = srcRect.h = height;
  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopyEx(renderer, textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width,
                               int height, int currentRow, int currentFrame,
                               SDL_Renderer* renderer, SDL_RendererFlip flip) {
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = width * currentFrame;
  srcRect.y = height * (currentRow - 1);
  destRect.w = srcRect.w = width;
  destRect.h = srcRect.h = height;
  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopyEx(renderer, textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
