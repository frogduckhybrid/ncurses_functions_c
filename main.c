//Library Directives
#include <curses.h>
#include <stdlib.h>

//Project Directives
#include "headers/screen.h"

#define WIDTH 265
#define HEIGHT 77

//Main Function
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

  
  Screen *s = (Screen*)malloc(sizeof(Screen));
  Screen *s2 = (Screen*)malloc(sizeof(Screen));
  
  screen_create(s, 30, 60, 0, 0);
  screen_create(s2, 30, 60, 0, 61);
  refresh();

  screen_fill(s, ".", 1);
  screen_checker(s, "X", 2, 3);
  wrefresh(s->win);

  screen_fill(s2, ".", 3);
  screen_checker(s2, "X", 4, 3);
  wrefresh(s2->win);

  free(s);
  free(s2);
  
  refresh();
  getch();
  endwin();
  return EXIT_SUCCESS;
}

