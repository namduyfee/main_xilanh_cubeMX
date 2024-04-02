

#include "FEE_Tu_Dong.h"

#define ngoai_cam_bien 1
#define trong_cam_bien 0

#define thoi_gian_xilanh_day 900
#define thoi_gian_kep_mo_xilanh 600
#define thoi_gian_an_toan_xoay 700


#define toc_do_nang_ha 250

#define toc_do_xoay_tay_1_tha_lua_lan_2 250
#define toc_do_xoay_tay_2_tha_lua_lan_2 250

#define toc_do_xoay_tay_1_gap_2_lua_cuoi 250
#define toc_do_xoay_tay_2_gap_2_lua_cuoi 250

#define toc_do_xoay_tha_lua 250

// ====================  lay lua ======================== /

/********* toc do ******************/
#define toc_do_tra_ve_lan_1_tay_1_lay_lua 25
#define toc_do_tra_ve_lan_1_tay_2_lay_lua 25

#define toc_do_tra_ve_lan_2_tay_1_lay_lua 35
#define toc_do_tra_ve_lan_2_tay_2_lay_lua 35

/*********** thoi gian ************/
#define thoi_gian_tra_ve_lay_lua_tay_1 50
#define thoi_gian_tra_ve_lay_lua_tay_2 50

// =================== tha lua ========================= / 

/********* toc do ******************/
#define toc_do_tra_ve_lan_1_tay_1_tha_lua 36
#define toc_do_tra_ve_lan_1_tay_2_tha_lua 36

#define toc_do_tra_ve_lan_2_tay_1_tha_lua 25
#define toc_do_tra_ve_lan_2_tay_2_tha_lua 25
/*********** thoi gian ************/
#define thoi_gian_tra_ve_tha_lua_tay_1 50
#define thoi_gian_tra_ve_tha_lua_tay_2 50


extern uint8_t dem_tay_1; 
extern uint8_t dem_tay_2; 
extern uint8_t tem_tx_data; 
extern uint8_t tx_data; 


void tu_dong_1(void) {
	
	day_tay_gap_lua(); 
	
	osDelay(thoi_gian_xilanh_day); // time day xilanh ra v
	
	kep(1); 
	
	osDelay(thoi_gian_kep_mo_xilanh); // time kep 
	nang_ha_tay_gap_tu_dong(FEE_RTOS_struct.TuDong.tha_lua, toc_do_nang_ha); 
	
}


void tu_dong_2(void) {
	
	// thoi gian chac chan xilanh da keo vao 
	osDelay(150); 												// on dinh tay      
	
	control_xilanh(3, 0); 
	control_xilanh(5, 0); 
	
	osDelay(thoi_gian_an_toan_xoay); 
	
	reset_chong_troi();

	khoi_dong_mem(1, 180); 
	khoi_dong_mem(2, 180); 
	
	xoay_180(1, 0, toc_do_xoay_tay_1_tha_lua_lan_2); 
	osDelay(5);
	xoay_180(2, 1, toc_do_xoay_tay_2_tha_lua_lan_2); 
	
}

void tu_dong_3(void) {
	
	osDelay(180); 												// on dinh tay 
	control_xilanh(1, 0); 
	control_xilanh(7, 0); 
	osDelay(thoi_gian_kep_mo_xilanh); 		// time xilanh nha 
	den_vi_tri_kep_lua(toc_do_nang_ha); 
	
}

void tu_dong_4(void) { 
	
	osDelay(10);			// time day xilanh an toan 
	kep(2); 
	osDelay(thoi_gian_kep_mo_xilanh); 			// time kep xilanh 
	
	nang_ha_tay_gap_tu_dong(FEE_RTOS_struct.TuDong.tranh_va_lua, toc_do_nang_ha); 
	
}

void tu_dong_4_2(void) {
	
	reset_chong_troi(); 
	
	khoi_dong_mem(1, 90); 
	khoi_dong_mem(2, 90); 
	
	xoay_90(1, 0, toc_do_xoay_tay_1_gap_2_lua_cuoi); 
	osDelay(5);
	
	xoay_90(2, 1, toc_do_xoay_tay_2_gap_2_lua_cuoi); 
	
}

