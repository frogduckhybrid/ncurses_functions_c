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
  for(size_t i = p->scr->h - p->y; i > p->scr->h - p->h - p->y; i--)
    mvwhline(p->scr->win, i, p->x, *c, p->w);
  wattroff(p->scr->win, COLOR_PAIR(col));
}

//TODO stick these in the struct
const int head_offset = 2;

void person_draw_head(Person *p, const char* c, int col){
  wattron(p->scr->win, COLOR_PAIR(col));
  for(size_t i = p->scr->h - p->y - p->h; i > p->scr->h - p->h - p->y - p->h/2; i--)
    mvwhline(p->scr->win, i, p->x + head_offset, *c, p->w - head_offset*2);
  wattroff(p->scr->win, COLOR_PAIR(col));
}

void person_draw(Person *p, const char* c, int head_col, int body_col){
  person_draw_body(p, c, head_col);
  person_draw_head(p, c, body_col);
}
