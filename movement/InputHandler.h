#include <SDL2/SDL.h>

class InputHandler {
 private:
  InputHandler() = default;
  ~InputHandler();
  static InputHandler* instance;

  //handle keyboard events
  void onKeyDown();
  void onKeyUp();

 public:
  const Uint8* keystates;

  static InputHandler* getInstance() {
    if (instance == nullptr) {
      instance = new InputHandler();
    }
    return instance;
  }

  bool isKeyDown(SDL_Scancode);

  void update();
  void clean();
};
