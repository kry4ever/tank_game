#include "tank_factory.h"

Tank* mCache = NULL;
extern float scaleFactor;
float pointSize = 6;
Tank* getTank(int x, int y, enum MYKEYS direction, const char* name) {
	if (mCache != NULL) {
		mCache->x = x;
		mCache -> y = y;
		mCache->direction = direction;

		if(!mCache->point->isShoting){
			mCache->point->x = x + mCache->size/2 - pointSize/2;
			mCache->point->y = y + mCache->size/2 - pointSize/2;
			mCache->point->direction = direction;
		}
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
	float size = al_get_bitmap_width(bitmap) > al_get_bitmap_height(bitmap) ? al_get_bitmap_width(bitmap) : al_get_bitmap_height(bitmap);
	tank->size = size * scaleFactor;
	tank->direction = direction;
	tank->point = (Point*)malloc(sizeof(Point));
	tank->point->image = al_create_bitmap(pointSize, pointSize);
	tank->point->x = tank->x + tank->size/2 - pointSize/2;
	tank->point->y = tank->y + tank->size/2 - pointSize/2;
	tank->point->direction = tank->direction;
	tank->point->isShoting = false;

	al_set_target_bitmap(tank->point->image);
	al_clear_to_color(al_map_rgb(255, 255, 255));
	extern ALLEGRO_DISPLAY *display;
	al_set_target_bitmap(al_get_backbuffer(display));

	mCache = tank;
	return tank;
}
