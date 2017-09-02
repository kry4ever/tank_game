#include "tank.h"
#include "tank_factory.h"

#ifdef __cplusplus
extern "C" {
#endif

	bool draw(float x, float y) {
		printf("x is %f, y si %f\n", x, y);
		Tank* tank = (Tank*)getTank(x, y, "../res/tank.bmp");
		drawTank(tank);
		return true;
	}

#ifdef __cplusplus
}
#endif
