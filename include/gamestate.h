#ifndef BOIDS_GAMESTATE_H
#define BOIDS_GAMESTATE_H

#include <stdbool.h>

#include "constants.h"
#include "boid.h"

typedef struct debugView DebugView;
struct debugView {
  int activeBoidIndex;
  Boid* activeBoidNeighbors[NUM_BOIDS];
  int activeBoidNeighborCount;
};

DebugView* gamestate_debugView_create();
void gamestate_debugView_free(DebugView* dv);

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
