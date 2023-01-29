#ifndef BOIDS_GAMESTATE_H
#define BOIDS_GAMESTATE_H

#include <stdbool.h>

typedef struct {
  bool cohesionEnabled;
  bool alignmentEnabled;
  bool separationEnabled;
  bool pauseEnabled;
  bool fovEnabled;
  bool stepEnabled;
} Gamestate;

#endif // BOIDS_GAMESTATE_H
