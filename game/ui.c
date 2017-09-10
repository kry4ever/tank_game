#include "tank.h"
#include "tank_factory.h"
#include "global.h"
#include <stdlib.h>
#include <time.h>
#include "direction.h"


#ifdef __cplusplus
extern "C" {
#endif

	enum MYKEYS getRandomDirection();
	bool shot();
	//int enemySize = 10;
	bool draw(float x, float y, enum MYKEYS direction) {
		//		printf("x is %f, y si %f\n", x, y);
		Tank* tank = (Tank*)getTank(0, x, y, direction, "../res/tank.bmp");
		moveTo(tank, x, y);
		movePointTo(tank, x, y);
		changePosition(tank, direction);
		drawTank(tank);
		if(tank->point->isShoting){
			drawPoint(tank->point);
		}


		int i;
		srand( (unsigned)time( NULL ) );
		for(i = 1; i < enemySize; i++){
				Tank* tank = (Tank*)getTank(i, getRandomPosition(width), getRandomPosition(height), getRandomDirection(), "../res/tank.bmp");
				move(tank, 1);
				drawTank(tank);
				if(tank->x <= 0 ||
				   tank->x >= (width-tank->size) ||
				   tank->y <= 0 ||
				   tank->y >= (height-tank->size)){
				   changePosition(tank, getRandomDirection());
				}

				if(!tank->point->isShoting){
					printf("here %d\n", i);
					tank->point->isShoting = true;
				}

				if(tank->point->isShoting){
					drawPoint(tank->point);
				}


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

#ifdef __cplusplus
}
#endif
