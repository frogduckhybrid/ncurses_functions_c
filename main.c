#include <curses.h>
#include <stdlib.h>

#include "headers/screen.h"

#define MAIN_SCR_H 50
#define MAIN_SCR_W 100
#define MAIN_SCR_Y 1
#define MAIN_SCR_X 1

#define SIDEBAR_H 50
#define SIDEBAR_W 20
#define SIDEBAR_Y 1
#define SIDEBAR_X MAIN_SCR_W+1

int main(int argc, char** argv){

  //Initialise ncurses
  initscr();
  cbreak();
  raw();
  noecho();
  start_color();

  //Initialise colours
  init_pair(1,0,0); //FG: black, BG: black
  init_pair(2,9,9); //FG: red, BG: red
  init_pair(3,12,12); //FG: blue, BG: blue
  init_pair(4, 13, 13);
  init_pair(5, 15, 15);

  Screen *s = screen_create(MAIN_SCR_H, MAIN_SCR_W, MAIN_SCR_Y, MAIN_SCR_X);
  Screen *s2 = screen_create(SIDEBAR_H, SIDEBAR_W , SIDEBAR_Y, SIDEBAR_X);
  refresh();

  screen_fill(s, ".", 2);

  screen_sin_wave(s, ".", 3, 15, 0.1);
  screen_asin_wave(s, ".", 4, 15, 0.01);

  wrefresh(s->win);

  screen_fill(s2, ".", 3);
  screen_fill_randomly(s2, 1422341, ".", 2, 50);
  wrefresh(s2->win);
  refresh();

  //Cleanup and quit
  free(s);
  free(s2);
  getch();
  endwin();
  return EXIT_SUCCESS;
}
