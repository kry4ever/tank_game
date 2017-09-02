#include "stdbool.h"
#include <allegro5/allegro.h>
#include "event_dispatcher.h"

bool key[4] = { false, false, false, false };
enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

float x = 0;
float y = 0;

void dispatchKeyDown(int keyCode)
{
	switch (keyCode) {
	case ALLEGRO_KEY_UP:
		key[KEY_UP] = true;
		break;

	case ALLEGRO_KEY_DOWN:
		key[KEY_DOWN] = true;
		break;

	case ALLEGRO_KEY_LEFT:
		key[KEY_LEFT] = true;
		break;

	case ALLEGRO_KEY_RIGHT:
		key[KEY_RIGHT] = true;
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

}

void dispatchDraw()
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	extern draw(float, float);
	draw(x, y);
}
