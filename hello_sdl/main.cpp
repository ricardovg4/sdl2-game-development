#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <iostream>

SDL_Window* window = 0;
SDL_Renderer* renderer = 0;

int main() {
  // initialize SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
    window = SDL_CreateWindow("Hello SDL!", 0, 0, 640, 480, SDL_WINDOW_SHOWN);

    if (window) {
      renderer = SDL_CreateRenderer(window, -1, 0);
    } else {
      // couldn't initialize
      return 1;
    }

    // set to black
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // clear the window to black
    SDL_RenderClear(renderer);

    // show the window
    SDL_RenderPresent(renderer);

    // delay before quitting
    SDL_Delay(2000);
    SDL_Quit();

    std::cout << "hello sdl2";
    return 0;
  }
}
