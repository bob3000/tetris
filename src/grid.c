#include "libtetris.h"

Grid *GridNew() {
  Grid *grid = (Grid *)MemAlloc(sizeof(Grid));
  grid->numCols = (uint32_t)(SCREEN_WIDTH / BRICK_WIDTH);
  grid->numRows = (uint32_t)(SCREEN_HEIGHT / BRICK_HEIGHT);
  return grid;
}

void GridDestroy(Grid *grid) { MemFree(grid); }

void GridRender(Grid *grid) {
  for (uint32_t i = 0; i < grid->numRows; i++) {
    for (uint32_t j = 0; j < grid->numCols; j++) {
      if (grid->bricks[i][j] != NULL) {
        BrickRender(grid->bricks[i][j]);
      }
    }
  }
}

Brick *GridGet(Grid *grid, Vector2 position) {
  uint32_t row = (uint32_t)(position.y / BRICK_WIDTH);
  uint32_t col = (uint32_t)(position.x / BRICK_HEIGHT);
  return grid->bricks[row][col];
}

void GridPut(Grid *grid, Brick *brick) {
  uint32_t row = (uint32_t)(brick->position.y / BRICK_WIDTH);
  uint32_t col = (uint32_t)(brick->position.x / BRICK_HEIGHT);
  grid->bricks[row][col] = (Brick *)MemAlloc(sizeof(Brick));
  memcpy(grid->bricks[row][col], brick, sizeof(Brick));
}

void GridDel(Grid *grid, Brick *brick) {
  uint32_t row = (uint32_t)(brick->position.y / BRICK_WIDTH);
  uint32_t col = (uint32_t)(brick->position.x / BRICK_HEIGHT);
  MemFree(grid->bricks[row][col]);
  grid->bricks[row][col] = NULL;
}
