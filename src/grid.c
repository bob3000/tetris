#include "libtetris.h"

Grid *GridNew() {
  Grid *grid = (Grid *)MemAlloc(sizeof(Grid));
  grid->numCols = (uint32_t)(SCREEN_WIDTH / BRICK_WIDTH);
  grid->numRows = (uint32_t)(SCREEN_HEIGHT / BRICK_HEIGHT);
  return grid;
}

void GridDestroy(Grid *grid) {
  for (uint32_t i = 0; i < grid->numRows; i++) {
    for (uint32_t j = 0; j < grid->numCols; j++) {
      if (grid->bricks[i][j] != NULL) {
        MemFree(grid->bricks[i][j]);
        grid->bricks[i][j] = NULL;
      }
    }
  }
  MemFree(grid);
}

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
  if (position.x > SCREEN_WIDTH || position.x < 0.0f || position.y < 0.0f ||
      position.y > SCREEN_HEIGHT) {
    return NULL;
  }
  return grid->bricks[row][col];
}

bool GridPut(Grid *grid, Brick *brick) {
  if (brick->position.x > SCREEN_WIDTH || brick->position.x < 0.0f ||
      brick->position.y < 0.0f || brick->position.y > SCREEN_HEIGHT) {
    return false;
  }
  uint32_t row = (uint32_t)(brick->position.y / BRICK_WIDTH);
  uint32_t col = (uint32_t)(brick->position.x / BRICK_HEIGHT);
  grid->bricks[row][col] = (Brick *)MemAlloc(sizeof(Brick));
  memcpy(grid->bricks[row][col], brick, sizeof(Brick));
  return true;
}

bool GridDel(Grid *grid, Brick *brick) {
  if (brick->position.x > SCREEN_WIDTH || brick->position.x < 0.0f ||
      brick->position.y < 0.0f || brick->position.y > SCREEN_HEIGHT) {
    return false;
  }
  uint32_t row = (uint32_t)(brick->position.y / BRICK_WIDTH);
  uint32_t col = (uint32_t)(brick->position.x / BRICK_HEIGHT);
  MemFree(grid->bricks[row][col]);
  grid->bricks[row][col] = NULL;
  return true;
}

int32_t GridCollect(Grid *grid) {
  uint8_t linesCollected = 0;
  bool deleteLine[grid->numRows];
  for (uint32_t i = 0; i < grid->numRows; i++) {
    deleteLine[i] = true;
    for (uint32_t j = 0; j < grid->numCols; j++) {
      if (grid->bricks[i][j] == NULL) {
        deleteLine[i] = false;
        break;
      }
    }
  }

  for (uint32_t i = 0; i < grid->numRows; i++) {
    if (deleteLine[i]) {
      for (uint32_t j = 0; j < grid->numCols; j++) {
        MemFree(grid->bricks[i][j]);
        grid->bricks[i][j] = NULL;
      }
      linesCollected += 1;
    }
  }

  for (uint32_t line = 0; line < grid->numRows; line++) {
    if (deleteLine[line]) {
      for (uint32_t i = line; i > 0; i--) {
        for (uint32_t j = 0; j < grid->numCols; j++) {
          if (grid->bricks[i - 1][j] != NULL) {
            grid->bricks[i][j] = grid->bricks[i - 1][j];
            grid->bricks[i - 1][j] = NULL;
            grid->bricks[i][j]->position.y += BRICK_HEIGHT;
          }
        }
      }
    }
  }

  return linesCollected;
}
