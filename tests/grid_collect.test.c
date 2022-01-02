#include "libtetris.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *gridBottomLine = "- - - - - - - - - -\n"
                             "- - - - - - - - - -\n"
                             "- - - - - - - - - -\n"
                             "- - - - - - - - - -\n"
                             "- - - - - - - - - -\n"
                             "- - - - - - - - - -\n"
                             "- - - - - - - - - -\n"
                             "- - - - - - - - - -\n"
                             "- - - - - - - - - -\n"
                             "- - - - - - - - - -\n"
                             "- - - - - - - - - -\n"
                             "- - - - - - - - - -\n"
                             "- - - - - - - - - -\n"
                             "- - - - - - - - - -\n"
                             "- - - - - - - - - -\n"
                             "x x x x x x x x x x\n";

const char *gridFull = "x x x x x x x x x x\n"
                       "x x x x x x x x x x\n"
                       "x x x x x x x x x x\n"
                       "x x x x x x x x x x\n"
                       "x x x x x x x x x x\n"
                       "x x x x x x x x x x\n"
                       "x x x x x x x x x x\n"
                       "x x x x x x x x x x\n"
                       "x x x x x x x x x x\n"
                       "x x x x x x x x x x\n"
                       "x x x x x x x x x x\n"
                       "x x x x x x x x x x\n"
                       "x x x x x x x x x x\n"
                       "x x x x x x x x x x\n"
                       "x x x x x x x x x x\n"
                       "x x x x x x x x x x\n";

const char *gridLineLeft = "x - - - - - - - - -\n"
                           "x - - - - - - - - -\n"
                           "x - - - - - - - - -\n"
                           "x - - - - - - - - -\n"
                           "x - - - - - - - - -\n"
                           "x - - - - - - - - -\n"
                           "x - - - - - - - - -\n"
                           "x - - - - - - - - -\n"
                           "x - - - - - - - - -\n"
                           "x - - - - - - - - -\n"
                           "x - - - - - - - - -\n"
                           "x - - - - - - - - -\n"
                           "x - - - - - - - - -\n"
                           "x - - - - - - - - -\n"
                           "x - - - - - - - - -\n"
                           "x - - - - - - - - -\n";

const char *gridPyramid = "- - - - - - - - - -\n"
                          "- - - - - - - - - -\n"
                          "- - - - - - - - - -\n"
                          "- - - - - - - - - -\n"
                          "- - - - - - - - - -\n"
                          "- - - - - - - - - -\n"
                          "- - - - - - - - - -\n"
                          "- - - - - - - - - -\n"
                          "- - - - - - - - - -\n"
                          "- - - - - x - - - -\n"
                          "- - - - x x - - - -\n"
                          "- - - x x x x - - -\n"
                          "- - x x x x x x - -\n"
                          "- x x x x x x x x -\n"
                          "x x x x x x x x x x\n"
                          "x x x x x x x x x x\n";

const char *gridPyramidExpected = "- - - - - - - - - -\n"
                                  "- - - - - - - - - -\n"
                                  "- - - - - - - - - -\n"
                                  "- - - - - - - - - -\n"
                                  "- - - - - - - - - -\n"
                                  "- - - - - - - - - -\n"
                                  "- - - - - - - - - -\n"
                                  "- - - - - - - - - -\n"
                                  "- - - - - - - - - -\n"
                                  "- - - - - - - - - -\n"
                                  "- - - - - - - - - -\n"
                                  "- - - - - x - - - -\n"
                                  "- - - - x x - - - -\n"
                                  "- - - x x x x - - -\n"
                                  "- - x x x x x x - -\n"
                                  "- x x x x x x x x -\n";

const char *gridHoles = "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - x - - - -\n"
                        "- - - - - x - - - -\n"
                        "x x x x x x x x x x\n"
                        "x x x x x x x - x x\n"
                        "x x x - x x x x x x\n"
                        "x x x x x x x x x x\n";

const char *gridHolesExpected = "- - - - - - - - - -\n"
                                "- - - - - - - - - -\n"
                                "- - - - - - - - - -\n"
                                "- - - - - - - - - -\n"
                                "- - - - - - - - - -\n"
                                "- - - - - - - - - -\n"
                                "- - - - - - - - - -\n"
                                "- - - - - - - - - -\n"
                                "- - - - - - - - - -\n"
                                "- - - - - - - - - -\n"
                                "- - - - - - - - - -\n"
                                "- - - - - - - - - -\n"
                                "- - - - - x - - - -\n"
                                "- - - - - x - - - -\n"
                                "x x x x x x x - x x\n"
                                "x x x - x x x x x x\n";

