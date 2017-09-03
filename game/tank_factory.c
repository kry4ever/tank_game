#include "tank_factory.h"

static Tank* mCache = NULL;
Tank* getTank(int x, int y, enum MYKEYS direction, const char* name) {
	if (mCache != NULL) {
		mCache->x = x;
		mCache -> y = y;
		mCache->direction = direction;
		return mCache;
	}

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
	tank->direction = direction;
	mCache = tank;
	return tank;
}