/*******************************    INCLUDES   ********************************/

#include "FEE_Robot.h"
//#include "usbd_customhid.h"


/*******************************    DEFINITONS   ******************************/

//#define PI 3.141592654
//extern USBD_HandleTypeDef 			        *pdev1;
//extern USBD_CUSTOM_HID_HandleTypeDef        *hhid1;
/***************************    GLOBAL VARIABLES   ****************************/
uint8_t rx_data; 
uint8_t tx_data; 


void dong_co_init(void) {
	
	FEE_RTOS_struct.Tay_1.chieu = 0; 
	FEE_RTOS_struct.Tay_1.toc_do = 0; 
	
	FEE_RTOS_struct.Tay_2.chieu = 0; 
	FEE_RTOS_struct.Tay_2.toc_do = 0; 	
	
	FEE_RTOS_struct.Nang_ha.chieu = 0; 
	FEE_RTOS_struct.Nang_ha.toc_do = 0; 		
	
}


void tu_dong_init(void) {
	
	FEE_RTOS_struct.TuDong.tu_dong_number = 45; 		// so dep <3 
	
	FEE_RTOS_struct.TuDong.stop_nang_ha = 0; 
	FEE_RTOS_struct.TuDong.vi_tri_nang_ha = 0; 
	FEE_RTOS_struct.TuDong.khoi_tao_an_toan = 4; 
	FEE_RTOS_struct.TuDong.tha_lua = 38; 																									// tha lua vao kho 
	FEE_RTOS_struct.TuDong.gap_lua_len = 28; 																						// vi tri tren mlo lua 
	FEE_RTOS_struct.TuDong.di_tha_lua_an_toan = 10; 																// tranh lua keo le 
	FEE_RTOS_struct.TuDong.nang_start_di_tha_lua = 10; 
	FEE_RTOS_struct.TuDong.vi_tri_check_tha_lua = 8; 																	// vi tri ngam vao diem tha lua 	
	FEE_RTOS_struct.TuDong.tranh_cam_bien = 34; 																			// tranh cham sw, cam bien 
	FEE_RTOS_struct.TuDong.kep_lua_tren_ro = 22; 
	FEE_RTOS_struct.TuDong.nang_lua_khoi_ro = 38; 
	FEE_RTOS_struct.TuDong.tranh_va_lua = 39; 
	
	for(int i = 0 ; i < 20; i++) {
		FEE_RTOS_struct.TuDong.day_keo_xilanh_an_toan[i] = 0; 
		
		FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[i] = 0; 
		FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[i] = 0; 
		FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[i] = 0; 
		
		FEE_RTOS_struct.TuDong.nang_ha_tha_lua[i] = 0; 
		
	}
	
	
	
	
}

void lai_tay_init(void) {
	
	for(int i = 1; i < 9; i++) {
		FEE_RTOS_struct.LaiTay.flag_xilanh[i] = 0; 
		FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[i] = 0; 
	}
	FEE_RTOS_struct.LaiTay.flag_tay_1_xoay_trai = 0; 
	FEE_RTOS_struct.LaiTay.flag_tay_2_xoay_trai = 0; 
	FEE_RTOS_struct.LaiTay.flag_tay_1_xoay_phai = 0; 
	FEE_RTOS_struct.LaiTay.flag_tay_2_xoay_phai = 0; 
	FEE_RTOS_struct.LaiTay.flag_nang = 0; 
	FEE_RTOS_struct.LaiTay.flag_ha = 0;
	FEE_RTOS_struct.LaiTay.check_start_nang_ha = 0;
	FEE_RTOS_struct.LaiTay.check_start_tay_1 = 0;
	FEE_RTOS_struct.LaiTay.check_start_tay_2 = 0;
	
}

void trang_thai_init(void) {
	
	FEE_RTOS_struct.TrangThai.mode_run = 0; 
	FEE_RTOS_struct.TrangThai.len_xuong = 0; 
	FEE_RTOS_struct.TrangThai.mode_lai_tay = 0; 
	
	for(int i = 0; i < 20; i++)
		FEE_RTOS_struct.TrangThai.done[i] = 0; 
	
	FEE_RTOS_struct.TrangThai.home = 0; 
	FEE_RTOS_struct.TrangThai.khoi_tao_tu_dong = 0; 
	FEE_RTOS_struct.TrangThai.check_sw_mode = 0; 
	FEE_RTOS_struct.TrangThai.check_sw_mode_lai_tay = 0; 
	FEE_RTOS_struct.TrangThai.vi_tri_kep_lua = 0;
	
	FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_hien_tai = 100;
	FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_hien_tai = 100;
	
	FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_mong_muon = 100; 
	FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_mong_muon = 100;
	
	FEE_RTOS_struct.TrangThai.chieu_xoay_1 = 0; 
	FEE_RTOS_struct.TrangThai.chieu_xoay_2 = 0; 
	
	for(int i = 0; i < 20; i++) 
		FEE_RTOS_struct.TrangThai.comple_reciver[i] = 0; 

	for(int i = 1; i < 9; i++)
		FEE_RTOS_struct.TrangThai.vi_tri_tay_xilanh[i] = i; 
	
	FEE_RTOS_struct.TrangThai.chong_troi_tay_1 = 0; 
	FEE_RTOS_struct.TrangThai.chong_troi_tay_2 = 0; 
	
	FEE_RTOS_struct.TrangThai.count_delay_chong_troi_1 = 0; 
	FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_1 = 0; 
	
	FEE_RTOS_struct.TrangThai.count_delay_chong_troi_2 = 0; 
	FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_2 = 0; 

	
	FEE_RTOS_struct.TrangThai.khoi_dong_mem_tay_1 = 0; 
	FEE_RTOS_struct.TrangThai.khoi_dong_mem_tay_2 = 0; 
	
	FEE_RTOS_struct.TrangThai.da_chong_troi = 0; 
	
	
	FEE_RTOS_struct.TrangThai.so_lan_trans = 20; 								// so lan truyen di 
	FEE_RTOS_struct.TrangThai.so_lan_trans = 0; 										// 0 data cu  
	
	FEE_RTOS_struct.TrangThai.goc_xoay_chong_troi_tay_1 = 0; 
	FEE_RTOS_struct.TrangThai.goc_xoay_chong_troi_tay_2 = 0; 
	
}


void initTimers(void) {
	configTIM1(); 
	configTIM2(); 
	configTIM3(); 
	configTIM4(); 
}


void configTIM1(void) {
// config TIM1
// enable clock TIM1
	
	RCC->APB2ENR |= 1<<11;	 
	TIM1->ARR = 65535-1; 
	TIM1->PSC = 14400-1; 
	TIM1->EGR |= 1; 
	TIM1->CR1 |= 1; 
	
}

void configTIM2(void) {
	
	RCC->APB1ENR |= 1<<0;	 
	TIM2->ARR = 65535-1; 
	TIM2->PSC = 14400-1; 
	TIM2->EGR |= 1; 
	TIM2->CR1 |= 1; 
	
}




void configTIM3(void) {
// config TIM3
// enable clock TIM3
	
	RCC->APB1ENR |= 1<<1;	 
	TIM3->ARR = 65535-1; 
	TIM3->PSC = 14400-1; 
	TIM3->EGR |= 1; 
	TIM3->CR1 |= 1; 
	
}

void configTIM4(void) {
// config TIM4
// enable clock TIM4
	
	RCC->APB1ENR |= 1<<2;	 
	TIM4->ARR = 2000-1; 
	TIM4->PSC = 72-1; 
	TIM4->EGR |= 1; 
	TIM4->CR1 |= 1; 
	
}
