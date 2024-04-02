
#include "FEE_Function.h"

#define ngoai_cam_bien 1 
#define trong_cam_bien 0


uint8_t mode_tem; 



void delayUs(uint32_t us) {

	while(us) {
		TIM4->CNT = 0; 
		while(TIM4->CNT == 0); 
		us--; 
	}
}


void reset_check_xoay_tay_1(void) {
	TIM1->CNT = 0; 
}

void reset_check_xoay_tay_2(void) {
	TIM3->CNT = 0; 
}


void reset_nang_ha(void) {
	TIM2->CNT = 0; 
}


int check_nang_ha(float second_limit) {
	float tem1 =  5000 * second_limit; 
	int tem2 = (int)tem1; 
	if(TIM2->CNT > tem2) 
		return 1; 
	else 
		return 0; 
	
}


int check_xoay_tay_1(float second_limit) {
	float tem1 =  5000 * second_limit; 
	int tem2 = (int)tem1; 
	if(TIM1->CNT > tem2) 
		return 1; 
	else 
		return 0; 
	
}

int check_xoay_tay_2(float second_limit) {
	float tem1 = 5000 * second_limit; 
	int tem2 = (int)tem1; 
	if(TIM3->CNT > tem2) 
		return 1; 
	else 
		return 0; 
	
}


void kep_chan(void) {
		control_xilanh(FEE_RTOS_struct.TrangThai.vi_tri_tay_xilanh[2], 1); 
		control_xilanh(FEE_RTOS_struct.TrangThai.vi_tri_tay_xilanh[4], 1); 
		control_xilanh(FEE_RTOS_struct.TrangThai.vi_tri_tay_xilanh[6], 1); 
		control_xilanh(FEE_RTOS_struct.TrangThai.vi_tri_tay_xilanh[8], 1); 	
}

void nha_chan(void) {
		control_xilanh(FEE_RTOS_struct.TrangThai.vi_tri_tay_xilanh[2], 0); 
		control_xilanh(FEE_RTOS_struct.TrangThai.vi_tri_tay_xilanh[4], 0); 
		control_xilanh(FEE_RTOS_struct.TrangThai.vi_tri_tay_xilanh[6], 0); 
		control_xilanh(FEE_RTOS_struct.TrangThai.vi_tri_tay_xilanh[8], 0); 		

}

void kep_le(void) {
		control_xilanh(FEE_RTOS_struct.TrangThai.vi_tri_tay_xilanh[1], 1); 
		control_xilanh(FEE_RTOS_struct.TrangThai.vi_tri_tay_xilanh[3], 1); 
		control_xilanh(FEE_RTOS_struct.TrangThai.vi_tri_tay_xilanh[5], 1); 
		control_xilanh(FEE_RTOS_struct.TrangThai.vi_tri_tay_xilanh[7], 1); 
}

void nha_le(void) {

		control_xilanh(FEE_RTOS_struct.TrangThai.vi_tri_tay_xilanh[1], 0); 
		control_xilanh(FEE_RTOS_struct.TrangThai.vi_tri_tay_xilanh[3], 0); 
		control_xilanh(FEE_RTOS_struct.TrangThai.vi_tri_tay_xilanh[5], 0); 
		control_xilanh(FEE_RTOS_struct.TrangThai.vi_tri_tay_xilanh[7], 0); 	
}

void khoa_dc_tay(uint8_t dc_number) {
	
	if(dc_number == 1) 
		FEE_RTOS_struct.Tay_1.toc_do = 1; 
	if(dc_number ==2)
		FEE_RTOS_struct.Tay_2.toc_do = 1; 
	if(dc_number == 3) 
		FEE_RTOS_struct.Nang_ha.toc_do = 1; 
	
}


void khoi_tao_tu_dong(void) {
	
	// khoi tao canh tay de chay tu dong
	
	if(0 == FEE_PES.R1 && 0 == FEE_PES.Select) {
		if(0 == FEE_RTOS_struct.TrangThai.khoi_tao_tu_dong) {
			FEE_RTOS_struct.TrangThai.vi_tri_kep_lua = 0; 
			mode_tem = FEE_RTOS_struct.TrangThai.mode_run; 
			FEE_RTOS_struct.TrangThai.mode_run = 2; 
			
			if((GPIOB->IDR & 1<<5) == trong_cam_bien)
				xoay_trai(1, 0);
			else 
				xoay_trai(1, 20);
			
			osDelay(5);
			
			if((GPIOB->IDR & 1<<4) == trong_cam_bien)
				xoay_trai(2, 0); 
			else
				xoay_trai(2, 20); 
			
			osDelay(5);
			
			if(GPIOA->IDR & 1<<15) {
				FEE_RTOS_struct.TrangThai.home = 0; 
				ha_canh_tay(40); 
			}
			else {
				
				ha_canh_tay(0); 
			}
			if(GPIOA->IDR & 1<<15) {}
				
			else {
				khoi_tao_an_toan(); 
				FEE_RTOS_struct.TrangThai.vi_tri_kep_lua = 1; 
			}
			FEE_RTOS_struct.TrangThai.khoi_tao_tu_dong = 1; 		
		}
	}
	else 
		FEE_RTOS_struct.TrangThai.khoi_tao_tu_dong = 0; 
}


