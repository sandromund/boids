#include "boid.h"
#include <SDL2/SDL2_gfxPrimitives.h>

#define BOID_TRIANGLE_SLOPE 0.6

void boid_render(Boid* b, SDL_Renderer* r) {
  Vec2dI ptA = {BOID_LENGTH / 2, 0}; // the tip
  Vec2dI ptB = {-1 * (BOID_LENGTH / 2), BOID_WIDTH / 2}; // right rear
  Vec2dI ptC = {-1 * (BOID_LENGTH / 2), -1 * (BOID_WIDTH / 2)}; // left rear

  // TODO make rotation dependent on boid's velocity
  // rotate "points" //XXX
  const int angle = 30;
  ptA = vec2di_rotate(ptA, angle);
  ptB = vec2di_rotate(ptB, angle);
  ptC = vec2di_rotate(ptC, angle);

  Sint16 vx[3] = {
    b->position.x + ptA.x,
    b->position.x + ptB.x,
    b->position.x + ptC.x,
  };
  Sint16 vy[3] = {
    b->position.y + ptA.y,
    b->position.y + ptB.y,
    b->position.y + ptC.y,
  };

  const Uint32 color = 0xffff0000; // blue
  filledPolygonColor(r, vx, vy, 3, color);
}
