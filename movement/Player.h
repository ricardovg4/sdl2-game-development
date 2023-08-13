#include <SDL2/SDL.h>

#include <string>

#include "SDLGameObject.h"

class Player : public SDLGameObject {
 public:
  Player(const LoaderParams* params);

  void draw();
  void update();
  void clean();
};
