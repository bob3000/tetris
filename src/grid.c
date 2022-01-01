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
  int8_t linesToCollect = 0;
  // get num lines to collect
  for (int32_t i = grid->numRows - 1; i >= 0; i--) {
    for (int32_t j = grid->numCols - 1; j >= 0; j--) {
      if (grid->bricks[i][j] == NULL) {
        i = j = -1;
      }
    }
    if (i >= 0) {
      linesToCollect += 1;
    }
  }
  if (linesToCollect == 0) {
    return linesToCollect;
  }

  // move lines downward
  Brick *tmpBrick = NULL;
  for (int32_t i = grid->numRows - 1; i >= 0; i--) {
    for (int32_t j = grid->numCols - 1; j >= 0; j--) {
      if ((i + linesToCollect) >= grid->numRows) {
        MemFree(grid->bricks[i][j]);
        grid->bricks[i][j] = NULL;
      } else if (grid->bricks[i][j] != NULL) {
        tmpBrick = grid->bricks[i][j];
        tmpBrick->position.y += BRICK_HEIGHT * (float)linesToCollect;
        GridPut(grid, tmpBrick);
        MemFree(tmpBrick);
        tmpBrick = NULL;
        grid->bricks[i][j] = NULL;
      }
    }
  }
  return linesToCollect;
}
