#ifndef BOIDS_GAMESTATE_H
#define BOIDS_GAMESTATE_H

#include <stdbool.h>

#include "constants.h"
#include "boid.h"

typedef struct gamestate Gamestate;
struct gamestate {
  bool cohesionEnabled;
  bool alignmentEnabled;
  bool separationEnabled;
  bool pauseEnabled;
  bool fovEnabled;
  bool stepEnabled;

  Boid boids[NUM_BOIDS];
};

#endif // BOIDS_GAMESTATE_H
