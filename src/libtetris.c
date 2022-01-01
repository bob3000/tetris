#include <libtetris.h>

int PosXRandom() {
  return (rand() % (SCREEN_WIDTH - ((uint32_t)BRICK_WIDTH * 4)) /
          (uint32_t)BRICK_WIDTH) *
         (uint32_t)BRICK_WIDTH;
}

int run(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);
  Grid *grid = GridNew();
  Formation *activeForamtion =
      FormationRandom(grid, PosXRandom(), 0.0f - BRICK_HEIGHT * 4);
  uint32_t fallCounter = FALLING_DELAY;

  while (!WindowShouldClose()) {
    // Update
    if (!PlayerInputApply(activeForamtion)) {
      FormationPersist(activeForamtion);
      FormationDestroy(activeForamtion);
      activeForamtion =
          FormationRandom(grid, PosXRandom(), 0.0f - BRICK_HEIGHT * 4);
    }
    fallCounter -= 1;
    if (!fallCounter && !FormationMove(activeForamtion, TRANSITION_DOWN)) {
      FormationPersist(activeForamtion);
      FormationDestroy(activeForamtion);
      activeForamtion =
          FormationRandom(grid, PosXRandom(), 0.0f - BRICK_HEIGHT * 4);
    }
    if (fallCounter <= 0) {
      fallCounter = FALLING_DELAY;
    }
    GridCollect(grid);

    // Draw
    BeginDrawing();

    ClearBackground(RAYWHITE);
    FormationRender(activeForamtion);
    GridRender(grid);

    EndDrawing();
  }

  GridDestroy(grid);
  CloseWindow();

  return 0;
}
