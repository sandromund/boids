#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>
#include <stdbool.h>

#include "boid.h"
#include "constants.h"
#include "gamestate.h"

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
      WINDOW_WIDTH,
      WINDOW_HEIGHT,
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

  // initialize SDL_TTF
  if (TTF_Init() == -1) {
    fprintf(stderr, "Could not initialize TTF: %s\n", SDL_GetError());
    SDL_DestroyRenderer(r);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  // init random seed
  srand(time(NULL));

  // init gamestate
  Gamestate gamestate;
  gamestate.alignmentEnabled = true;
  gamestate.cohesionEnabled = true;
  gamestate.separationEnabled = true;
  gamestate.pauseEnabled = false;
  gamestate.fovEnabled = true;
  gamestate.stepEnabled = false;
  gamestate.debugViewEnabled = false;

  // init boids somewhere on the window
  for (int i = 0; i < NUM_BOIDS; i++) {
    gamestate.boids[i] = boid_init(i);
  }

  // game loop
  bool isRunning = true;
  while (isRunning) {
    // event loop
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          isRunning = false;
          break;
        case SDL_MOUSEBUTTONDOWN:
          gamestate_handleClick(&gamestate, event.button);
          break;
        case SDL_KEYDOWN:
          switch (event.key.keysym.sym) {
            case SDLK_r:
              for (int i = 0; i < NUM_BOIDS; i++) {
                gamestate.boids[i] = boid_init(i);
              }
              break;
            case SDLK_v:
              for (int i = 0; i < NUM_BOIDS; i++) {
                boid_randomizeVelocity(gamestate.boids + i);
              }
              break;
            case SDLK_p:
              gamestate.pauseEnabled = gamestate.pauseEnabled ? 0 : 1;
              break;
            case SDLK_q:
              isRunning = false;
              break;
            case SDLK_s:
              gamestate.stepEnabled = gamestate.stepEnabled ? 0 : 1;
              break;
            case SDLK_d:
              if (!gamestate.debugViewEnabled) {
                gamestate.debugViewEnabled = true;
                gamestate.debugView = gamestate_debugView_create();
                if (gamestate.debugView == NULL) {
                  fprintf(stderr, "Cannot load font. Aborting\n");
                  TTF_Quit();
                  SDL_DestroyRenderer(r);
                  SDL_DestroyWindow(window);
                  SDL_Quit();
                  return 1;
                }
              } else {
                gamestate.debugViewEnabled = false;
                gamestate_debugView_free(gamestate.debugView);
              }
              break;
            case SDLK_1:
              gamestate.separationEnabled = gamestate.separationEnabled ? 0 : 1;
              break;
            case SDLK_2:
              gamestate.cohesionEnabled = gamestate.cohesionEnabled ? 0 : 1;
              break;
            case SDLK_3:
              gamestate.alignmentEnabled = gamestate.alignmentEnabled ? 0 : 1;
              break;
            case SDLK_4:
              gamestate.fovEnabled = gamestate.fovEnabled ? 0 : 1;
              break;
          }
      }
    }

    // update
    if (!gamestate.pauseEnabled || gamestate.stepEnabled) {
      if (gamestate.debugViewEnabled) {
        // reset debugView vars
        gamestate_debugView_reset(gamestate.debugView);
      }
      for (int i = 0; i < NUM_BOIDS; i++) {
        boid_update(gamestate.boids + i, &gamestate);
      }
    }

    // render
    SDL_SetRenderDrawColor(r, 0, 0, 180, 255);
    SDL_RenderClear(r);

    // render boids
    for (int i = 0; i < NUM_BOIDS; i++) {
      boid_render(gamestate.boids + i, r, &gamestate);
    }

    // render additional debug elements
    if (gamestate.debugViewEnabled && gamestate.debugView && gamestate.debugView->activeBoidIndex > -1) {
      double avg_x = gamestate.debugView->neighborCenter.x / gamestate.debugView->neighborCount;
      double avg_y = gamestate.debugView->neighborCenter.y / gamestate.debugView->neighborCount;

      SDL_Rect rect;
      rect.x = avg_x - 2;
      rect.y = avg_y - 2;
      rect.h = 4;
      rect.w = 4;
      SDL_SetRenderDrawColor(r, 0, 255, 0, 255);
      SDL_RenderFillRect(r, &rect);
    }

    SDL_RenderPresent(r);
    gamestate.stepEnabled = false;
  }

  SDL_DestroyRenderer(r);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
