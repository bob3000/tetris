#include "libtetris.h"
#include <assert.h>
#include <stdio.h>

void TestCollisionBickRight(void) {
  Grid *grid = GridNew();
  Formation *activeForamtion = FormationNew(grid, Line, 100.0f, 150.0f, BLACK);
  Formation *passiveForamtion = FormationNew(grid, Line, 150.0f, 150.0f, BLACK);
  FormationPersist(passiveForamtion);
  FormationDestroy(passiveForamtion);
  Collision collision =
      FormationCollisionCheck(activeForamtion, TRANSITION_RIGHT);
  FormationDestroy(activeForamtion);
  GridDestroy(grid);
  assert(collision == CollisionBrickRight);
}

void TestCollisionBrickLeft(void) {
  Grid *grid = GridNew();
  Formation *activeForamtion = FormationNew(grid, Line, 150.0f, 150.0f, BLACK);
  Formation *passiveForamtion = FormationNew(grid, Line, 100.0f, 150.0f, BLACK);
  FormationPersist(passiveForamtion);
  FormationDestroy(passiveForamtion);
  Collision collision =
      FormationCollisionCheck(activeForamtion, TRANSITION_LEFT);
  FormationDestroy(activeForamtion);
  GridDestroy(grid);
  assert(collision == CollisionBrickLeft);
}

void TestCollisionBrickTop(void) {
  Grid *grid = GridNew();
  Formation *activeForamtion = FormationNew(grid, Line, 150.0f, 150.0f, BLACK);
  Formation *passiveForamtion = FormationNew(grid, Line, 150.0f, 350.0f, BLACK);
  FormationPersist(passiveForamtion);
  FormationDestroy(passiveForamtion);
  Collision collision =
      FormationCollisionCheck(activeForamtion, TRANSITION_DOWN);
  FormationDestroy(activeForamtion);
  GridDestroy(grid);
  assert(collision == CollisionBrickTop);
}

void TestCollisionWallRight(void) {
  Grid *grid = GridNew();
  Formation *activeForamtion =
      FormationNew(grid, Line, SCREEN_WIDTH - BRICK_WIDTH, 150.0f, BLACK);
  Collision collision =
      FormationCollisionCheck(activeForamtion, TRANSITION_RIGHT);
  FormationDestroy(activeForamtion);
  GridDestroy(grid);
  assert(collision == CollisionWallRight);
}

void TestCollisionWallLeft(void) {
  Grid *grid = GridNew();
  Formation *activeForamtion = FormationNew(grid, Line, 0.0f, 150.0f, BLACK);
  Collision collision =
      FormationCollisionCheck(activeForamtion, TRANSITION_LEFT);
  FormationDestroy(activeForamtion);
  GridDestroy(grid);
  assert(collision == CollisionWallLeft);
}

void TestCollisionWallBottom(void) {
  Grid *grid = GridNew();
  Formation *activeForamtion =
      FormationNew(grid, Line, 0.0f, SCREEN_HEIGHT - BRICK_HEIGHT, BLACK);
  Collision collision =
      FormationCollisionCheck(activeForamtion, TRANSITION_DOWN);
  FormationDestroy(activeForamtion);
  GridDestroy(grid);
  assert(collision == CollisionWallBottom);
}

int main(void) {
  TestCollisionBickRight();
  TestCollisionBrickLeft();
  TestCollisionBrickTop();
  TestCollisionWallRight();
  TestCollisionWallLeft();
  TestCollisionWallBottom();
  return 0;
}
