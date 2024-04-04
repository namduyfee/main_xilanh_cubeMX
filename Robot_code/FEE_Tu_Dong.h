

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
void tu_dong_4_2(void); 
//void tu_dong_5(void); 
void tu_dong_6(void); 
void tu_dong_7(void); 
void tu_dong_8(void); 
void tu_dong_9(void); 
void tu_dong_10(void); 
void tu_dong_11_1(int vi_tri_can_den); 
void tu_dong_11_2(int vi_tri_can_den); 

void tu_dong_xoay_tha_90(void); 
void den_vi_tri_kep_lua(uint16_t toc_do); 
void xoay_180(uint8_t tay_number, uint8_t chieu_xoay, uint16_t toc_do); 
void xoay_90(uint8_t tay_number, uint8_t chieu_xoay, uint16_t toc_do); 
void nang_ha_tay_gap_tu_dong(uint8_t vi_tri_can_den, uint16_t toc_do); 

void tinh_vi_tri_tay_xoay(uint8_t tay_number); 
void so_lan_trans(uint8_t so_lan_trans); 

void reset_chong_troi(void); 
void reset_chong_troi_1(void); 
void reset_chong_troi_2(void); 
void chong_troi(uint8_t trang_thai); 																			// 0 : lay lua          1 : tha lua 
void xoay_chong_troi(uint8_t tay_number, uint16_t toc_do); 
void chong_troi_tay_1(uint8_t trang_thai); 
void chong_troi_tay_2(uint8_t trang_thai); 


void reset_khoi_dong_mem(uint8_t tay_number); 
void khoi_dong_mem(uint8_t tay_number, int goc_xoay_khoi_dong_mem); 


#endif

