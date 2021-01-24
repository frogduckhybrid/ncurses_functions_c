#include <curses.h>
#include <stdlib.h>

#include "headers/screen.h"

#define MAIN_SCR_H 40
#define MAIN_SCR_W 60
#define MAIN_SCR_Y 1
#define MAIN_SCR_X 1

#define SIDEBAR_H 40
#define SIDEBAR_W 20
#define SIDEBAR_Y 1
#define SIDEBAR_X 42

int main(int argc, char** argv){

  //Initialise ncurses
  initscr();
  cbreak();
  raw();
  noecho();
  start_color();

  //Initialise colours
  init_pair(1,9,0); //FG: red, BG: black
  init_pair(2,12,0); //FG: blue, BG: black
  init_pair(3,9,9); //FG: red, BG: red
  init_pair(4,12,12); //FG: blue, BG: blue

  Screen *s = screen_create(MAIN_SCR_H, MAIN_SCR_W, MAIN_SCR_Y, MAIN_SCR_X);
  Screen *s2 = screen_create(SIDEBAR_H, SIDEBAR_W , SIDEBAR_Y, SIDEBAR_X);
  refresh();

  screen_fill(s, ".", 4);
  screen_sine_wave(s, ".", 3, 8, 0.3);
  wrefresh(s->win);

  screen_fill(s2, ".", 1);
  wrefresh(s2->win);
  refresh();

  //Cleanup and quit
  free(s);
  free(s2);
  getch();
  endwin();
  return EXIT_SUCCESS;
}
