#include "raylib.h"
#include "raymath.h"
#include <inttypes.h>

// libtetris
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

typedef struct _Brick {
  Vector2 position;
  Color color;
} Brick;

Brick *BrickNew(float posX, float posY, Color color);
void BrickDestroy(Brick *brick);
bool BrickMove(Brick *brick, Vector2 transition);
void BrickRender(Brick *brick);

// formation
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
  Brick *bricks;
} Formation;

Formation *FormationNew(Shape shape, float posX, float posY, Color color);
void FormationDestroy(Formation *formation);
void FormationMove(Formation *formation);
void FormationRotateLeft(Formation *formation);
void FormationRender(Formation *formation);
