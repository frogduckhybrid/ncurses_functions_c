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
void person_draw(Person *p, const char* c, int head_col, int body_col);

#endif
