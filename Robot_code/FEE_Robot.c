/*******************************    INCLUDES   ********************************/

#include "FEE_Robot.h"
//#include "usbd_customhid.h"

/*******************************    DEFINITONS   ******************************/

//#define PI 3.141592654
//extern USBD_HandleTypeDef 			        *pdev1;
//extern USBD_CUSTOM_HID_HandleTypeDef        *hhid1;
/***************************    GLOBAL VARIABLES   ****************************/


void control_xilanh(int xilanh_number, uint8_t trang_thai_xilanh) {
	// kep vao
	if(trang_thai_xilanh == 1) {
		
		if(xilanh_number == 1) 
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 1); 
		if(xilanh_number == 2)  
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 1); 
		if(xilanh_number == 3) 
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1); 
		if(xilanh_number == 4) 
			 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, 1); 
		
		// tay 2 
		
		if(xilanh_number == 5) 
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 1); 
		if(xilanh_number == 6) 
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1); 
		if(xilanh_number == 7) 
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 1); 
		if(xilanh_number == 8) 
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1); 
		
	}
	//mo ra  
	if(trang_thai_xilanh == 0) {
		
		if(xilanh_number == 1) 
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, 0); 
		if(xilanh_number == 2)  
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0); 
		if(xilanh_number == 3) 
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
		if(xilanh_number == 4) 
			 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, 0); 
		
		// tay 2 
		
		if(xilanh_number == 5) 
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 0); 
		if(xilanh_number == 6) 
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);
		if(xilanh_number == 7) 
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0); 
		if(xilanh_number == 8) 
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0); 
		
	}

}

void ve_vi_tri_0(void) {
	
	
	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15)) {
		pid_dc3(1, 40);
	}
	else 
		pid_dc3(0, 1);
	
	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) == 0) {
		pid_dc2(1, 40);
	}
	else 
		pid_dc2(0, 1);
	
	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5) == 0) {
		pid_dc1(1, 40);
	}
	else 
		pid_dc1(0, 1);
	
}
	

void nang_canh_tay(int toc_do) {
	pid_dc3(0, toc_do);
}
	
void ha_canh_tay(int toc_do) {
	pid_dc3(1, toc_do);
}

void xoay_canh_tay(int tay_number, int chieu, int toc_do) {
	if(tay_number == 1) {
		if(chieu == 0) 
			pid_dc1(0, toc_do);
		else
			pid_dc1(1, toc_do);
	}
	if(tay_number == 2) {
		if(chieu == 0) 
			pid_dc2(0, toc_do);
		else
			pid_dc2(1, toc_do);
	}
}








