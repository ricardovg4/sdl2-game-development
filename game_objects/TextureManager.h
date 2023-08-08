#include <SDL2/SDL.h>

#include <map>
#include <string>

class TextureManager {
  TextureManager() = default;
  ~TextureManager();

  static TextureManager* instance;

 public:
  static TextureManager* getInstance() {
    if (instance == nullptr) {
      instance = new TextureManager();
      return instance;
    }

    return instance;
  }

  std::map<std::string, SDL_Texture*> textureMap;

  bool load(std::string fileName, std::string id, SDL_Renderer* renderer);

  void draw(std::string id, int x, int y, int width, int height,
            SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

  void drawFrame(std::string id, int x, int y, int width, int height,
                 int currentRow, int currentFrame, SDL_Renderer* renderer,
                 SDL_RendererFlip flip = SDL_FLIP_NONE);
};
