#include "vec2d.h"

Vec2dI vec2di_add(Vec2dI v1, Vec2dI v2) {
  Vec2dI result;
  result.x = v1.x + v2.x;
  result.y = v1.y + v2.y;

  return result;
}

Vec2dD vec2dd_add(Vec2dD v1, Vec2dD v2) {
  Vec2dD result;
  result.x = v1.x + v2.x;
  result.y = v1.y + v2.y;

  return result;
}
