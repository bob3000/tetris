#include <libtetris.h>

int PosXRandom() {
  return (rand() % (SCREEN_WIDTH - ((uint32_t)BRICK_WIDTH * 4)) /
          (uint32_t)BRICK_WIDTH) *
         (uint32_t)BRICK_WIDTH;
}

int run(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);
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
      activeForamtion =
          FormationRandom(grid, PosXRandom(), 0.0f - BRICK_HEIGHT * 4);
    }
    if (!PlayerInputFormation(activeForamtion)) {
      if (!FormationPersist(activeForamtion)) {
        GameSetState(game, GameOver);
      }
      FormationDestroy(activeForamtion);
      activeForamtion = NULL;
      continue;
    }
    fallCounter -= 1;
    if (!fallCounter && !FormationMove(activeForamtion, TRANSITION_DOWN)) {
      if (!FormationPersist(activeForamtion)) {
        GameSetState(game, GameOver);
      }
      FormationDestroy(activeForamtion);
      activeForamtion = NULL;
      continue;
    }
    if (fallCounter <= 0) {
      fallCounter = FALLING_DELAY;
    }
    GridCollect(grid);

    // Draw
    BeginDrawing();

    ClearBackground(BLACK);
    FormationRender(activeForamtion);
    GridRender(grid);

    EndDrawing();
  }

  GridDestroy(grid);
  GameDestroy(game);
  CloseWindow();

  return 0;
}
