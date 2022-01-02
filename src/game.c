#include "libtetris.h"

Game *GameNew() {
  Game *game = (Game *)MemAlloc(sizeof(Game));
  game->state = GameOver;
  game->score = 0;
  game->level = 1;
  game->numFormations = 0;
  return game;
}

void GameDestroy(Game *game) { MemFree(game); }

void GameReset(Game *game) {
  game->state = GameOver;
  game->score = 0;
  game->level = 1;
  game->numFormations = 0;
}

void GameSetState(Game *game, GameState state) { game->state = state; }
void GameTogglePaused(Game *game) {
  if (game->state == GamePaused) {
    game->state = GameRunning;
  } else if (game->state == GameRunning) {
    game->state = GamePaused;
  }
}

void GameScoreAdd(Game *game, ScoreEvent event, uint8_t times) {
  uint32_t score;
  switch (event) {
  case FormationPut:
    score = SCORE_FORMATION_PUT;
    break;
  case LineCollected:
    score = SCORE_LINE_COLLECTED;
    break;
  }
  for (uint32_t i = 1; i <= times; i++) {
    game->score += score * i;
  }
}

void GameFormationInc(Game *game) {
  game->numFormations += 1;
  if ((game->numFormations % FORMATIONS_TO_NEXT_LEVEL) == 0) {
    game->level += 1;
  }
}
