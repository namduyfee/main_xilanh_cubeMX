
#ifndef		__FEE_FUNCTION_H__
#define		__FEE_FUNCTION_H__

/*******************************    INCLUDES   ********************************/
#include "main.h"
#include "stdlib.h"
#include "math.h"
/***************************    GLOBAL VARIABLES   ****************************/

extern struct FEE_RTOS_struct_def           FEE_RTOS_struct;

/***************************       FUNCTIONS       ****************************/

void control_xilanh(int xilanh_number, uint8_t trang_thai_xilanh); 

void kep_chan(void); 
void nha_chan(void); 
void kep_le(void); 
void nha_le(void); 

void khoa_dc_tay(uint8_t dc_number); 
void xoay_phai(uint8_t tay_number, uint16_t toc_do); 
void xoay_trai(uint8_t tay_number, uint16_t toc_do); 

void nang_canh_tay(uint16_t toc_do); 
void ha_canh_tay(uint16_t toc_do); 

void khoi_tao_tu_dong(void); 
void khoi_tao_kep_lua(void);
void khoi_tao_an_toan(); 
void delayUs(uint32_t us); 
void reset_check_xoay_tay_1(void); 
void reset_check_xoay_tay_2(void); 
void reset_nang_ha(void); 
int check_nang_ha(float second_limit); 

int check_xoay_tay_1(float second_limit); 
int check_xoay_tay_2(float second_limit); 
void kep(uint8_t chan_le); 
void nha(uint8_t chan_le); 

void day_tay_gap_lua(void); 
void thu_tay_gap_lua(void); 
void nang_tay_kep_bong(void); 
void ha_tay_kep_bong(void); 
void kep_bong(void); 
void nha_bong(void); 
void start_dc_keo_sung(void); 
void stop_dc_keo_sung(void); 

#endif
