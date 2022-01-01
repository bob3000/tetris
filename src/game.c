#include "libtetris.h"

Game *GameNew() {
  Game *game = (Game *)MemAlloc(sizeof(Game));
  game->state = GameOver;
  game->score = 0;
  game->level = 0;
  return game;
}

void GameDestroy(Game *game) { MemFree(game); }

void GameReset(Game *game) {
  game->state = GameOver;
  game->score = 0;
  game->level = 0;
}

void GameSetState(Game *game, GameState state) { game->state = state; }
void GameTogglePaused(Game *game) {
  if (game->state == GamePaused) {
    game->state = GameRunning;
  } else if (game->state == GameRunning) {
    game->state = GamePaused;
  }
}