//void tu_dong_5(void) {

//}

void tu_dong_6(void) {
	osDelay(200); 
	kep(1); 
	osDelay(thoi_gian_kep_mo_xilanh); 
	nang_ha_tay_gap_tu_dong(FEE_RTOS_struct.TuDong.gap_lua_len, toc_do_nang_ha); 
	osDelay(700); 

}

void tu_dong_xoay_tha_90(void) {
	
	reset_chong_troi(); 
	
	khoi_dong_mem(1, 90); 
	khoi_dong_mem(2, 90); 
	 
	xoay_90(1, 1, toc_do_xoay_tha_lua); 
	osDelay(5);
	xoay_90(2, 0, toc_do_xoay_tha_lua); 
}


void tu_dong_11_1(void) {
	
	nang_ha_tay_gap_tu_dong(FEE_RTOS_struct.TuDong.kep_lua_tren_ro, toc_do_nang_ha); 
}

void tu_dong_11_2(void) {

	nang_ha_tay_gap_tu_dong(FEE_RTOS_struct.TuDong.nang_lua_khoi_ro, toc_do_nang_ha); 

}

// chieu_xoay == 0 : xoay trai 
// chieu xoay == 1 : xoay phai 
void xoay_180(uint8_t tay_number, uint8_t chieu_xoay, uint16_t toc_do) {
	
	if(1 == tay_number) {
		
		dem_tay_1 = 2;
		reset_check_xoay_tay_1();
		
		if(chieu_xoay == 0) {
			FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_mong_muon = FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_hien_tai + 2; 
			xoay_trai(1, toc_do_xoay_tha_lua);
		}
		else {
			FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_mong_muon = FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_hien_tai - 2; 
			xoay_phai(1, toc_do_xoay_tha_lua);			
		}
	}
	else if(2 == tay_number) {
		
		dem_tay_2 = 2;
		reset_check_xoay_tay_2();
		
		if(chieu_xoay == 0) {
			FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_mong_muon = FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_hien_tai + 2; 
			xoay_trai(2, toc_do_xoay_tha_lua);
		}
		else {
			FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_mong_muon = FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_hien_tai - 2; 
			xoay_phai(2, toc_do_xoay_tha_lua);			
		}
	}
}


// chieu_xoay == 0 : xoay trai 
// chieu xoay == 1 : xoay phai 
void xoay_90(uint8_t tay_number, uint8_t chieu_xoay, uint16_t toc_do) {
	if(1 == tay_number) {
		dem_tay_1 = 1;
		reset_check_xoay_tay_1();
		
		if(chieu_xoay == 0) {
			FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_mong_muon = FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_hien_tai + 1; 
			xoay_trai(1, toc_do);
		}
		else {
			FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_mong_muon = FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_hien_tai - 1; 
			xoay_phai(1, toc_do);			
		}
	}
	else if(2 == tay_number) {
		
		dem_tay_2 = 1;
		reset_check_xoay_tay_2();
		
		if(chieu_xoay == 0) {
			FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_mong_muon = FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_hien_tai + 1; 
			xoay_trai(2, toc_do);
		}
		else {
			FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_mong_muon = FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_hien_tai - 1; 
			xoay_phai(2, toc_do);			
		}
	}
}
// sau khi tha 2 lua dau 

void den_vi_tri_kep_lua(uint16_t toc_do) {
	if(GPIOA->IDR & 1<<15) {
		reset_nang_ha(); 
		FEE_RTOS_struct.TrangThai.home = 0; 
		FEE_RTOS_struct.TrangThai.len_xuong = 0; 
		ha_canh_tay(toc_do);
		
	}
	else 
		ha_canh_tay(0);
}

