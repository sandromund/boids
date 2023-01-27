#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#include "boid.h"

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
      1600,
      800,
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

  // init a boid somewhere on the window
  Boid boid = {0};
  boid.position.x = 200;
  boid.position.y = 200;
  boid.velocity.x = -2;
  boid.velocity.y = 1;

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

    // update
    boid_update(&boid);

    // render
    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_RenderClear(r);

    // render a boid
    boid_render(&boid, r);

    SDL_RenderPresent(r);
  }

  SDL_DestroyRenderer(r);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