void khoi_tao_kep_lua(void) {
	FEE_RTOS_struct.TrangThai.home = 0;
	ha_canh_tay(40); 
}


void khoi_tao_an_toan(void) {
	
	FEE_RTOS_struct.TuDong.stop_nang_ha = FEE_RTOS_struct.TuDong.khoi_tao_an_toan;
	
	reset_nang_ha(); 
	
	if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha < FEE_RTOS_struct.TuDong.khoi_tao_an_toan) {
		FEE_RTOS_struct.TrangThai.len_xuong = 1;
		nang_canh_tay(30);
	}
	else if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha > FEE_RTOS_struct.TuDong.khoi_tao_an_toan) {
		FEE_RTOS_struct.TrangThai.len_xuong = 0; 
		ha_canh_tay(30);
	}	
	
}


void control_xilanh(int xilanh_number, uint8_t trang_thai_xilanh) {
	// kep vao
	if(trang_thai_xilanh == 1) {
		
		FEE_RTOS_struct.LaiTay.flag_xilanh[xilanh_number] = 1;
		
		if(xilanh_number == 1) {
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0); 

		}
		if(xilanh_number == 2)  {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 1); 
		}
		if(xilanh_number == 3) 
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1); 
		
		if(xilanh_number == 4) 
			 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, 1); 
		
		// tay 2 
		
		if(xilanh_number == 5) 
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1); 		
		if(xilanh_number == 6) 
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0); 
		if(xilanh_number == 7) 
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0); 
		if(xilanh_number == 8) 
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0); 		
	}
	//mo ra  
	if(trang_thai_xilanh == 0) {
		
		FEE_RTOS_struct.LaiTay.flag_xilanh[xilanh_number] = 0;
		
		if(xilanh_number == 1) {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1); 
 
		}
		if(xilanh_number == 2)  {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0); 
		}
		if(xilanh_number == 3) 
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0); 
		
		if(xilanh_number == 4) 
			 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, 0); 
		
		// tay 2 
	
		if(xilanh_number == 5) 
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0); 		
		if(xilanh_number == 6) 
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1); 
		if(xilanh_number == 7) 
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1); 
		if(xilanh_number == 8) 
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1); 		
	}
}


void xoay_phai(uint8_t tay_number, uint16_t toc_do) {
	if(tay_number ==1) {
		FEE_RTOS_struct.Tay_1.chieu = 1; 
		FEE_RTOS_struct.Tay_1.toc_do = toc_do; 
		FEE_RTOS_struct.TrangThai.chieu_xoay_1 = 1; 
	}
	
	if(tay_number ==2) {
		FEE_RTOS_struct.Tay_2.chieu = 1; 
		FEE_RTOS_struct.Tay_2.toc_do = toc_do; 
		FEE_RTOS_struct.TrangThai.chieu_xoay_2 = 1; 
	}
	
}

void xoay_trai(uint8_t tay_number, uint16_t toc_do) {
	if(tay_number ==1) {
		FEE_RTOS_struct.Tay_1.chieu = 0; 
		FEE_RTOS_struct.Tay_1.toc_do = toc_do; 
		FEE_RTOS_struct.TrangThai.chieu_xoay_1 =0; 
	}
	
	if(tay_number ==2) {
		FEE_RTOS_struct.Tay_2.chieu = 0; 
		FEE_RTOS_struct.Tay_2.toc_do = toc_do;
		FEE_RTOS_struct.TrangThai.chieu_xoay_2 = 0; 		
	}
	
}

void nang_canh_tay(uint16_t toc_do) {
		FEE_RTOS_struct.Nang_ha	.chieu = 1; 
		FEE_RTOS_struct.Nang_ha.toc_do = toc_do; 
}


void ha_canh_tay(uint16_t toc_do) {
		FEE_RTOS_struct.Nang_ha	.chieu = 0; 
		FEE_RTOS_struct.Nang_ha.toc_do = toc_do; 
}

void kep(uint8_t chan_le) {
	
	if(chan_le == 1) {
		control_xilanh(1, 1); 
		control_xilanh(3, 1); 
		control_xilanh(5, 1); 
		control_xilanh(7, 1); 
	}
	if(chan_le == 2) {
		control_xilanh(2, 1); 
		control_xilanh(4, 1); 
		control_xilanh(6, 1); 
		control_xilanh(8, 1); 
	}
}

void nha(uint8_t chan_le) {
		if(chan_le == 2) {
		control_xilanh(2, 0); 
		control_xilanh(4, 0); 
		control_xilanh(6, 0); 
		control_xilanh(8, 0); 
	}
		
	if(chan_le == 1) {
		control_xilanh(1, 0); 
		control_xilanh(3, 0); 
		control_xilanh(5, 0); 
		control_xilanh(7, 0); 
	}

}


void start_dc_keo_sung(void) {
	
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1); 
}

void stop_dc_keo_sung(void) {
	
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0); 
}
void kep_bong(void) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0); 
}

void nha_bong(void) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 1); 
}

void nang_tay_kep_bong(void) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0); 
}

void ha_tay_kep_bong(void) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1); 
}
void day_tay_gap_lua(void) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1); 
}

void thu_tay_gap_lua(void) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); 
}