void nang_ha_tay_gap_tu_dong(uint8_t vi_tri_can_den, uint16_t toc_do) {
	
	FEE_RTOS_struct.TuDong.stop_nang_ha = vi_tri_can_den; 
	
	reset_nang_ha(); 

	if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha < vi_tri_can_den) {
		FEE_RTOS_struct.TrangThai.len_xuong = 1;
		nang_canh_tay(toc_do);
	}
	else if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha > vi_tri_can_den) {
		FEE_RTOS_struct.TrangThai.len_xuong = 0; 
		ha_canh_tay(toc_do);
	}			
}

void tinh_vi_tri_tay_xoay(uint8_t tay_number) {
	
	if(1 == tay_number) {
		if(0 == FEE_RTOS_struct.TrangThai.chieu_xoay_1) 
			FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_hien_tai++; 
		else 
			FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_hien_tai--; 
	}
	else if(2 == tay_number) {
		if(0 == FEE_RTOS_struct.TrangThai.chieu_xoay_2) 
			FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_hien_tai++; 
		else 
			FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_hien_tai--; 		
	}
}


void chong_troi_tay_1(uint8_t trang_thai) {
	int16_t t1;
	uint16_t v1_1,v1_2; 
	
	if(0 == trang_thai) {
		
		t1 = thoi_gian_tra_ve_lay_lua_tay_1; 
		v1_1 = toc_do_tra_ve_lan_1_tay_1_lay_lua; 
		v1_2 = toc_do_tra_ve_lan_2_tay_1_lay_lua; 
	}	
	else if(1 == trang_thai) {
		
		t1 = thoi_gian_tra_ve_tha_lua_tay_1; 
		v1_1 = toc_do_tra_ve_lan_1_tay_1_tha_lua; 
		v1_2 = toc_do_tra_ve_lan_2_tay_1_tha_lua; 
	}		
	
	if(ngoai_cam_bien == HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5)) {
		FEE_RTOS_struct.TrangThai.chong_troi_tay_1 = 1; 
		FEE_RTOS_struct.TrangThai.count_delay_chong_troi_1 = 0; 
		FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_1 = t1; 		
		xoay_chong_troi(1, v1_1); 
	}
	
	while(FEE_RTOS_struct.TrangThai.count_delay_chong_troi_1 < FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_1)
	{
		osDelay(10); 
		FEE_RTOS_struct.TrangThai.count_delay_chong_troi_1++; 
	}	
	
	if(1 == FEE_RTOS_struct.TrangThai.chong_troi_tay_1) {
		
		reset_khoi_dong_mem(1);
		if(0 == FEE_RTOS_struct.TrangThai.chieu_xoay_1) 
			xoay_phai(1, v1_2);
		else 
			xoay_trai(1, v1_2);		
		
	}	
	
}


void chong_troi_tay_2(uint8_t trang_thai) {
	int16_t t2;
	uint16_t v2_1,v2_2; 
	
	if(0 == trang_thai) {
		
		t2 = thoi_gian_tra_ve_lay_lua_tay_2; 
		v2_1 = toc_do_tra_ve_lan_1_tay_2_lay_lua; 
		v2_2 = toc_do_tra_ve_lan_2_tay_2_lay_lua; 
	}	
	else if(1 == trang_thai) {
		
		t2 = thoi_gian_tra_ve_tha_lua_tay_2; 
		v2_1 = toc_do_tra_ve_lan_1_tay_2_tha_lua; 
		v2_2 = toc_do_tra_ve_lan_2_tay_2_tha_lua; 
	}		
	
	if(ngoai_cam_bien == HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4)) {
//		reset_khoi_dong_mem(); 
		FEE_RTOS_struct.TrangThai.chong_troi_tay_2 = 1; 
		FEE_RTOS_struct.TrangThai.count_delay_chong_troi_2 = 0; 
		FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_2 = t2; 
		xoay_chong_troi(2, v2_1); 
	}
	
	while(FEE_RTOS_struct.TrangThai.count_delay_chong_troi_2 < FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_2)
	{
		osDelay(10); 
		FEE_RTOS_struct.TrangThai.count_delay_chong_troi_2++; 
	}	
	
	if(1 == FEE_RTOS_struct.TrangThai.chong_troi_tay_2) {
		reset_khoi_dong_mem(2);
		if(0 == FEE_RTOS_struct.TrangThai.chieu_xoay_2) 
			xoay_phai(2, v2_2);
		else 
			xoay_trai(2, v2_2);		
		
	}	
	
}


