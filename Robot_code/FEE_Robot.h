#ifndef		__FEE_ROBOT_H__
#define		__FEE_ROBOT_H__

/*******************************    INCLUDES   ********************************/
#include "main.h"
#include "stdlib.h"
#include "math.h"
/***************************    GLOBAL VARIABLES   ****************************/

extern struct FEE_RTOS_struct_def           FEE_RTOS_struct;

/***************************       FUNCTIONS       ****************************/
void control_xilanh(int xilanh_number, uint8_t trang_thai_xilanh); 

void ve_vi_tri_0(void); 

#endif
