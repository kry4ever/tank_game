#pragma once

#include "tank.h"
#include "stdio.h"
#include "malloc.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	Tank* getTank(int x, int y, const char* name) {
		ALLEGRO_BITMAP *bitmap = al_load_bitmap(name);
		if (!bitmap)
		{
			fprintf(stderr, "failed to al_load_bitmap\n");
			return NULL;
		}

		Tank* tank = (Tank*)malloc(sizeof(Tank));
		tank->image = bitmap;
		tank->x = x;
		tank->y = y;
		return tank;
	}
#ifdef __cplusplus
}
#endif // __cplusplus
