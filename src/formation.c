#include "libtetris.h"

Formation *FormationNew(Shape shape, float posX, float posY, Color color) {
  Formation *formation = (Formation *)MemAlloc(sizeof(Formation));
  formation->shape = shape;
  formation->numBricks = 4;
  formation->currentRotation = 0;
  switch (shape) {
  case Block:
    formation->numRotations = 1;
    formation->bricks = (Brick *)MemAlloc(sizeof(Brick) * formation->numBricks);
    formation->bricks[0] = *BrickNew(posX, posY, color);
    formation->bricks[1] = *BrickNew(posX + BRICK_WIDTH, posY, color);
    formation->bricks[2] = *BrickNew(posX, posY + BRICK_HEIGHT, color);
    formation->bricks[3] =
        *BrickNew(posX + BRICK_WIDTH, posY + BRICK_HEIGHT, color);
    break;
  case Line:
    formation->numRotations = 2;
    formation->bricks = (Brick *)MemAlloc(sizeof(Brick) * formation->numBricks *
                                          formation->numRotations);
    // vertical
    formation->bricks[0] = *BrickNew(posX, posY - BRICK_HEIGHT, color);
    formation->bricks[1] = *BrickNew(posX, posY, color);
    formation->bricks[2] = *BrickNew(posX, posY + BRICK_HEIGHT, color);
    formation->bricks[3] = *BrickNew(posX, posY + BRICK_HEIGHT * 2, color);
    // horizontal
    formation->bricks[4] = *BrickNew(posX - BRICK_WIDTH, posY, color);
    formation->bricks[5] = *BrickNew(posX, posY, color);
    formation->bricks[6] = *BrickNew(posX + BRICK_WIDTH, posY, color);
    formation->bricks[7] = *BrickNew(posX + BRICK_WIDTH * 2, posY, color);
    break;
  case El:
    formation->numRotations = 4;
    formation->bricks = (Brick *)MemAlloc(sizeof(Brick) * formation->numBricks *
                                          formation->numRotations);
    // 0
    formation->bricks[0] = *BrickNew(posX, posY - BRICK_HEIGHT, color);
    formation->bricks[1] = *BrickNew(posX, posY, color);
    formation->bricks[2] = *BrickNew(posX, posY + BRICK_HEIGHT, color);
    formation->bricks[3] =
        *BrickNew(posX + BRICK_WIDTH, posY + BRICK_HEIGHT, color);
    // 90
    formation->bricks[4] = *BrickNew(posX - BRICK_WIDTH, posY, color);
    formation->bricks[5] = *BrickNew(posX, posY, color);
    formation->bricks[6] = *BrickNew(posX + BRICK_WIDTH, posY, color);
    formation->bricks[7] =
        *BrickNew(posX + BRICK_WIDTH, posY - BRICK_HEIGHT, color);
    // 180
    formation->bricks[8] = *BrickNew(posX, posY + BRICK_HEIGHT, color);
    formation->bricks[9] = *BrickNew(posX, posY, color);
    formation->bricks[10] = *BrickNew(posX, posY - BRICK_HEIGHT, color);
    formation->bricks[11] =
        *BrickNew(posX - BRICK_WIDTH, posY - BRICK_HEIGHT, color);
    // 270
    formation->bricks[12] = *BrickNew(posX + BRICK_WIDTH, posY, color);
    formation->bricks[13] = *BrickNew(posX, posY, color);
    formation->bricks[14] = *BrickNew(posX - BRICK_WIDTH, posY, color);
    formation->bricks[15] =
        *BrickNew(posX - BRICK_WIDTH, posY + BRICK_HEIGHT, color);
    break;
  case Le:
    formation->numRotations = 4;
    formation->bricks = (Brick *)MemAlloc(sizeof(Brick) * formation->numBricks *
                                          formation->numRotations);
    // 0
    formation->bricks[0] = *BrickNew(posX, posY - BRICK_HEIGHT, color);
    formation->bricks[1] = *BrickNew(posX, posY, color);
    formation->bricks[2] = *BrickNew(posX, posY + BRICK_HEIGHT, color);
    formation->bricks[3] =
        *BrickNew(posX - BRICK_WIDTH, posY + BRICK_HEIGHT, color);
    // 90
    formation->bricks[4] = *BrickNew(posX - BRICK_WIDTH, posY, color);
    formation->bricks[5] = *BrickNew(posX, posY, color);
    formation->bricks[6] = *BrickNew(posX + BRICK_WIDTH, posY, color);
    formation->bricks[7] =
        *BrickNew(posX + BRICK_WIDTH, posY + BRICK_HEIGHT, color);
    // 180
    formation->bricks[8] = *BrickNew(posX, posY + BRICK_HEIGHT, color);
    formation->bricks[9] = *BrickNew(posX, posY, color);
    formation->bricks[10] = *BrickNew(posX, posY - BRICK_HEIGHT, color);
    formation->bricks[11] =
        *BrickNew(posX + BRICK_WIDTH, posY - BRICK_HEIGHT, color);
    // 270
    formation->bricks[12] = *BrickNew(posX + BRICK_WIDTH, posY, color);
    formation->bricks[13] = *BrickNew(posX, posY, color);
    formation->bricks[14] = *BrickNew(posX - BRICK_WIDTH, posY, color);
    formation->bricks[15] =
        *BrickNew(posX - BRICK_WIDTH, posY - BRICK_HEIGHT, color);
    break;
  case Zee:
    formation->numRotations = 2;
    formation->bricks = (Brick *)MemAlloc(sizeof(Brick) * formation->numBricks *
                                          formation->numRotations);
    // horizontal
    formation->bricks[0] = *BrickNew(posX - BRICK_WIDTH, posY, color);
    formation->bricks[1] = *BrickNew(posX, posY, color);
    formation->bricks[2] = *BrickNew(posX, posY + BRICK_HEIGHT, color);
    formation->bricks[3] =
        *BrickNew(posX + BRICK_WIDTH, posY + BRICK_HEIGHT, color);
    // vertical
    formation->bricks[4] = *BrickNew(posX, posY - BRICK_HEIGHT, color);
    formation->bricks[5] = *BrickNew(posX, posY, color);
    formation->bricks[6] = *BrickNew(posX - BRICK_WIDTH, posY, color);
    formation->bricks[7] =
        *BrickNew(posX - BRICK_WIDTH, posY + BRICK_HEIGHT, color);
    break;
  case Eez:
    formation->numRotations = 2;
    formation->bricks = (Brick *)MemAlloc(sizeof(Brick) * formation->numBricks *
                                          formation->numRotations);
    // horizontal
    formation->bricks[0] = *BrickNew(posX + BRICK_WIDTH, posY, color);
    formation->bricks[1] = *BrickNew(posX, posY, color);
    formation->bricks[2] = *BrickNew(posX, posY + BRICK_HEIGHT, color);
    formation->bricks[3] =
        *BrickNew(posX - BRICK_WIDTH, posY + BRICK_HEIGHT, color);
    // vertical
    formation->bricks[4] = *BrickNew(posX, posY - BRICK_HEIGHT, color);
    formation->bricks[5] = *BrickNew(posX, posY, color);
    formation->bricks[6] = *BrickNew(posX + BRICK_WIDTH, posY, color);
    formation->bricks[7] =
        *BrickNew(posX + BRICK_WIDTH, posY + BRICK_HEIGHT, color);
    break;
  case Tee:
    formation->numRotations = 4;
    formation->bricks = (Brick *)MemAlloc(sizeof(Brick) * formation->numBricks *
                                          formation->numRotations);
    // 0
    formation->bricks[0] = *BrickNew(posX, posY - BRICK_HEIGHT, color);
    formation->bricks[1] = *BrickNew(posX, posY, color);
    formation->bricks[2] = *BrickNew(posX, posY + BRICK_HEIGHT, color);
    formation->bricks[3] = *BrickNew(posX + BRICK_WIDTH, posY, color);
    // 90
    formation->bricks[4] = *BrickNew(posX - BRICK_WIDTH, posY, color);
    formation->bricks[5] = *BrickNew(posX, posY, color);
    formation->bricks[6] = *BrickNew(posX + BRICK_WIDTH, posY, color);
    formation->bricks[7] = *BrickNew(posX, posY - BRICK_HEIGHT, color);
    // 180
    formation->bricks[8] = *BrickNew(posX, posY + BRICK_HEIGHT, color);
    formation->bricks[9] = *BrickNew(posX, posY, color);
    formation->bricks[10] = *BrickNew(posX, posY - BRICK_HEIGHT, color);
    formation->bricks[11] = *BrickNew(posX - BRICK_WIDTH, posY, color);
    // 270
    formation->bricks[12] = *BrickNew(posX + BRICK_WIDTH, posY, color);
    formation->bricks[13] = *BrickNew(posX, posY, color);
    formation->bricks[14] = *BrickNew(posX - BRICK_WIDTH, posY, color);
    formation->bricks[15] = *BrickNew(posX, posY + BRICK_HEIGHT, color);
    break;
  }
  return formation;
}
void FormationDestroy(Formation *formation) {
  MemFree(formation->bricks);
  MemFree(formation);
}
void FormationMove(Formation *formation) {
  Vector2 transition = TRANSITION_NONE;
  if (IsKeyReleased(KEY_LEFT)) {
    transition = TRANSITION_LEFT;
  } else if (IsKeyReleased(KEY_RIGHT)) {
    transition = TRANSITION_RIGHT;
  } else if (IsKeyDown(KEY_DOWN)) {
    transition = TRANSITION_DOWN;
  } else if (IsKeyReleased(KEY_UP)) {
    FormationRotateLeft(formation);
  }
  for (uint32_t i = 0; i < (formation->numBricks * formation->numRotations);
       i++) {
    BrickMove(&formation->bricks[i], transition);
  }
};

void FormationRotateLeft(Formation *formation) {
  formation->currentRotation =
      ++(formation->currentRotation) % formation->numRotations;
}

void FormationRender(Formation *formation) {
  for (uint32_t i = formation->currentRotation * formation->numBricks;
       i < (formation->numBricks * (formation->currentRotation + 1)); i++) {
    BrickRender(&formation->bricks[i]);
  }
}
