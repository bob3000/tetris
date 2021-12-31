#include <libtetris.h>

Brick *BrickNew(Grid *grid, float posX, float posY, Color color) {
  Brick *brick = (Brick *)MemAlloc(sizeof(Brick));
  brick->grid = grid;
  brick->position.x = posX;
  brick->position.y = posY;
  brick->color = color;
  return brick;
}

void BrickDestroy(Brick *brick) { MemFree(brick); }

void BrickRender(Brick *brick) {
  DrawRectangle(brick->position.x, brick->position.y, BRICK_WIDTH, BRICK_HEIGHT,
                brick->color);
}

Collision BrickCollisionCheck(Brick *brick, Vector2 transition) {
  Vector2 posNew = Vector2Add(brick->position, transition);
  if (posNew.x < 0.0f) {
    return CollisionWallLeft;
  } else if ((posNew.x + BRICK_WIDTH) > (float)SCREEN_WIDTH) {
    return CollisionWallRight;
  } else if ((posNew.y + BRICK_HEIGHT) > (float)SCREEN_HEIGHT) {
    return CollisionWallBottom;
  } else if (transition.y > 0.0f && GridGet(brick->grid, posNew) != NULL) {
    return CollisionBrickTop;
  } else if (transition.x > 0.0f && GridGet(brick->grid, posNew) != NULL) {
    return CollisionBrickRight;
  } else if (transition.x < 0.0f && GridGet(brick->grid, posNew) != NULL) {
    return CollisionBrickLeft;
  } else {
    return CollisionNone;
  }
}

void BrickMove(Brick *brick, Vector2 transition) {
  brick->position = Vector2Add(brick->position, transition);
}
