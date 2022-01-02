#include "libtetris.h"

TextLine *TextLineNew(const char *body, int posY, Align align, int fontSize,
                      Color color) {
  TextLine *textLine = (TextLine *)MemAlloc(sizeof(TextLine));
  textLine->fontSize = fontSize;
  textLine->textLen = MeasureText(body, fontSize);
  textLine->posY = posY;
  textLine->color = color;
  textLine->align = align;
  textLine->body = (char *)MemAlloc(strlen(body) + 1);
  strncpy(textLine->body, body, strlen(body));
  return textLine;
}

void TextLineRender(TextLine *textLine) {
  int posX;
  switch (textLine->align) {
  case LEFT: {
    posX = 0;
    break;
  }
  case CENTER: {
    posX = (SCREEN_WIDTH / 2) - (textLine->textLen / 2);
    break;
  }
  case RIGHT: {
    posX = SCREEN_WIDTH - textLine->textLen;
    break;
  }
  }
  DrawText(textLine->body, posX, textLine->posY, textLine->fontSize, GREEN);
}

void TextLineDestroy(TextLine *textLine) { MemFree(textLine); }

void TextDisplayPause() {
  TextLine *textTitle = TextLineNew("TETRIS", 140, CENTER, 80, GREEN);
  TextLine *textGamePaused = TextLineNew("GAME PAUSED", 340, CENTER, 40, GREEN);
  TextLine *textGameResume =
      TextLineNew("Press P to resume game", 420, CENTER, 20, GREEN);
  TextLine *textGameReset =
      TextLineNew("Press R to reset game", 440, CENTER, 20, GREEN);
  TextLine *textGameQuit =
      TextLineNew("Press Q to quit game", 460, CENTER, 20, GREEN);

  TextLineRender(textTitle);
  TextLineRender(textGamePaused);
  TextLineRender(textGameResume);
  TextLineRender(textGameReset);
  TextLineRender(textGameQuit);
}

void TextDisplayOver() {
  TextLine *textTitle = TextLineNew("TETRIS", 140, CENTER, 80, GREEN);
  TextLine *textGameOver = TextLineNew("GAME OVER", 340, CENTER, 40, GREEN);
  TextLine *textGameReset =
      TextLineNew("Press R to start game", 420, CENTER, 20, GREEN);
  TextLine *textGameQuit =
      TextLineNew("Press Q to quit game", 440, CENTER, 20, GREEN);

  TextLineRender(textTitle);
  TextLineRender(textGameOver);
  TextLineRender(textGameReset);
  TextLineRender(textGameQuit);
}

void TextDisplayScore(uint32_t score) {
  char scoreText[32];
  sprintf(scoreText, "SCORE: %015d", score);
  TextLine *textScore = TextLineNew(scoreText, 0, RIGHT, 20, GREEN);
  TextLineRender(textScore);
}

void TextDisplayLevel(uint32_t level) {
  char scoreText[16];
  sprintf(scoreText, "LEVEL: %01d", level);
  TextLine *textScore = TextLineNew(scoreText, 0, LEFT, 20, GREEN);
  TextLineRender(textScore);
}
