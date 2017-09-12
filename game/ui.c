#include "tank.h"
#include "tank_factory.h"
#include "global.h"
#include <stdlib.h>
#include <time.h>
#include "point.h"
#include "direction.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"


#ifdef __cplusplus
extern "C" {
#endif

	ALLEGRO_FONT *font;

	enum MYKEYS getRandomDirection();
	bool shot();
	bool inside(Point* point, Tank *tank);
	int getRandomPosition(int max);
	//int enemySize = 10;
	Tank *enemys[enemySize];

	void initEnemy() {
		int i;
		for (i = 1; i < enemySize; i++) {
			Tank* tank = (Tank*)getTank(i, getRandomPosition(width), getRandomPosition(height), getRandomDirection(), "../res/tank.bmp");
			enemys[i] = tank;
		}

		font = al_load_ttf_font("../res/pirulen.ttf", 72, 0);
		assert(font != NULL);
	}

	bool draw(float x, float y, enum MYKEYS direction) {
		//		printf("x is %f, y si %f\n", x, y);
		Tank* self = (Tank*)getTank(0, x, y, direction, "../res/tank.bmp");
		moveTo(self, x, y);
		movePointTo(self, x, y);
		changePosition(self, direction);
		drawTank(self, true);
		if (self->point->isShoting) {
			drawPoint(self->point);
		}


		int i;
		srand((unsigned)time(NULL));

		for (i = 1; i < enemySize; i++) {
			Tank* tank = enemys[i];
			if (tank != NULL) {
				move(tank, 1);

				if (tank->x <= 0 ||
					tank->x >= (width - tank->size) ||
					tank->y <= 0 ||
					tank->y >= (height - tank->size)) {
					changePosition(tank, getRandomDirection());
				}

				if (!tank->point->isShoting) {
					tank->point->isShoting = true;
				}

				if (tank->point->isShoting) {
					drawPoint(tank->point);
				}

				if (inside(self->point, tank)) {
					ALLEGRO_BITMAP *bitmap = al_load_bitmap("../res/boom.bmp");
					assert(bitmap != NULL);
					changeBitmap(tank, bitmap);
					tank->state = BESHOTED;
				}
				else if (tank->state == BESHOTED) {
					enemys[i] = NULL;
				}

				if (inside(tank->point, self)) {
					extern bool(*drawFrame)(float, float, enum MYKEYS);
					extern bool drawGameOver(float x, float y, enum MYKEYS direction);
					drawFrame = drawGameOver;
				}


				drawTank(tank, false);
			}
		}
		al_flip_display();
		return true;
	}


	bool drawGameOver(float x, float y, enum MYKEYS direction) {
		al_draw_text(font, al_map_rgb(255, 255, 255), width / 2, (height / 4), ALLEGRO_ALIGN_CENTRE, "GAME OVER");
		al_flip_display();
	}


	int getRandomPosition(int max) {
		//srand( (unsigned)time( NULL ) );
		int res = rand() % max + 1;
		//printf("pos is %d\n", res);
		return res;
	}


	enum MYKEYS getRandomDirection() {
		return rand() % KEY_ALL;
	}

	bool shot() {
		return rand() % 2 == 0;
	}

	bool inside(Point* point, Tank *tank) {
		return point->x > tank->x && point->x < tank->x + tank->size && point->y > tank->y && point->y < tank->y + tank->size;
	}

#ifdef __cplusplus
}
#endif
