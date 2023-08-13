#pragma once

#include <string>

class LoaderParams {
 private:
  int x;
  int y;

  int width;
  int height;

  std::string textureId;

 public:
  LoaderParams(int x, int y, int width, int height, std::string textureId);

  int getX() const { return x; }
  int getY() const { return y; }
  int getWidth() const { return width; }
  int getHeight() const { return height; }
  std::string getTextureId() const { return textureId; }
};
