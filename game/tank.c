
#include "tank.h"

 void drawTank(Tank* tank)
{
	assert(tank != NULL);
	int bitmapWidth = al_get_bitmap_width(tank->image);
	int bitmapHeight = al_get_bitmap_height(tank->image);
	int scaleFactor = 10;
	al_draw_scaled_bitmap(tank->image, 0, 0,
		bitmapWidth,
		bitmapHeight,
		tank->x,
		tank->y,
		bitmapWidth / scaleFactor,
		bitmapHeight / scaleFactor, 0);
	al_flip_display();
}
