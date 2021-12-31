#include "libtetris.h"
#include <assert.h>

int main(void) {
  Grid *grid = GridNew();
  Brick *brick1 = BrickNew(grid, 0.0f, 0.0f, BLACK);
  Brick *brick2 = BrickNew(grid, 50.0f, 50.0f, BLACK);
  Brick *brick3 = BrickNew(grid, 19.4f, 11.2f, BLACK);

  GridPut(grid, brick1);
  Brick *b1 = GridGet(grid, brick1->position);
  assert(b1 == brick1);

  GridPut(grid, brick2);
  Brick *b2 = GridGet(grid, brick2->position);
  assert(b2 == brick2);

  GridPut(grid, brick3);
  Brick *b3 = GridGet(grid, brick3->position);
  assert(b3 == brick3);
}
