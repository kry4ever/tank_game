#pragma once

#include "tank.h"
#include "stdio.h"
#include "malloc.h"

//#ifdef __cplusplus
//extern "C" {
//#endif // __cplusplus
Tank* getTank(int x, int y, enum MYKEYS direction, const char* name);
//#ifdef __cplusplus
//}
//#endif // __cplusplus
