#pragma once

#include "allegro5/allegro.h"
#include "direction.h"
#include <stdbool.h>

struct _Tank{
	int id;
	ALLEGRO_BITMAP *image;
	float x, y;
	float size;
	enum MYKEYS direction;
	struct _Point *point;
};

typedef struct _Tank Tank;

#ifdef __cplusplus
extern "C" {
#endif

	void drawTank(Tank* tank, bool self);
	void moveTo(Tank* tank, float x, float y);
	void movePointTo(Tank* tank, float x, float y);
	void changePosition(Tank* tank, enum MYKEYS direction);
	void move(Tank* tank, float speed);
#ifdef __cplusplus
}
#endif // __cplusplus
