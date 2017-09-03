#pragma once

#include "allegro5/allegro.h"

enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

typedef struct Tank{
	ALLEGRO_BITMAP *image;
	float x, y;
	float size;
	enum MYKEYS direction;
}Tank;


#ifdef __cplusplus
extern "C" {
#endif

	void drawTank(Tank* tank);

#ifdef __cplusplus
}
#endif // __cplusplus
