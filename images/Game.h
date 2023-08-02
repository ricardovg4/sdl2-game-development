#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

class Game {
  SDL_Window* window;
  SDL_Renderer* renderer;
  
  SDL_Texture* texture;
  SDL_Rect sourceRectangle;
  SDL_Rect destinationRectangle;

  bool running;

public:
  bool init(const char* title, int xpos, int ypos, int width, int height,
            bool fullscreen);
  void handleEvents();
  void update();
  void render();
  void clean();

  bool getRunning() { return running; };
};
