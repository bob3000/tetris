#include "raylib.h"
#include "raymath.h"
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

// libtetris
#define SCREEN_WIDTH ((uint32_t)500)
#define SCREEN_HEIGHT ((uint32_t)800)

#define WINDOW_TITLE "Tetris"

int run(void);

// brick
#define BRICK_HEIGHT 50.0f
#define BRICK_WIDTH 50.0f

#define TRANSITION_LEFT                                                        \
  (Vector2) { .x = -BRICK_WIDTH, .y = 0.0f }
#define TRANSITION_RIGHT                                                       \
  (Vector2) { .x = BRICK_WIDTH, .y = 0.0f }
#define TRANSITION_UP                                                          \
  (Vector2) { .x = 0.0f, .y = -BRICK_HEIGHT }
#define TRANSITION_DOWN                                                        \
  (Vector2) { .x = 0.0f, .y = BRICK_HEIGHT }
#define TRANSITION_NONE                                                        \
  (Vector2) { .x = 0.0f, .y = 0.0f }

typedef enum _Collision {
  CollisionBrickLeft,
  CollisionBrickRight,
  CollisionBrickTop,
  CollisionNone,
  CollisionWallBottom,
  CollisionWallLeft,
  CollisionWallRight,
} Collision;

typedef struct _Grid {
  uint32_t numRows;
  uint32_t numCols;
  struct _Brick *bricks[SCREEN_HEIGHT / (uint32_t)BRICK_HEIGHT]
                       [SCREEN_WIDTH / (uint32_t)BRICK_WIDTH];
} Grid;

typedef struct _Brick {
  Vector2 position;
  Grid *grid;
  Color color;
} Brick;

typedef enum _Shape {
  Block,
  Line,
  El,
  Zee,
  Le,
  Eez,
  Tee,
} Shape;

typedef struct _Formation {
  uint8_t numBricks;
  uint8_t numRotations;
  uint8_t currentRotation;
  Shape shape;
  Grid *grid;
  Brick *bricks;
} Formation;

Brick *BrickNew(Grid *grid, float posX, float posY, Color color);
void BrickDestroy(Brick *brick);
void BrickMove(Brick *brick, Vector2 transition);
void BrickRender(Brick *brick);
Collision BrickCollisionCheck(Brick *brick, Vector2 transition);

// formation
Formation *FormationNew(Grid *grid, Shape shape, float posX, float posY,
                        Color color);
Formation *FormationRandom(Grid *grid, float posX, float posY);
void FormationDestroy(Formation *formation);
bool FormationMove(Formation *formation, Vector2 transition);
void FormationRotateLeft(Formation *formation);
void FormationPersist(Formation *formation);
void FormationRender(Formation *formation);
Collision FormationCollisionCheck(Formation *formation, Vector2 transition);

// Grid
Grid *GridNew();
void GridDestroy(Grid *grid);
void GridRender(Grid *grid);
Brick *GridGet(Grid *grid, Vector2 position);
void GridPut(Grid *grid, Brick *brick);
void GridDel(Grid *grid, Brick *brick);

// Player input
bool PlayerInputApply(Formation *formation);
