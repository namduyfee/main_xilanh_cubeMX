#ifndef		__FEE_ROBOT_H__
#define		__FEE_ROBOT_H__

/*******************************    INCLUDES   ********************************/
#include "main.h"
#include "stdlib.h"
#include "math.h"
/***************************    GLOBAL VARIABLES   ****************************/

extern struct FEE_RTOS_struct_def           FEE_RTOS_struct;

/***************************       FUNCTIONS       ****************************/

void dong_co_init(void); 
void tu_dong_init(void); 
void lai_tay_init(void); 
void trang_thai_init(void); 

void initTimers(void); 
void configTIM1(void); 
void configTIM3(void); 
void configTIM4(void); 

#endif


