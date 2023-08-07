#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

#include <vector>

#include "GameObject.h"

class Game {
  SDL_Window* window;
  SDL_Renderer* renderer;

  bool running;

  GameObject* go;
  GameObject* player;
  GameObject* enemy;

  std::vector<GameObject*> GameObjects;

 public:
  bool init(const char* title, int xpos, int ypos, int width, int height,
            bool fullscreen);
  void handleEvents();
  void update();
  void render();
  void clean();

  bool getRunning() { return running; };
};
