//Library Directives
#include <curses.h>
#include <stdlib.h>

//Project Directives
#include "headers/screen.h"
#include "headers/person.h"

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
  init_pair(5, 212, 212);
  init_pair(6, 0, 9);

  Screen *s = screen_create(62,206,2,2);
  Screen *s2 = screen_create(62,60,2,210);

  Person *p = person_create(s, 18, 35, 30, 30);

  refresh();

  screen_fill(s, ".", 4);
  person_draw_body(p, "-", 6);
  person_draw_head(p, "-", 5);
  //screen_checker(s, "X", 2, 3);
  wrefresh(s->win);

  screen_fill(s2, ".", 1);
  //screen_checker(s2, "X", 4, 3);
  wrefresh(s2->win);

  free(s);
  free(s2);
  free(p);

  refresh();
  getch();
  endwin();
  return EXIT_SUCCESS;
}
