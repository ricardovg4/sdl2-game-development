#pragma once

#include <string>

#include "GameObject.h"
#include "Vector2D.cpp"

class SDLGameObject : public GameObject {
 protected:
  Vector2D position;
  Vector2D velocity;
  Vector2D acceleration;

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
