#include "tank.h"

const float PI = 3.1415926f;
 void drawTank(Tank* tank)
{
	assert(tank != NULL);
	int bitmapWidth = al_get_bitmap_width(tank->image);
	int bitmapHeight = al_get_bitmap_height(tank->image);
	float scaleFactor = 0.1f;
	float angle = 0;
	switch(tank->direction){
	case KEY_UP:
		angle = 0;
		break;

	case KEY_DOWN:
		angle = 180;
		break;

	case KEY_LEFT:
		angle = 270;
		break;

	case KEY_RIGHT:
		angle = 90;
		break;
	}

	printf("y is %f\n", tank->y);
	al_draw_scaled_rotated_bitmap(tank->image,
								  tank->x,
								  tank->y,
								  tank->x,
								  tank->y,
								  scaleFactor,
								  scaleFactor,
								  angle * PI/180,
								  0);
	al_flip_display();
}
