#ifndef BOIDS_BOID_H
#define BOIDS_BOID_H

#include <SDL2/SDL.h>
#include "vec2d.h"

typedef struct gamestate Gamestate;

#define BOID_LENGTH 30
#define BOID_WIDTH BOID_LENGTH / 2

typedef struct boid Boid;
struct boid {
  Vec2dD position; // center of boid
  Vec2dD velocity;
};

void boid_render(Boid* b, int index, SDL_Renderer* r, Gamestate* gs);
void boid_update(Boid* b, int index, Gamestate* gs);
Boid boid_init();
void boid_randomizeVelocity(Boid* b);

#endif // BOIDS_BOID_H
