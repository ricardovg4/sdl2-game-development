#include <SDL2/SDL.h>

#include <string>

#include "SDLGameObject.h"

class Enemy : public SDLGameObject {
 public:
  Enemy(const LoaderParams* params);

  void draw();
  void update();
  void clean();
};
