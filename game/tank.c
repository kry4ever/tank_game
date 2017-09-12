#include "tank.h"
#include "stdio.h"
#include "global.h"
#include "point.h"

const float PI = 3.1415926f;
const float scaleFactor = 0.1f;
void drawTank(Tank* tank, bool self)
{
	assert(tank != NULL);
	int bitmapWidth = al_get_bitmap_width(tank->image);
	int bitmapHeight = al_get_bitmap_height(tank->image);
	float angle = 90;
	if(tank->x < 0){
		tank->x = 0;
	}

	//extern int width;
	if(tank->x > width-tank->size){
		tank->x = width -tank->size;
	}

	if(tank->y < 0){
		tank->y = 0;
	}

	//extern int height;
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

	if (self) {
		al_draw_scaled_rotated_bitmap(tank->image,
			0,
			0,
			dx,
			dy,
			scaleFactor,
			scaleFactor,
			angle * PI / 180,
			0);
	}
	else {
		al_draw_tinted_scaled_rotated_bitmap(tank->image,
			al_map_rgba_f(1, 0.5, 0.5, 0.5),
			0,
			0,
			dx,
			dy,
			scaleFactor,
			scaleFactor,
			angle * PI / 180,
			0);
	}
	
}


void moveTo(Tank* tank, float x, float y){
	tank->x = x;
	tank->y = y;
}

void movePointTo(Tank* tank, float x, float y){
	if(!tank->point->isShoting){
		tank->point->x = x + tank->size/2 - pointSize/2;
		tank->point->y = y + tank->size/2 - pointSize/2;
	}
}
void changePosition(Tank* tank, enum MYKEYS direction){
	tank->direction = direction;
	if(!tank->point->isShoting){
		tank->point->direction = direction;
	}
}

void move(Tank* tank, float speed){
	switch(tank->direction){
	case KEY_DOWN:
		tank->y += speed;
		break;

	case KEY_UP:
		tank->y -= speed;
		break;

	case KEY_LEFT:
		tank->x -= speed;
		break;

	case KEY_RIGHT:
		tank->x += speed;
		break;

	}
}

void changeBitmap(Tank * tank, ALLEGRO_BITMAP * bitmap)
{
	tank->image = bitmap;
}
