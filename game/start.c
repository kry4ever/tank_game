// test1.cpp: 定义控制台应用程序的入口点。
//
//#include "stdafx.h"
#include "framework.h"
#include "loop.h"
#include "tank.h"
#include "tank_factory.h"



int main(int argc, char **argv) {

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_TIMER *timer = NULL;
	if (!init(&display)) {
		fprintf(stderr, "failed to init");
		return -1;
	}

	extern bool draw(float, float);
	startLoop(&timer, display, draw);
	return 0;
}
