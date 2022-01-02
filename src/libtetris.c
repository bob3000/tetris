#include <libtetris.h>

int PosXRandom() {
  uint32_t brickWidth = (uint32_t)BRICK_WIDTH;
  uint32_t min = brickWidth * 2;
  uint32_t max = SCREEN_WIDTH - brickWidth * 2;
  uint32_t randomNum = rand() % (max - min) + min;
  return randomNum / brickWidth * brickWidth;
}

int run(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);
  srand(time(NULL));
  Game *game = GameNew();
  Grid *grid = NULL;
  Formation *activeForamtion = NULL;
  uint32_t fallCounter = FALLING_DELAY;

  while (!WindowShouldClose()) {
    // Update
    PlayerInputGame(game);
    if (game->state == GameTerminate) {
      break;
    }

    if (game->state == GameInitializing) {
      GameReset(game);
      if (activeForamtion != NULL) {
        FormationDestroy(activeForamtion);
        activeForamtion = NULL;
      }
      if (grid != NULL) {
        GridDestroy(grid);
        grid = NULL;
      }
      grid = GridNew();
      GameSetState(game, GameRunning);
    }

    if (game->state == GameOver) {
      BeginDrawing();
      ClearBackground(BLACK);
      TextDisplayOver();
      EndDrawing();
      continue;
    }

    if (game->state == GamePaused) {
      BeginDrawing();
      ClearBackground(BLACK);
      TextDisplayPause();
      EndDrawing();
      continue;
    }

    // GameState GameRunning
    if (activeForamtion == NULL) {
      uint32_t posX = PosXRandom();
      activeForamtion = FormationRandom(grid, posX, 0.0f - BRICK_HEIGHT * 2);
      GameFormationInc(game);
    }
    if (fallCounter <= 0) {
      fallCounter = FALLING_DELAY - (FALLING_DELAY / 10 * game->level) + 1;
    }
    fallCounter -= 1;
    if (!PlayerInputFormation(activeForamtion)) {
      if (!FormationPersist(activeForamtion)) {
        GameSetState(game, GameOver);
      }
      FormationDestroy(activeForamtion);
      activeForamtion = NULL;
      GameScoreAdd(game, FormationPut, 1);
      continue;
    }
    if (!fallCounter && !FormationMove(activeForamtion, TRANSITION_DOWN)) {
      if (!FormationPersist(activeForamtion)) {
        GameSetState(game, GameOver);
      }
      FormationDestroy(activeForamtion);
      GameScoreAdd(game, FormationPut, 1);
      activeForamtion = NULL;
      continue;
    }
    uint32_t numLinesCollected = GridCollect(grid);
    GameScoreAdd(game, LineCollected, numLinesCollected);

    // Draw
    BeginDrawing();

    ClearBackground(BLACK);
    TextDisplayLevel(game->level);
    TextDisplayScore(game->score);
    FormationRender(activeForamtion);
    GridRender(grid);

    EndDrawing();
  }

  GridDestroy(grid);
  GameDestroy(game);
  CloseWindow();

  return 0;
}
