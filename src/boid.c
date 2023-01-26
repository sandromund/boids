#include "boid.h"
#include <SDL2/SDL2_gfxPrimitives.h>

#define BOID_TRIANGLE_SLOPE 0.6

void boid_render(Boid* b, SDL_Renderer* r) {
  Sint16 vx[3] = {
    b->position.x - BOID_LENGTH / 2,
    b->position.x + BOID_LENGTH / 2,
    b->position.x + BOID_LENGTH / 2
  };
  Sint16 vy[3] = {
    b->position.y,
    b->position.y + BOID_WIDTH / 2,
    b->position.y - BOID_WIDTH / 2
  };

  const Uint32 color = 0xffff0000; // blue
  filledPolygonColor(r, vx, vy, 3, color);
}
