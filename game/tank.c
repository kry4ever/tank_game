#include "tank.h"
#include "stdio.h"

const float PI = 3.1415926f;
const float scaleFactor = 0.1f;
void drawTank(Tank* tank)
{
	assert(tank != NULL);
	int bitmapWidth = al_get_bitmap_width(tank->image);
	int bitmapHeight = al_get_bitmap_height(tank->image);
	float angle = 90;
	if(tank->x < 0){
		tank->x = 0;
	}

	extern int width;
	if(tank->x > width-tank->size){
		tank->x = width -tank->size;
	}

	if(tank->y < 0){
		tank->y = 0;
	}

	extern int height;
	if(tank->y > height - tank->size){
		tank->y = height - tank->size;
	}


	float dx = tank->x;
	float dy = tank->y;
	switch (tank->direction) {
	case KEY_UP:
		angle = 0;
		break;

	case KEY_DOWN:
		angle = 180;
		dx += tank->size;
		dy += tank->size;
		break;

	case KEY_LEFT:
		angle = 270;
		dy += tank->size;
		break;

	case KEY_RIGHT:
		angle = 90;
		dx += tank->size;
		break;
	}

	//	printf("x is %f, y is %f, size is %f\n", tank->x, tank->y, tank->size);
	al_draw_scaled_rotated_bitmap(tank->image,
		0,
		0,
		dx,
		dy,
		scaleFactor,
		scaleFactor,
		angle * PI / 180,
		0);
	al_flip_display();
}
