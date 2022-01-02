#include "raylib.h"
#include "raymath.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// libtetris
#define SCREEN_WIDTH ((uint32_t)500)
#define SCREEN_HEIGHT ((uint32_t)800)

#define WINDOW_TITLE "Tetris"

int run(void);

// brick
#define BRICK_HEIGHT 50.0f
#define BRICK_WIDTH 50.0f
#define FALLING_DELAY (uint32_t)100

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

// Score
#define SCORE_FORMATION_PUT (uint32_t)5
#define SCORE_LINE_COLLECTED (uint32_t)50
#define FORMATIONS_TO_NEXT_LEVEL (uint8_t)50

typedef enum _Align {
  LEFT,
  CENTER,
  RIGHT,
} Align;

typedef struct _TextLine {
  int fontSize;
  int textLen;
  Color color;
  int posY;
  Align align;
  char *body;
} TextLine;

typedef enum _GameState {
  GameInitializing,
  GameRunning,
  GamePaused,
  GameOver,
  GameTerminate,
} GameState;

typedef struct _Game {
  GameState state;
  uint32_t score;
  uint8_t level;
  uint32_t fallingCounter;
  bool playMusic;
  uint32_t numFormations;
} Game;

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

typedef enum _ScoreEvent {
  FormationPut,
  LineCollected,
} ScoreEvent;

// Text
TextLine *TextLineNew(const char *body, int posY, Align align, int fontSize,
                      Color color);
void TextLineRender(TextLine *textLine);
void TextLineDestroy(TextLine *textLine);
void TextDisplayPause();
void TextDisplayOver();
void TextDisplayScore();
void TextDisplayLevel();

// Game
Game *GameNew();
void GameDestroy(Game *game);
void GameTogglePaused(Game *game);
void GameSetState(Game *game, GameState state);
void GameReset(Game *game);
void GameScoreAdd(Game *game, ScoreEvent event, uint8_t times);
void GameFormationInc(Game *game);
void GameResetFallingCounter(Game *game);
void GameFallingCounterDec(Game *game);

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
bool FormationPersist(Formation *formation);
void FormationRender(Formation *formation);
Collision FormationCollisionCheck(Formation *formation, Vector2 transition);

// Grid
Grid *GridNew();
void GridDestroy(Grid *grid);
void GridRender(Grid *grid);
Brick *GridGet(Grid *grid, Vector2 position);
bool GridPut(Grid *grid, Brick *brick);
bool GridDel(Grid *grid, Brick *brick);
uint32_t GridCollect(Grid *grid);

// Player input
bool PlayerInputFormation(Formation *formation);
void PlayerInputGame(Game *game);
