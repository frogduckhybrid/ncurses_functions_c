//Library Directives
#include <curses.h>
#include <stdlib.h>

//Project Directives
#include "../headers/person.h"
#include "../headers/screen.h"


//Functions
Person*  person_create(Screen *s, int h, int w, int y, int x){
  Person* result = (Person*)malloc(sizeof(Person));
  result->scr = s;
  result->h = h;
  result->w = w;
  result->y = y;
  result->x = x;
  return result;
}

void person_draw_body(Person *p, const char* c, int col){
  wattron(p->scr->win, COLOR_PAIR(col));
  for(int i = p->scr->h; i > p->scr->h - p->h; i--)
    mvwhline(p->scr->win, i, 0, *c, p->w);
  wattroff(p->scr->win, COLOR_PAIR(col));
}

//TODO stick these in the struct
const int head_h = 30;
const int head_offset = 4;

void person_draw_head(Person *p, const char* c, int col){
  wattron(p->scr->win, COLOR_PAIR(col));
  for(int i = p->scr->h - p->h; i > p->scr->h - head_h; i--)
    mvwhline(p->scr->win, i, head_offset, *c, p->w - head_offset*2);
  wattroff(p->scr->win, COLOR_PAIR(col));
}
