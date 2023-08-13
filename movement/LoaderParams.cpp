#include "LoaderParams.h"

LoaderParams::LoaderParams(int x, int y, int width, int height,
                           std::string textureId) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
  this->textureId = textureId;
}
