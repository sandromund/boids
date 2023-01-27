#include <math.h>
#include "vec2d.h"

#define RAD(x) (M_PI * x / 180)

Vec2dI vec2di_add(Vec2dI v1, Vec2dI v2) {
  Vec2dI r;
  r.x = v1.x + v2.x;
  r.y = v1.y + v2.y;

  return r;
}

Vec2dD vec2dd_add(Vec2dD v1, Vec2dD v2) {
  Vec2dD r;
  r.x = v1.x + v2.x;
  r.y = v1.y + v2.y;

  return r;
}

Vec2dI vec2di_rotate(Vec2dI v, int angle) {
  Vec2dI r;

  r.x = v.x * cos(RAD(angle)) - v.y * sin(RAD(angle));
  r.y = v.x * sin(RAD(angle)) + v.y * cos(RAD(angle));
  
  return r;
}

Vec2dD vec2dd_rotate(Vec2dD v, int angle) {
  Vec2dD r;

  r.x = v.x * cos(RAD(angle)) - v.y * sin(RAD(angle));
  r.y = v.x * sin(RAD(angle)) + v.y * cos(RAD(angle));
  
  return r;
}

double vec2dd_dot(Vec2dD v1, Vec2dD v2) {
  return v1.x * v2.x + v1.y * v2.y;
}

double vec2dd_length(Vec2dD v) {
  return sqrt(vec2dd_dot(v, v));
}

double vec2dd_angle(Vec2dD v1, Vec2dD v2) {
  return acos(vec2dd_dot(v1, v2) / (vec2dd_length(v1) * vec2dd_length(v2)));
}
