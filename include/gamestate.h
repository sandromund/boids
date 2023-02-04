#ifndef BOIDS_GAMESTATE_H
#define BOIDS_GAMESTATE_H

#include <stdbool.h>
#include <SDL2/SDL_ttf.h>

#include "constants.h"
#include "boid.h"
#include "vec2d.h"

typedef struct debugView DebugView;
struct debugView {
  int activeBoidIndex;
  bool activeBoidNeighbors[NUM_BOIDS];
  Vec2dD neighborCenter;
  int neighborCount;

  TTF_Font* font;
};

DebugView* gamestate_debugView_create();
void gamestate_debugView_free(DebugView* dv);
void gamestate_debugView_reset(DebugView* dv);

typedef struct gamestate Gamestate;
struct gamestate {
  bool cohesionEnabled;
  bool alignmentEnabled;
  bool separationEnabled;
  bool pauseEnabled;
  bool fovEnabled;
  bool stepEnabled;
  bool debugViewEnabled;

  Boid boids[NUM_BOIDS];

  DebugView* debugView;
};

void gamestate_handleClick(Gamestate* gs, SDL_MouseButtonEvent e);

#endif // BOIDS_GAMESTATE_H
