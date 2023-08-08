#pragma once

#include <string>

#include "GameObject.h"

class SDLGameObject : public GameObject {
 protected:
  int x;
  int y;

  int width;
  int height;

  int currentRow;
  int currentFrame;

  std::string textureId;

 public:
  SDLGameObject(const LoaderParams* params);

  virtual void draw();
  virtual void update();
  virtual void clean();
};
