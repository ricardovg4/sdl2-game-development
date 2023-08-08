#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

#include <variant>
#include <vector>

#include "GameObject.h"

class Game {
 private:
  Game() = default;
  static Game* instance;

  SDL_Window* window;
  SDL_Renderer* renderer;

  bool running;

  GameObject* go;
  GameObject* player;
  GameObject* enemy;

  std::vector<GameObject*> GameObjects;

 public:
  static Game* getInstance() {
    if (instance == nullptr) {
      instance = new Game();
      return instance;
    }
    return instance;
  }

  SDL_Renderer* getRenderer() const { return renderer; }

  bool init(const char* title, int xpos, int ypos, int width, int height,
            bool fullscreen);
  void handleEvents();
  void update();
  void render();
  void clean();

  bool getRunning() { return running; };
};
