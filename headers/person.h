#ifndef PERSON_H
#define PERSON_H

//Library Directives
#include <curses.h>

//Project Directives
#include "screen.h"

//Struct Definition
typedef struct Person{
Screen *scr;
int h;
int w;
int y;
int x;
}Person;


//Functions
Person* person_create(Screen *s, int h, int w, int y, int x);
void person_draw_body(Person *p, const char* c, int col);
void person_draw_head(Person *p, const char* c, int col);

#endif
