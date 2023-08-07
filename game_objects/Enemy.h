#include <SDL2/SDL.h>

#include <string>

#include "GameObject.h"

class Enemy : public GameObject {
 public:
  void load(int x, int y, int widht, int height, std::string textureId);
  void draw(SDL_Renderer *renderer);
  void update();
  void clean();
};
