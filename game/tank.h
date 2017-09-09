#pragma once

#include "allegro5/allegro.h"
#include "point.h"
#include "direction.h"

typedef struct Tank{
	ALLEGRO_BITMAP *image;
	float x, y;
	float size;
	enum MYKEYS direction;
	Point *point;
}Tank;


#ifdef __cplusplus
extern "C" {
#endif

	void drawTank(Tank* tank);

#ifdef __cplusplus
}
#endif // __cplusplus
