#include "stdbool.h"
#include <allegro5/allegro.h>
#include "event_dispatcher.h"
#include "tank.h"

bool key[4] = { false, false, false, false };

float x = 0;
float y = 0;
enum MYKEYS currentDirection = KEY_UP;

void dispatchKeyDown(int keyCode)
{
	switch (keyCode) {
	case ALLEGRO_KEY_UP:
		key[KEY_UP] = true;
		currentDirection = KEY_UP;
		break;

	case ALLEGRO_KEY_DOWN:
		key[KEY_DOWN] = true;
		currentDirection = KEY_DOWN;
		break;

	case ALLEGRO_KEY_LEFT:
		key[KEY_LEFT] = true;
		currentDirection = KEY_LEFT;
		break;

	case ALLEGRO_KEY_RIGHT:
		key[KEY_RIGHT] = true;
		currentDirection = KEY_RIGHT;
		break;
	}
}

void dispatchKeyUp(int keyCode)
{
	switch (keyCode) {
	case ALLEGRO_KEY_UP:
		key[KEY_UP] = false;
		break;

	case ALLEGRO_KEY_DOWN:
		key[KEY_DOWN] = false;
		break;

	case ALLEGRO_KEY_LEFT:
		key[KEY_LEFT] = false;
		break;

	case ALLEGRO_KEY_RIGHT:
		key[KEY_RIGHT] = false;
		break;
	}
}

extern int width,height;
void dispatchTimer()
{
	if (key[KEY_UP]) {
		y -= 4.0;
	}

	if (key[KEY_DOWN]) {
		y += 4.0;
	}

	if (key[KEY_LEFT]) {
		x -= 4.0;
	}

	if (key[KEY_RIGHT]) {
		x += 4.0;
	}

	if(x >= width){
		x = width;
	}

	if(x < 0){
		x = 0;
	}

	if(y >= height){
		y = height;
	}

	if(y < 0){
		y = 0;
	}

}

void dispatchDraw()
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	extern draw(float, float, enum MYKEYS);
	draw(x, y, currentDirection);
}
