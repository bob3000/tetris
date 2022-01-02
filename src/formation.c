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
    formation->bricks[0] = *BrickNew(grid, posX, posY, color);
    formation->bricks[1] = *BrickNew(grid, posX + BRICK_WIDTH, posY, color);
    formation->bricks[2] = *BrickNew(grid, posX, posY + BRICK_HEIGHT, color);
    formation->bricks[3] =
        *BrickNew(grid, posX + BRICK_WIDTH, posY + BRICK_HEIGHT, color);
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
    formation->bricks[0] = *BrickNew(grid, posX, posY - BRICK_HEIGHT, color);
    formation->bricks[1] = *BrickNew(grid, posX, posY, color);
    formation->bricks[2] = *BrickNew(grid, posX, posY + BRICK_HEIGHT, color);
    formation->bricks[3] =
        *BrickNew(grid, posX, posY + BRICK_HEIGHT * 2, color);
    // horizontal
    formation->bricks[4] = *BrickNew(grid, posX - BRICK_WIDTH, posY, color);
    formation->bricks[5] = *BrickNew(grid, posX, posY, color);
    formation->bricks[6] = *BrickNew(grid, posX + BRICK_WIDTH, posY, color);
    formation->bricks[7] = *BrickNew(grid, posX + BRICK_WIDTH * 2, posY, color);
    break;
  // X
  // X
  // XX
  case El:
    formation->numRotations = 4;
    formation->bricks = (Brick *)MemAlloc(sizeof(Brick) * formation->numBricks *
                                          formation->numRotations);
    // 0
    formation->bricks[0] = *BrickNew(grid, posX, posY - BRICK_HEIGHT, color);
    formation->bricks[1] = *BrickNew(grid, posX, posY, color);
    formation->bricks[2] = *BrickNew(grid, posX, posY + BRICK_HEIGHT, color);
    formation->bricks[3] =
        *BrickNew(grid, posX + BRICK_WIDTH, posY + BRICK_HEIGHT, color);
    // 90
    formation->bricks[4] = *BrickNew(grid, posX - BRICK_WIDTH, posY, color);
    formation->bricks[5] = *BrickNew(grid, posX, posY, color);
    formation->bricks[6] = *BrickNew(grid, posX + BRICK_WIDTH, posY, color);
    formation->bricks[7] =
        *BrickNew(grid, posX + BRICK_WIDTH, posY - BRICK_HEIGHT, color);
    // 180
    formation->bricks[8] = *BrickNew(grid, posX, posY + BRICK_HEIGHT, color);
    formation->bricks[9] = *BrickNew(grid, posX, posY, color);
    formation->bricks[10] = *BrickNew(grid, posX, posY - BRICK_HEIGHT, color);
    formation->bricks[11] =
        *BrickNew(grid, posX - BRICK_WIDTH, posY - BRICK_HEIGHT, color);
    // 270
    formation->bricks[12] = *BrickNew(grid, posX + BRICK_WIDTH, posY, color);
    formation->bricks[13] = *BrickNew(grid, posX, posY, color);
    formation->bricks[14] = *BrickNew(grid, posX - BRICK_WIDTH, posY, color);
    formation->bricks[15] =
        *BrickNew(grid, posX - BRICK_WIDTH, posY + BRICK_HEIGHT, color);
    break;
  //  X
  //  X
  // XX
  case Le:
    formation->numRotations = 4;
    formation->bricks = (Brick *)MemAlloc(sizeof(Brick) * formation->numBricks *
                                          formation->numRotations);
    // 0
    formation->bricks[0] = *BrickNew(grid, posX, posY - BRICK_HEIGHT, color);
    formation->bricks[1] = *BrickNew(grid, posX, posY, color);
    formation->bricks[2] = *BrickNew(grid, posX, posY + BRICK_HEIGHT, color);
    formation->bricks[3] =
        *BrickNew(grid, posX - BRICK_WIDTH, posY + BRICK_HEIGHT, color);
    // 90
    formation->bricks[4] = *BrickNew(grid, posX - BRICK_WIDTH, posY, color);
    formation->bricks[5] = *BrickNew(grid, posX, posY, color);
    formation->bricks[6] = *BrickNew(grid, posX + BRICK_WIDTH, posY, color);
    formation->bricks[7] =
        *BrickNew(grid, posX + BRICK_WIDTH, posY + BRICK_HEIGHT, color);
    // 180
    formation->bricks[8] = *BrickNew(grid, posX, posY + BRICK_HEIGHT, color);
    formation->bricks[9] = *BrickNew(grid, posX, posY, color);
    formation->bricks[10] = *BrickNew(grid, posX, posY - BRICK_HEIGHT, color);
    formation->bricks[11] =
        *BrickNew(grid, posX + BRICK_WIDTH, posY - BRICK_HEIGHT, color);
    // 270
    formation->bricks[12] = *BrickNew(grid, posX + BRICK_WIDTH, posY, color);
    formation->bricks[13] = *BrickNew(grid, posX, posY, color);
    formation->bricks[14] = *BrickNew(grid, posX - BRICK_WIDTH, posY, color);
    formation->bricks[15] =
        *BrickNew(grid, posX - BRICK_WIDTH, posY - BRICK_HEIGHT, color);
    break;
  // XX
  //  XX
  case Zee:
    formation->numRotations = 2;
    formation->bricks = (Brick *)MemAlloc(sizeof(Brick) * formation->numBricks *
                                          formation->numRotations);
    // horizontal
    formation->bricks[0] = *BrickNew(grid, posX - BRICK_WIDTH, posY, color);
    formation->bricks[1] = *BrickNew(grid, posX, posY, color);
    formation->bricks[2] = *BrickNew(grid, posX, posY + BRICK_HEIGHT, color);
    formation->bricks[3] =
        *BrickNew(grid, posX + BRICK_WIDTH, posY + BRICK_HEIGHT, color);
    // vertical
    formation->bricks[4] = *BrickNew(grid, posX, posY - BRICK_HEIGHT, color);
    formation->bricks[5] = *BrickNew(grid, posX, posY, color);
    formation->bricks[6] = *BrickNew(grid, posX - BRICK_WIDTH, posY, color);
    formation->bricks[7] =
        *BrickNew(grid, posX - BRICK_WIDTH, posY + BRICK_HEIGHT, color);
    break;
  //  XX
  // XX
  case Eez:
    formation->numRotations = 2;
    formation->bricks = (Brick *)MemAlloc(sizeof(Brick) * formation->numBricks *
                                          formation->numRotations);
    // horizontal
    formation->bricks[0] = *BrickNew(grid, posX + BRICK_WIDTH, posY, color);
    formation->bricks[1] = *BrickNew(grid, posX, posY, color);
    formation->bricks[2] = *BrickNew(grid, posX, posY + BRICK_HEIGHT, color);
    formation->bricks[3] =
        *BrickNew(grid, posX - BRICK_WIDTH, posY + BRICK_HEIGHT, color);
    // vertical
    formation->bricks[4] = *BrickNew(grid, posX, posY - BRICK_HEIGHT, color);
    formation->bricks[5] = *BrickNew(grid, posX, posY, color);
    formation->bricks[6] = *BrickNew(grid, posX + BRICK_WIDTH, posY, color);
    formation->bricks[7] =
        *BrickNew(grid, posX + BRICK_WIDTH, posY + BRICK_HEIGHT, color);
    break;
  // X
  // XX
  // X
  case Tee:
    formation->numRotations = 4;
    formation->bricks = (Brick *)MemAlloc(sizeof(Brick) * formation->numBricks *
                                          formation->numRotations);
    // 0
    formation->bricks[0] = *BrickNew(grid, posX, posY - BRICK_HEIGHT, color);
    formation->bricks[1] = *BrickNew(grid, posX, posY, color);
    formation->bricks[2] = *BrickNew(grid, posX, posY + BRICK_HEIGHT, color);
    formation->bricks[3] = *BrickNew(grid, posX + BRICK_WIDTH, posY, color);
    // 90
    formation->bricks[4] = *BrickNew(grid, posX - BRICK_WIDTH, posY, color);
    formation->bricks[5] = *BrickNew(grid, posX, posY, color);
    formation->bricks[6] = *BrickNew(grid, posX + BRICK_WIDTH, posY, color);
    formation->bricks[7] = *BrickNew(grid, posX, posY - BRICK_HEIGHT, color);
    // 180
    formation->bricks[8] = *BrickNew(grid, posX, posY + BRICK_HEIGHT, color);
    formation->bricks[9] = *BrickNew(grid, posX, posY, color);
    formation->bricks[10] = *BrickNew(grid, posX, posY - BRICK_HEIGHT, color);
    formation->bricks[11] = *BrickNew(grid, posX - BRICK_WIDTH, posY, color);
    // 270
    formation->bricks[12] = *BrickNew(grid, posX + BRICK_WIDTH, posY, color);
    formation->bricks[13] = *BrickNew(grid, posX, posY, color);
    formation->bricks[14] = *BrickNew(grid, posX - BRICK_WIDTH, posY, color);
    formation->bricks[15] = *BrickNew(grid, posX, posY + BRICK_HEIGHT, color);
    break;
  }
  return formation;
}

