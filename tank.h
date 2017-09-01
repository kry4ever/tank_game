#pragma once

#include <allegro5/allegro.h>

typedef struct Tank{
	ALLEGRO_BITMAP *image;
	int x, y;
	int size;
}Tank;


#ifdef __cplusplus
extern "C" {
#endif

	void drawTank(Tank* tank);

#ifdef __cplusplus
}
#endif // __cplusplus
