#include <libtetris.h>

int run(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);
  Grid *grid = GridNew();
  Formation *activeForamtion = FormationNew(grid, Tee, 150.0f, 150.0f, BLACK);

  while (!WindowShouldClose()) {
    // Update
    if (!PlayerInputApply(activeForamtion)) {
      FormationPersist(activeForamtion);
      FormationDestroy(activeForamtion);
      activeForamtion = FormationNew(grid, Tee, 150.0f, 150.0f, BLACK);
    }

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
