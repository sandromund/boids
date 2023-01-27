#ifndef BOIDS_VEC2D_H
#define BOIDS_VEC2D_H

typedef struct {
  int x;
  int y;
} Vec2dI;

Vec2dI vec2di_add(Vec2dI v1, Vec2dI v2);
Vec2dI vec2di_rotate(Vec2dI v, int angle);

typedef struct {
  double x;
  double y;
} Vec2dD;

Vec2dD vec2dd_add(Vec2dD v1, Vec2dD v2);
Vec2dD vec2dd_rotate(Vec2dD v, int angle);

#endif // BOIDS_VEC2D_H
