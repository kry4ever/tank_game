// test1.cpp: 定义控制台应用程序的入口点。
//
//#include "stdafx.h"
#include "framework.h"
#include "loop.h"
#include "tank.h"
#include "tank_factory.h"

int main(int argc, char **argv) {

	ALLEGRO_DISPLAY *display = NULL;
	if (!init(&display)) {
		exit(-1);
	}

	extern bool draw();
	ALLEGRO_TIMER *timer = NULL;
	int res = startLoop(&timer, display, draw);
	printf("res is %d\n", res);
	//	al_rest(15.0f);

	//	al_destroy_timer(timer);
	al_destroy_display(display);
	return 0;
}