void FormationDestroy(Formation *formation) {
  MemFree(formation->bricks);
  MemFree(formation);
}

Formation *FormationRandom(Grid *grid, float posX, float posY) {
  Shape shapes[] = {Block, Line, Zee, El, Le, Eez, Tee};
  Color colores[] = {LIGHTGRAY, BLUE, RED, YELLOW, GREEN, BROWN, MAGENTA};
  uint8_t numShapes = sizeof(shapes) / sizeof(int);
  uint8_t numColores = sizeof(colores) / sizeof(int);
  uint8_t choiceShape = rand() % numShapes;
  uint8_t choiceColor = rand() % numShapes;
  return FormationNew(grid, shapes[choiceShape], posX, posY,
                      colores[choiceColor]);
}

bool FormationMove(Formation *formation, Vector2 transition) {
  Collision collision = FormationCollisionCheck(formation, transition);
  if ((transition.x + transition.y) > 0.0f)
    if (collision != 3)
      TraceLog(LOG_INFO, "collision %d", collision);
  switch (collision) {
  case CollisionWallBottom:
    TraceLog(LOG_INFO, "collision bottom");
  case CollisionBrickTop:
    TraceLog(LOG_INFO, "collision brick top");
    return false;
  case CollisionNone:
    for (uint32_t i = 0; i < (formation->numBricks * formation->numRotations);
         i++) {
      BrickMove(&formation->bricks[i], transition);
    }
  default:
    return true;
  }
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

bool FormationPersist(Formation *formation) {
  for (uint32_t i = formation->currentRotation * formation->numBricks;
       i < (formation->numBricks * (formation->currentRotation + 1)); i++) {
    if (!GridPut(formation->grid, &formation->bricks[i])) {
      return false;
    }
  }
  return true;
}

void FormationRender(Formation *formation) {
  for (uint32_t i = formation->currentRotation * formation->numBricks;
       i < (formation->numBricks * (formation->currentRotation + 1)); i++) {
    BrickRender(&formation->bricks[i]);
  }
}
