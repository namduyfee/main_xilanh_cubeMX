

#ifndef		__FEE_TU_DONG_H__
#define		__FEE_TU_DONG_H__

/*******************************    INCLUDES   ********************************/
#include "main.h"
#include "stdlib.h"
#include "math.h"
/***************************    GLOBAL VARIABLES   ****************************/

extern struct FEE_RTOS_struct_def           FEE_RTOS_struct;

/***************************       FUNCTIONS       ****************************/

void tu_dong_1(void); 
void tu_dong_2(void);
void tu_dong_3(void); 
void tu_dong_4(void); 
void tu_dong_5(void); 
void tu_dong_6(void); 
void tinh_vi_tri_tay_xoay(uint8_t tay_number); 
void chong_troi(void); 
void reset_chong_troi(void); 
void xoay_chong_troi(uint8_t tay_number, uint16_t toc_do); 

#endif
