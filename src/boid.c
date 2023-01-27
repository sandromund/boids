#include "boid.h"
#include "mathStuff.h"
#include <SDL2/SDL2_gfxPrimitives.h>

void boid_render(Boid* b, SDL_Renderer* r) {
  Vec2dD ptA = {BOID_LENGTH / 2, 0}; // the tip
  Vec2dD ptB = {-1 * (BOID_LENGTH / 2), BOID_WIDTH / 2}; // right rear
  Vec2dD ptC = {-1 * (BOID_LENGTH / 2), -1 * (BOID_WIDTH / 2)}; // left rear

  // TODO make rotation dependent on boid's velocity
  // rotate "points" //XXX
  const Vec2dD xAxis = {1, 0};
  const int angle = DEG(vec2dd_angle(xAxis, b->velocity));
  ptA = vec2dd_rotate(ptA, angle);
  ptB = vec2dd_rotate(ptB, angle);
  ptC = vec2dd_rotate(ptC, angle);

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

void boid_update(Boid* b) {
  b->position = vec2dd_add(b->position, b->velocity);
}
