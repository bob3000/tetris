#include <libtetris.h>

Brick *BrickNew(float posX, float posY, Color color) {
  Brick *brick = (Brick *)MemAlloc(sizeof(Brick));
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

// bool BrickCollisionCheck(Brick *brick, Brick *other) {
//   Rectangle brickShape = {.x = brick->poition.x,
//                           .y = brick->poition.y,
//                           .width = BRICK_WIDTH,
//                           .height = BRICK_HEIGHT};
//   Rectangle otherShape = {.x = other->poition.x,
//                           .y = other->poition.y,
//                           .width = BRICK_WIDTH,
//                           .height = BRICK_HEIGHT};
//   return CheckCollisionRecs(brickShape, otherShape);
// }

bool BrickMove(Brick *brick, Vector2 transition) {
  brick->position = Vector2Add(brick->position, transition);
  return true;
}
