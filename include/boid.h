#ifndef BOIDS_BOID_H
#define BOIDS_BOID_H

#include <SDL2/SDL.h>
#include "vec2d.h"

#define BOID_LENGTH 30
#define BOID_WIDTH BOID_LENGTH / 2

typedef struct {
  Vec2dD position; // center of boid
  Vec2dD velocity;
} Boid;

void boid_render(Boid* b, SDL_Renderer* r);
void boid_update(Boid* b, Boid* boids, int index);
Boid boid_init();

#endif // BOIDS_BOID_H