const char *gridEmpty = "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n"
                        "- - - - - - - - - -\n";

Grid *GridBuild(const char instructions[]) {
  Grid *grid = GridNew();
  uint32_t row = 0, col = 0;
  for (uint32_t i = 0; i < strlen(instructions); i++) {
    switch (instructions[i]) {
    case '\n':
      row += 1;
      col = 0;
      break;
    case '-':
      col += 1;
      break;
    case 'x': {
      Brick *brick =
          BrickNew(grid, BRICK_WIDTH * col, BRICK_HEIGHT * row, BLACK);
      GridPut(grid, brick);
      BrickDestroy(brick);
      col += 1;
      break;
    }
    }
  }
  return grid;
}

void GridPrint(Grid *grid) {
  printf("\n   ");
  for (int j = 0; j < grid->numCols; j++) {
    printf("%02d ", j);
  }
  printf("\n");
  for (int i = 0; i < grid->numRows; i++) {
    printf("%02d", i);
    for (int j = 0; j < grid->numCols; j++) {
      if (grid->bricks[i][j] != NULL) {
        printf("  x");
      } else {
        printf("  -");
      }
    }
    printf("\n");
  }
}

bool GridCompare(Grid *g1, Grid *g2) {
  for (uint8_t i = 0; i < g1->numRows; i++) {
    for (uint8_t j = 0; j < g1->numCols; j++) {
      if ((g1->bricks[i][j] == NULL && g2->bricks[i][j] != NULL) ||
          (g1->bricks[i][j] != NULL && g2->bricks[i][j] == NULL)) {
        return false;
      }
    }
  }
  return true;
}

void TestGridCollectBottomLine() {
  TraceLog(LOG_INFO, "Test collect bottom line grid");
  Grid *gridInput = GridBuild(gridBottomLine);
  Grid *gridExpected = GridBuild(gridEmpty);
  uint32_t linesCollected = GridCollect(gridInput);
  GridPrint(gridInput);
  assert(GridCompare(gridInput, gridExpected));
  assert(linesCollected == 1);
  GridDestroy(gridInput);
  GridDestroy(gridExpected);
}

void TestGridCollectEmpty() {
  TraceLog(LOG_INFO, "Test collect empty grid");
  Grid *gridInput = GridBuild(gridEmpty);
  Grid *gridExpected = GridBuild(gridEmpty);
  uint32_t linesCollected = GridCollect(gridInput);
  GridPrint(gridInput);
  assert(GridCompare(gridInput, gridExpected));
  assert(linesCollected == 0);
  GridDestroy(gridInput);
  GridDestroy(gridExpected);
}

void TestGridCollectFull() {
  TraceLog(LOG_INFO, "Test collect full grid");
  Grid *gridInput = GridBuild(gridFull);
  Grid *gridExpected = GridBuild(gridEmpty);
  uint32_t linesCollected = GridCollect(gridInput);
  GridPrint(gridInput);
  assert(GridCompare(gridInput, gridExpected));
  assert(linesCollected == 16);
  GridDestroy(gridInput);
  GridDestroy(gridExpected);
}

void TestGridCollectPyramid() {
  TraceLog(LOG_INFO, "Test collect pyramid grid");
  Grid *gridInput = GridBuild(gridPyramid);
  Grid *gridExpected = GridBuild(gridPyramidExpected);
  uint32_t linesCollected = GridCollect(gridInput);
  GridPrint(gridInput);
  assert(GridCompare(gridInput, gridExpected));
  assert(linesCollected == 2);
  GridDestroy(gridInput);
  GridDestroy(gridExpected);
}

void TestGridCollectHoles() {
  TraceLog(LOG_INFO, "Test collect holes grid");
  Grid *gridInput = GridBuild(gridHoles);
  Grid *gridExpected = GridBuild(gridHolesExpected);
  uint32_t linesCollected = GridCollect(gridInput);
  GridPrint(gridInput);
  assert(GridCompare(gridInput, gridExpected));
  assert(linesCollected == 2);
  GridDestroy(gridInput);
  GridDestroy(gridExpected);
}

int main(void) {
  TestGridCollectEmpty();
  TestGridCollectFull();
  TestGridCollectBottomLine();
  TestGridCollectPyramid();
  TestGridCollectHoles();
  return 0;
}
