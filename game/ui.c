#include "tank.h"
#include "tank_factory.h"
#include "global.h"
#include <stdlib.h>
#include <time.h>
#include "point.h"
#include "direction.h"


#ifdef __cplusplus
extern "C" {
#endif

	enum MYKEYS getRandomDirection();
	bool shot();
	bool inside(Point* point, Tank *tank);
	int getRandomPosition(int max);
	//int enemySize = 10;
	Tank *enemys[enemySize];
	bool draw(float x, float y, enum MYKEYS direction) {
		//		printf("x is %f, y si %f\n", x, y);
		Tank* self = (Tank*)getTank(0, x, y, direction, "../res/tank.bmp");
		moveTo(self, x, y);
		movePointTo(self, x, y);
		changePosition(self, direction);
		drawTank(self, true);
		if(self->point->isShoting){
			drawPoint(self->point);
		}


		int i;
		srand( (unsigned)time( NULL ) );
		for(i = 1; i < enemySize; i++){
				Tank* tank = (Tank*)getTank(i, getRandomPosition(width), getRandomPosition(height), getRandomDirection(), "../res/tank.bmp");
				move(tank, 1);

				if(tank->x <= 0 ||
				   tank->x >= (width-tank->size) ||
				   tank->y <= 0 ||
				   tank->y >= (height-tank->size)){
				   changePosition(tank, getRandomDirection());
				}

				if(!tank->point->isShoting){
					tank->point->isShoting = true;
				}

				if(tank->point->isShoting){
					drawPoint(tank->point);
				}

				if (inside(self->point, tank)) {
					printf("i hit %d\n", tank->id);
				}

				drawTank(tank, false);

		}
		al_flip_display();
		return true;
	}


	int getRandomPosition(int max){
			//srand( (unsigned)time( NULL ) );
		int res = rand()%max+1;
		//printf("pos is %d\n", res);
		return res;
	}


	enum MYKEYS getRandomDirection(){
			return rand()%KEY_ALL;
	}

	bool shot(){
		return rand()%2 == 0;
	}

	bool inside(Point* point, Tank *tank) {
		return point->x > tank->x && point->x < tank->x + tank->size && point->y > tank->y && point->y < tank->y + tank->size;
	}

#ifdef __cplusplus
}
#endif
