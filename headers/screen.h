#ifndef SCREEN_H
#define SCREEN_H

#include <curses.h>

typedef struct Screen{
  WINDOW *win;
  int h;
  int w;
  int y;
  int x;
}Screen;

Screen* screen_create(int h, int w, int y, int x);
void screen_fill(Screen *s, const char* c, int col);
void screen_fill_randomly(Screen *s, int seed, const char*c, int col, int percent);
void screen_cross(Screen *s, const char* c, int col, int y, int x);
void screen_grid(Screen *s, const char* c, int col, int spacing, int y_offset, int x_offset);
void screen_dotted_v_line(Screen *s, const char* c, int col, int y, int spacing);
void screen_dotted_h_line(Screen *s, const char* c, int col, int x, int spacing);
void screen_polka_dot(Screen *s, const char* c, int col, int spacing);
void screen_checker(Screen *s, const char* c, int col, int spacing);

//Function pointer accepts sin, cos, etc from math.h
void screen_wave(Screen *s, const char*c, double (*fp) (double), int col, double amp, double freq);

#endif
