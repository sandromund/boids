#ifndef BOIDS_VEC2D_H
#define BOIDS_VEC2D_H

typedef struct vec2dI Vec2dI;
struct vec2dI {
  int x;
  int y;
};

Vec2dI vec2di_add(Vec2dI v1, Vec2dI v2);
Vec2dI vec2di_rotate(Vec2dI v, int angle);

typedef struct vec2dD Vec2dD;
struct vec2dD {
  double x;
  double y;
};

Vec2dD vec2dd_add(Vec2dD v1, Vec2dD v2);
Vec2dD vec2dd_rotate(Vec2dD v, int angle);
double vec2dd_dot(Vec2dD v1, Vec2dD v2);
double vec2dd_length(Vec2dD v);
double vec2dd_angle(Vec2dD v1, Vec2dD v2);
double vec2dd_dist(Vec2dD v1, Vec2dD v2);
Vec2dD vec2dd_subtract(Vec2dD v1, Vec2dD v2);
Vec2dD vec2dd_multScalar(Vec2dD v, double scalar);

#endif // BOIDS_VEC2D_H