void chong_troi(uint8_t trang_thai) {
	
	// trang thai = 0 : lay lua 
	// trang thai = 1 : tha lua 
	
	
		uint16_t t1, t2; 
		uint16_t v1_1, v2_1, v1_2, v2_2; 
	
	if(0 == trang_thai) {
		
		t1 = thoi_gian_tra_ve_lay_lua_tay_1; 
		t2 = thoi_gian_tra_ve_lay_lua_tay_2; 
		
		v1_1 = toc_do_tra_ve_lan_1_tay_1_lay_lua; 
		v2_1 = toc_do_tra_ve_lan_1_tay_2_lay_lua; 
		
		v1_2 = toc_do_tra_ve_lan_2_tay_1_lay_lua; 
		v2_2 = toc_do_tra_ve_lan_2_tay_2_lay_lua; 
	}
	
	else if(1 == trang_thai) {
		
		t1 = thoi_gian_tra_ve_tha_lua_tay_1; 
		t2 = thoi_gian_tra_ve_tha_lua_tay_2; 
		
		v1_1 = toc_do_tra_ve_lan_1_tay_1_tha_lua; 
		v2_1 = toc_do_tra_ve_lan_1_tay_2_tha_lua; 
		
		v1_2 = toc_do_tra_ve_lan_2_tay_1_tha_lua; 
		v2_2 = toc_do_tra_ve_lan_2_tay_2_tha_lua; 
	}	
	
	
	if(ngoai_cam_bien == HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4)) {
//		reset_khoi_dong_mem(); 
		FEE_RTOS_struct.TrangThai.chong_troi_tay_2 = 1; 
		FEE_RTOS_struct.TrangThai.count_delay_chong_troi_2 = 0; 
		FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_2 = t2; 
		xoay_chong_troi(2, v2_1); 
	}
	
	if(ngoai_cam_bien == HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5)) {
//		reset_khoi_dong_mem(); 
		FEE_RTOS_struct.TrangThai.chong_troi_tay_1 = 1; 
		FEE_RTOS_struct.TrangThai.count_delay_chong_troi_1 = 0; 
		FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_1 = t1; 		
		xoay_chong_troi(1, v1_1); 
	}
	
	if(5 == FEE_RTOS_struct.TuDong.tu_dong_number) {
		tx_data = 'M'; 
		so_lan_trans(20); 
	}
	
	while((FEE_RTOS_struct.TrangThai.count_delay_chong_troi_2 < FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_2) || 
					(FEE_RTOS_struct.TrangThai.count_delay_chong_troi_1 < FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_1)) 
	{
		osDelay(10); 
		FEE_RTOS_struct.TrangThai.count_delay_chong_troi_1++; 
		FEE_RTOS_struct.TrangThai.count_delay_chong_troi_2++; 
		if(5 == FEE_RTOS_struct.TuDong.tu_dong_number) {
			tx_data = 'M'; 
			so_lan_trans(20); 
		}
	}
	
	if(1 == FEE_RTOS_struct.TrangThai.chong_troi_tay_1) {
		reset_khoi_dong_mem(1);
		if(0 == FEE_RTOS_struct.TrangThai.chieu_xoay_1) 
			xoay_phai(1, v1_2);
		else 
			xoay_trai(1, v1_2);		
		
	}
	
	if(1 == FEE_RTOS_struct.TrangThai.chong_troi_tay_2) {
		reset_khoi_dong_mem(2);
		if(0 == FEE_RTOS_struct.TrangThai.chieu_xoay_2) 
			xoay_phai(2, v2_2);
		else 
			xoay_trai(2, v2_2);	
	}
	
	while(1 == FEE_RTOS_struct.TrangThai.chong_troi_tay_1 || 1 == FEE_RTOS_struct.TrangThai.chong_troi_tay_2); 
	
}


