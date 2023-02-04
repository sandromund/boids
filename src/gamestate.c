#include <stdio.h>
#include <limits.h>

#include "gamestate.h"
#include "constants.h"
#include "boid.h"

DebugView* gamestate_debugView_create() {
  DebugView* dv = malloc(sizeof(DebugView));
  if (dv == NULL) {
    return NULL;
  }

  dv->font = TTF_OpenFont(DEBUG_FONT_PATH, DEBUG_FONT_SIZE);
  if (dv->font == NULL) {
    return NULL;
  }

  dv->activeBoidIndex = -1;
  memset(dv->activeBoidNeighbors, 0, sizeof(bool) * NUM_BOIDS);

  dv->neighborCenter.x = 0;
  dv->neighborCenter.y = 0;
  dv->neighborCount = 0;

  return dv;
}

void gamestate_debugView_free(DebugView* dv) {
  if (dv != NULL) {
    if (dv->font != NULL) {
      TTF_CloseFont(dv->font);
    }
    free(dv);
  }
}

void gamestate_handleClick(Gamestate* gs, SDL_MouseButtonEvent e) {
  if (!gs->debugViewEnabled) return;

  // determine closest boid to mouse coordinates
  int closestIndex = -1;
  int closestDistance = INT_MAX;

  for (int i = 0; i < NUM_BOIDS; i++) {
    const Boid* b = gs->boids + i;
    const Vec2dD mousePos = {e.x, e.y};
    const double dist = vec2dd_dist(b->position, mousePos);

    if (dist < BOID_LENGTH / 2) {
      if (dist < closestDistance) {
        closestDistance = dist;
        closestIndex = i;
      }
    }
  }

  // set selected boid in debugView
  gs->debugView->activeBoidIndex = closestIndex;

}

void gamestate_debugView_reset(DebugView* dv) {
  if (dv == NULL) return;

  memset(dv->activeBoidNeighbors, 0, sizeof(bool) * NUM_BOIDS);
  dv->neighborCenter.x = 0;
  dv->neighborCenter.y = 0;
  dv->neighborCount = 0;
}
