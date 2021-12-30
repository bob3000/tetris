#include <libtetris.h>

#define SCREEN_WIDTH (500)
#define SCREEN_HEIGHT (800)

#define WINDOW_TITLE "Tetris"

int run(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);
  Formation *activeForamtion = FormationNew(Tee, 150.0f, 150.0f, BLACK);

  while (!WindowShouldClose()) {
    // Update
    FormationMove(activeForamtion);
    // Draw
    BeginDrawing();

    ClearBackground(RAYWHITE);
    FormationRender(activeForamtion);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
