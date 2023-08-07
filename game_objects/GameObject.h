#include <SDL2/SDL.h>

#include <string>

class GameObject {
 public:
  virtual void load(int x, int y, int width, int height, std::string textureId);
  virtual void draw(SDL_Renderer* renderer);
  virtual void update();
  virtual void clean();

 protected:
  std::string textureId;

  int currentFrame;
  int currentRow;

  int x;
  int y;

  int width;
  int height;
};
