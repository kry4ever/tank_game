#include "allegro5/allegro.h"
#include "direction.h"
#include <stdbool.h>

typedef struct _Point{
  float x;
  float y;
  ALLEGRO_BITMAP *image;
  enum MYKEYS direction;
  bool isShoting;
  //Tank *belong;
}Point;


void drawPoint(Point* p);
