#include <SDL2/SDL.h>

#include <string>

#include "GameObject.h"

class Player : public GameObject {
 public:
  void load(int x, int y, int width, int height, std::string textureId);
  void draw(SDL_Renderer* renderer);
  void update();
  void clean();
};
