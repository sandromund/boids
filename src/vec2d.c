#include <math.h>
#include "vec2d.h"
#include "mathStuff.h"

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
  double angle = atan2(v2.y, v2.x) - atan2(v1.y, v1.x);
  if (angle > M_PI) {
    angle -= 2 * M_PI;
  } else if (angle <= -M_PI) {
    angle += 2 * M_PI;
  }

  return angle;
}

double vec2dd_dist(Vec2dD v1, Vec2dD v2) {
  return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
}

Vec2dD vec2dd_subtract(Vec2dD v1, Vec2dD v2) {
  Vec2dD result;
  result.x = v1.x - v2.x;
  result.y = v1.y - v2.y;
  return result;
}

Vec2dD vec2dd_multScalar(Vec2dD v, double scalar) {
  Vec2dD result;
  result.x = scalar * v.x;
  result.y = scalar * v.y;
  return result;
}
