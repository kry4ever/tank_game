#include "point.h"
#include <assert.h>
#include <stdio.h>

float step = 10;
void drawPoint(Point* p){
  assert(p != NULL);
  al_draw_bitmap(p->image, p->x, p->y, 0);
  al_flip_display();
  switch(p->direction){
  case KEY_DOWN:
    p->y += step;
    break;

  case KEY_LEFT:
    p->x -= step;
    break;


  case KEY_RIGHT:
    p->x += step;
    break;


  case KEY_UP:
    p->y -= step;
    break;
  }

  //  printf("p is %p, x is %f, y is %f, direction %d\n",&(p->x), p->x, p->y, p->direction);
  extern int width;
  extern int height;
  if(p->x > width || p->x < 0 || p->y <0 || p->y > height){
    p->isShoting = false;
  }
}
