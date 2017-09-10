#pragma once

#include "allegro5/allegro.h"
#include "point.h"
#include "direction.h"

typedef struct Tank{
	int id;
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
	void moveTo(Tank* tank, float x, float y);
	void movePointTo(Tank* tank, float x, float y);
	void changePosition(Tank* tank, enum MYKEYS direction);
	void move(Tank* tank, float speed);
#ifdef __cplusplus
}
#endif // __cplusplus
