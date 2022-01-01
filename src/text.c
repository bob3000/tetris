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
  TextLine *textGamePaused = TextLineNew("GAME PAUSED", 40, CENTER, 40, GREEN);
  TextLine *textGameResume =
      TextLineNew("Press P to resume game", 120, CENTER, 20, GREEN);
  TextLine *textGameReset =
      TextLineNew("Press R to reset game", 140, CENTER, 20, GREEN);
  TextLine *textGameQuit =
      TextLineNew("Press Q to quit game", 160, CENTER, 20, GREEN);

  TextLineRender(textGamePaused);
  TextLineRender(textGameResume);
  TextLineRender(textGameReset);
  TextLineRender(textGameQuit);
}

void TextDisplayOver() {
  TextLine *textGameOver = TextLineNew("GAME OVER", 40, CENTER, 40, GREEN);
  TextLine *textGameResume =
      TextLineNew("Press P to resume game", 120, CENTER, 20, GREEN);
  TextLine *textGameReset =
      TextLineNew("Press R to reset game", 140, CENTER, 20, GREEN);
  TextLine *textGameQuit =
      TextLineNew("Press Q to quit game", 160, CENTER, 20, GREEN);

  TextLineRender(textGameOver);
  TextLineRender(textGameReset);
  TextLineRender(textGameQuit);
}
