#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

int main() {
  // initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
    return 1;
  }

  // initialize window
  SDL_Window* window = SDL_CreateWindow(
      "boids",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      800,
      600,
      0);
  if (window == NULL) {
    fprintf(stderr, "Could not initialize Window: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  // initialize renderer
  SDL_Renderer* r = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (r == NULL) {
    fprintf(stderr, "Could not initialize renderer: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }


  // game loop
  int isRunning = 1;
  while (isRunning) {
    // event loop
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          isRunning = 0;
          break;
      }
    }
    // draw something to test the renderer //XXX
    SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
    SDL_RenderClear(r);

    SDL_RenderPresent(r);
  }

  SDL_DestroyRenderer(r);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