void xoay_chong_troi(uint8_t tay_number, uint16_t toc_do) {
	
	if(1 == tay_number) {
		if(0 == FEE_RTOS_struct.TrangThai.chieu_xoay_1) 
			xoay_phai(1, toc_do_tra_ve_lan_1_tay_1_lay_lua);
		else 
			xoay_trai(1, toc_do_tra_ve_lan_1_tay_1_lay_lua);
	}		
	else if(2 == tay_number) {
		if(0 == FEE_RTOS_struct.TrangThai.chieu_xoay_2) 
			xoay_phai(2, toc_do_tra_ve_lan_1_tay_2_lay_lua);
		else 
			xoay_trai(2, toc_do_tra_ve_lan_1_tay_2_lay_lua);		
	}
}

void reset_chong_troi(void) {
	
	FEE_RTOS_struct.TrangThai.da_chong_troi = 0; 
	
	FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_1 = 0; 
	FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_2 = 0;
	FEE_RTOS_struct.TrangThai.count_delay_chong_troi_1 = 0; 
	FEE_RTOS_struct.TrangThai.count_delay_chong_troi_2 = 0; 
	
	FEE_RTOS_struct.TrangThai.chong_troi_tay_1  = 0; 
	FEE_RTOS_struct.TrangThai.chong_troi_tay_2  = 0; 
	
}

void reset_chong_troi_1(void) {
	
	FEE_RTOS_struct.TrangThai.da_chong_troi = 0; 
	FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_1 = 0; 
	FEE_RTOS_struct.TrangThai.count_delay_chong_troi_1 = 0; 
	FEE_RTOS_struct.TrangThai.chong_troi_tay_1  = 0; 
	
}

void reset_chong_troi_2(void) {
	
	FEE_RTOS_struct.TrangThai.da_chong_troi = 0; 
	FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_2 = 0; 
	FEE_RTOS_struct.TrangThai.count_delay_chong_troi_2 = 0; 
	FEE_RTOS_struct.TrangThai.chong_troi_tay_2  = 0; 	
}


void reset_khoi_dong_mem(uint8_t tay_number) {
	
	if(1 == tay_number) {
		FEE_RTOS_struct.TrangThai.khoi_dong_mem_tay_1 = 0; 
		FEE_RTOS_struct.TrangThai.goc_xoay_chong_troi_tay_1 = 0; 
	}
	else if(2 == tay_number) {
		FEE_RTOS_struct.TrangThai.khoi_dong_mem_tay_2 = 0; 
		FEE_RTOS_struct.TrangThai.goc_xoay_chong_troi_tay_2 = 0; 
	}
	
}

void khoi_dong_mem(uint8_t tay_number, int goc_xoay_khoi_dong_mem) {
	
	if(1 == tay_number) {
		FEE_RTOS_struct.TrangThai.khoi_dong_mem_tay_1 = 1; 
		FEE_RTOS_struct.TrangThai.goc_xoay_chong_troi_tay_1 =  goc_xoay_khoi_dong_mem; 
	}
	else if(2 == tay_number) {
		FEE_RTOS_struct.TrangThai.khoi_dong_mem_tay_2 = 1; 
		FEE_RTOS_struct.TrangThai.goc_xoay_chong_troi_tay_2 =  goc_xoay_khoi_dong_mem; 
	}
}


void so_lan_trans(uint8_t so_lan_trans) {
	
	if(tem_tx_data != tx_data) 
		FEE_RTOS_struct.TrangThai.so_lan_trans = so_lan_trans; 
	tem_tx_data = tx_data; 
	
	if(FEE_RTOS_struct.TrangThai.so_lan_trans > 1) {
		HAL_UART_Transmit(&huart3, &tx_data, 1, 20); 		
		FEE_RTOS_struct.TrangThai.so_lan_trans--; 
	}	
}
