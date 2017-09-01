#include "tank.h"

#ifdef __cplusplus
extern "C"{
#endif

bool draw(){
  Tank* tank = (Tank*)getTank(100, 120, "../res/tank.bmp");
  drawTank(tank);
  return true;
}

#ifdef __cplusplus
}
#endif
