#include "libtetris.h"

Formation *FormationNew(Grid *grid, Shape shape, float posX, float posY,
                        Color color) {
  Formation *formation = (Formation *)MemAlloc(sizeof(Formation));
  formation->shape = shape;
  formation->grid = grid;
  formation->numBricks = 4;
  formation->currentRotation = 0;
  switch (shape) {
  // XX
  // XX
  case Block:
    formation->numRotations = 1;
    formation->bricks = (Brick *)MemAlloc(sizeof(Brick) * formation->numBricks);
    formation->bricks[0] = *BrickNew(posX, posY, color);
    formation->bricks[1] = *BrickNew(posX + BRICK_WIDTH, posY, color);
    formation->bricks[2] = *BrickNew(posX, posY + BRICK_HEIGHT, color);
    formation->bricks[3] =
        *BrickNew(posX + BRICK_WIDTH, posY + BRICK_HEIGHT, color);
    break;
  // X
  // X
  // X
  // X
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
  // X
  // X
  // XX
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
  //  X
  //  X
  // XX
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
  // XX
  //  XX
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
  //  XX
  // XX
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
  // X
  // XX
  // X
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

bool FormationMove(Formation *formation) {
  Vector2 transition = TRANSITION_NONE;
  Collision collision = CollisionNone;
  if (IsKeyReleased(KEY_LEFT)) {
    collision = FormationCollisionCheck(formation, TRANSITION_LEFT);
    if (collision == CollisionNone) {
      transition = TRANSITION_LEFT;
    }
  } else if (IsKeyReleased(KEY_RIGHT)) {
    collision = FormationCollisionCheck(formation, TRANSITION_RIGHT);
    if (collision == CollisionNone) {
      transition = TRANSITION_RIGHT;
    }
  } else if (IsKeyDown(KEY_DOWN)) {
    collision = FormationCollisionCheck(formation, TRANSITION_DOWN);
    if (collision == CollisionNone) {
      transition = TRANSITION_DOWN;
    }
  } else if (IsKeyReleased(KEY_UP)) {
    FormationRotateLeft(formation);
  }
  switch (collision) {
  case CollisionWallBottom:
  case CollisionBrickTop:
    return false;
  default:
    break;
  }
  for (uint32_t i = 0; i < (formation->numBricks * formation->numRotations);
       i++) {
    BrickMove(&formation->bricks[i], transition);
  }
  return true;
};

void FormationRotateLeft(Formation *formation) {
  formation->currentRotation =
      ++(formation->currentRotation) % formation->numRotations;
  if (FormationCollisionCheck(formation, TRANSITION_NONE) != CollisionNone) {
    formation->currentRotation =
        --(formation->currentRotation) % formation->numRotations;
  }
}

Collision FormationCollisionCheck(Formation *formation, Vector2 transition) {
  Collision collision = CollisionNone;
  for (uint32_t i = formation->currentRotation * formation->numBricks;
       i < (formation->numBricks * (formation->currentRotation + 1)); i++) {
    collision = BrickCollisionCheck(&formation->bricks[i], transition);
    if (collision != CollisionNone) {
      return collision;
    }
  }
  return collision;
}

void FormationPersist(Formation *formation) {
  for (uint32_t i = formation->currentRotation * formation->numBricks;
       i < (formation->numBricks * (formation->currentRotation + 1)); i++) {
    GridPut(formation->grid, &formation->bricks[i]);
  }
}

void FormationRender(Formation *formation) {
  for (uint32_t i = formation->currentRotation * formation->numBricks;
       i < (formation->numBricks * (formation->currentRotation + 1)); i++) {
    BrickRender(&formation->bricks[i]);
  }
}
