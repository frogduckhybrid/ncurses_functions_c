//Library Directives
#include <curses.h>
#include <stdlib.h>

//Project Directives
#include "../headers/screen.h"

//Functions
void screen_create(Screen *s, int h, int w, int y, int x){
  s->win =  newwin(h, w, y, x);
  s->h = h;
  s->w = w;
  s->y = y;
  s->x = x;
}

void screen_fill(Screen *s, const char* c, int col){
  wattron(s->win, COLOR_PAIR(col));
  for(int i = 0; i < s->h; i++)
    mvwhline(s->win, i, 0, *c, s->w);
    
  wattroff(s->win, COLOR_PAIR(col));
}

void screen_fill_randomly(Screen *s, int seed, const char *c, int col, int chance){
  srand(seed);

  wattron(s->win, COLOR_PAIR(col));
  
  for(int i = 0; i < s->h; i++)
    for(int j = 0; j < s->w; j++)
      if((rand() % 100) +1 < chance)
        mvwprintw(s->win, i, j, c);
  
  wattroff(s->win, COLOR_PAIR(col));
}

void screen_cross(Screen *s, const char* c, int col, int y, int x){
  wattron(s->win, COLOR_PAIR(col));
  mvwhline(s->win, y, 0, *c, s->w);
  mvwvline(s->win, 0, x*2, *c, s->h);
  mvwvline(s->win, 0, x*2+1, *c, s->h);
  wattroff(s->win, COLOR_PAIR(col));
}

void screen_grid(Screen *s, const char* c, int col, int spacing, int y_offset, int x_offset){
  int max = s->h > s->w ? s->h : s->w;
  spacing = spacing+1;
  for(int i = 0; i < max; i += spacing)
    screen_cross(s, c, col, i+y_offset, i+x_offset);
}

void screen_dotted_v_line(Screen *s, const char* c, int col, int y, int spacing){
  spacing *= 2;
  wattron(s->win, COLOR_PAIR(col));
  for(int i = 0; i < s->w; i+=spacing*2){
    mvwhline(s->win, y, i, *c, spacing);
  }

  wattroff(s->win, COLOR_PAIR(col));
}

void screen_dotted_h_line(Screen *s, const char* c, int col, int x, int spacing){
  wattron(s->win, COLOR_PAIR(col));

  for(int i = 0; i < s->w; i+=spacing*2){
    mvwvline(s->win, i, x+x, *c, spacing);
    mvwvline(s->win, i, x+x+1, *c, spacing);
  }
  wattroff(s->win, COLOR_PAIR(col));
}

void screen_polka_dot(Screen *s, const char* c, int col, int spacing){
  wattron(s->win, COLOR_PAIR(col));

  for(int i = 0; i < s->w; i += spacing*4)
    for(int j = 0; j < spacing*2; j++)
      for(int k = 0; k < s->h; k+=spacing*2)
        mvwvline(s->win, k, j+i, *c, spacing);
  
  wattroff(s->win, COLOR_PAIR(col));
}

void screen_checker(Screen *s, const char* c, int col, int spacing){
  wattron(s->win, COLOR_PAIR(col));

  for(int i = 0; i < s->w; i+=spacing*4)
    for(int j = 0; j < spacing*2; j++)
      for(int k = 0; k < s->h; k += spacing * 2){
        mvwvline(s->win, k, j+i, *c, spacing);
        mvwvline(s->win, k+spacing, j+i+spacing*2, *c, spacing);
      }

  wattroff(s->win, COLOR_PAIR(col));
}
