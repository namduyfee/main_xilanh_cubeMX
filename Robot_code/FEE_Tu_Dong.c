

#include "FEE_Tu_Dong.h"

#define thoi_gian_tranh_lua_cham_robot_4_lua_cuoi 400
#define thoi_gian_tranh_lua_cham_sw_cb_4_lua_cuoi 200
#define thoi_gian_xilanh_day 700
#define thoi_gian_kep_mo_xilanh 600
#define toc_do_nang_ha 180
#define toc_do_nang_ha_luc_dau 170

#define toc_do_xoay_tay_1_tha_lua_lan_2 80
#define toc_do_xoay_tay_2_tha_lua_lan_2 80

#define toc_do_xoay_tay_1_gap_2_lua_cuoi 90
#define toc_do_xoay_tay_2_gap_2_lua_cuoi 90

#define toc_do_xoay_di_tha_lua 60

#define toc_do_tra_ve_lan_1 20
#define toc_do_tra_ve_lan_2 30

extern uint8_t da_chong_troi; 
extern uint8_t dem_tay_1; 
extern uint8_t dem_tay_2; 

void tu_dong_1(void) {
	
	osDelay(thoi_gian_xilanh_day); // time day xilanh ra 
//	kep_le(); 
	kep(1); 
	
	osDelay(thoi_gian_kep_mo_xilanh); // time kep 
	
	FEE_RTOS_struct.TuDong.stop_nang_ha = FEE_RTOS_struct.TuDong.tha_lua;
	
	if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha < FEE_RTOS_struct.TuDong.tha_lua) {
		FEE_RTOS_struct.TrangThai.len_xuong = 1;
		nang_canh_tay(toc_do_nang_ha_luc_dau);
	}
	else if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha > FEE_RTOS_struct.TuDong.tha_lua) {
		FEE_RTOS_struct.TrangThai.len_xuong = 0; 
		ha_canh_tay(toc_do_nang_ha_luc_dau);
	}
}

void tu_dong_2(void) {
	
	osDelay(500); 												// on dinh tay 
	
	control_xilanh(7, 0); 
	control_xilanh(1, 0); 
	osDelay(thoi_gian_kep_mo_xilanh); 
	
	da_chong_troi = 0; 
	reset_chong_troi(); 
	
	dem_tay_1 = 2;
	reset_check_xoay_tay_1();
//	FEE_RTOS_struct.TrangThai.luu_count_suon_len_1 = FEE_RTOS_struct.TrangThai.count_suon_len_1 + 1; 
	FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_mong_muon = FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_hien_tai + 2; 
	xoay_trai(1, toc_do_xoay_tay_1_tha_lua_lan_2); 
	
	osDelay(5);
	
	dem_tay_2 = 2;
	reset_check_xoay_tay_2();
//	FEE_RTOS_struct.TrangThai.luu_count_suon_len_2= FEE_RTOS_struct.TrangThai.count_suon_len_2 + 1; 
	FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_mong_muon = FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_hien_tai - 2; 
	xoay_phai(2, toc_do_xoay_tay_2_tha_lua_lan_2);
	
	
}

void tu_dong_3(void) {
	
	osDelay(400); 												// on dinh tay 
	
	control_xilanh(5, 0); 
	control_xilanh(3, 0); 
	
	osDelay(thoi_gian_kep_mo_xilanh); 		// time xilanh nha 
	
	FEE_RTOS_struct.TuDong.stop_nang_ha = FEE_RTOS_struct.TuDong.kep_lua;
	
	if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha < FEE_RTOS_struct.TuDong.kep_lua) {
		FEE_RTOS_struct.TrangThai.len_xuong = 1;
		nang_canh_tay(toc_do_nang_ha);
	}
	else if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha > FEE_RTOS_struct.TuDong.kep_lua) {
		FEE_RTOS_struct.TrangThai.len_xuong = 0; 
		ha_canh_tay(toc_do_nang_ha);
	}
	
}

void tu_dong_4(void) {
	
	osDelay(300);			// time day xilanh an toan 
// 	kep_chan(); 
	kep(2); 
	osDelay(thoi_gian_kep_mo_xilanh); 			// time kep xilanh 
	
	FEE_RTOS_struct.TuDong.stop_nang_ha = FEE_RTOS_struct.TuDong.tranh_cam_bien; 
	
	if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha < FEE_RTOS_struct.TuDong.tranh_cam_bien) {
		FEE_RTOS_struct.TrangThai.len_xuong = 1;
		nang_canh_tay(toc_do_nang_ha);
	}
	else if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha > FEE_RTOS_struct.TuDong.tranh_cam_bien) {
		FEE_RTOS_struct.TrangThai.len_xuong = 0; 
		ha_canh_tay(toc_do_nang_ha);
	}
}

void tu_dong_5(void) {
	
//	osDelay(thoi_gian_tranh_lua_cham_robot_4_lua_cuoi); 				// day xilanh ra tranh viec quay va mac lua vao robot 
	
	da_chong_troi = 0; 
	reset_chong_troi(); 
	
	dem_tay_1 = 1;
	reset_check_xoay_tay_1();
	FEE_RTOS_struct.TrangThai.luu_count_suon_len_1 = FEE_RTOS_struct.TrangThai.count_suon_len_1; 
	FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_mong_muon = FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_hien_tai + 1; 
	xoay_trai(1, toc_do_xoay_tay_1_gap_2_lua_cuoi);
	
	osDelay(5);

	dem_tay_2 = 1;
	reset_check_xoay_tay_2();
	FEE_RTOS_struct.TrangThai.luu_count_suon_len_2 = FEE_RTOS_struct.TrangThai.count_suon_len_2; 
	FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_mong_muon = FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_hien_tai  - 1; 
	xoay_phai(2, toc_do_xoay_tay_2_gap_2_lua_cuoi); 
	
	osDelay(thoi_gian_tranh_lua_cham_sw_cb_4_lua_cuoi); 					//thoi gian tranh lua dap vao bac de lua
	
	FEE_RTOS_struct.TuDong.stop_nang_ha = FEE_RTOS_struct.TuDong.kep_lua;
	
	if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha < FEE_RTOS_struct.TuDong.kep_lua) {
		FEE_RTOS_struct.TrangThai.len_xuong = 1;
		nang_canh_tay(toc_do_nang_ha);
	}
	else if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha > FEE_RTOS_struct.TuDong.kep_lua) {
		FEE_RTOS_struct.TrangThai.len_xuong = 0; 
		ha_canh_tay(toc_do_nang_ha);
	}

}

void tu_dong_6(void) {
	
	kep(1); 
//	kep_le(); 
	
	osDelay(thoi_gian_kep_mo_xilanh); 
	
	FEE_RTOS_struct.TuDong.stop_nang_ha = FEE_RTOS_struct.TuDong.gap_lua_len; 
	
	if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha < FEE_RTOS_struct.TuDong.gap_lua_len) {
		FEE_RTOS_struct.TrangThai.len_xuong = 1;
		nang_canh_tay(toc_do_nang_ha);
	}
	else if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha > FEE_RTOS_struct.TuDong.gap_lua_len) {
		FEE_RTOS_struct.TrangThai.len_xuong = 0; 
		ha_canh_tay(toc_do_nang_ha);
	}
	
	osDelay(700); 

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

void chong_troi(void) {
	
	if(0 == HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4)) {
		FEE_RTOS_struct.TrangThai.chong_troi_tay_2 = 1; 
		FEE_RTOS_struct.TrangThai.count_delay_chong_troi_2 = 0; 
		FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_2 = 35; 
		xoay_chong_troi(2, toc_do_tra_ve_lan_1); 
	}
	
	if(0 == HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5)) {
		FEE_RTOS_struct.TrangThai.chong_troi_tay_1 = 1; 
		FEE_RTOS_struct.TrangThai.count_delay_chong_troi_1 = 0; 
		FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_1 = 35; 		
		xoay_chong_troi(1, toc_do_tra_ve_lan_1); 
	}
	
	while((FEE_RTOS_struct.TrangThai.count_delay_chong_troi_2 < FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_2) || 
					(FEE_RTOS_struct.TrangThai.count_delay_chong_troi_1 < FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_1)) 
	{
		osDelay(10); 
		FEE_RTOS_struct.TrangThai.count_delay_chong_troi_1++; 
		FEE_RTOS_struct.TrangThai.count_delay_chong_troi_2++; 
	}
	
	if(1 == FEE_RTOS_struct.TrangThai.chong_troi_tay_1) 
		xoay_chong_troi(1, toc_do_tra_ve_lan_2);
	if(1 == FEE_RTOS_struct.TrangThai.chong_troi_tay_2)
		xoay_chong_troi(2, toc_do_tra_ve_lan_2);
	
	while(1 == FEE_RTOS_struct.TrangThai.chong_troi_tay_1 || 1 == FEE_RTOS_struct.TrangThai.chong_troi_tay_2); 
	
}


void xoay_chong_troi(uint8_t tay_number, uint16_t toc_do) {
	// tay 1 
	if(1 == tay_number) {
		if((FEE_RTOS_struct.TrangThai.luu_count_suon_len_1  + 1) <  FEE_RTOS_struct.TrangThai.count_suon_len_1) {
			if(0 == FEE_RTOS_struct.TrangThai.chieu_xoay_1) 
				xoay_trai(1, toc_do); 
			else 
			xoay_phai(1, toc_do); 			
		}
		else {
			if(0 == FEE_RTOS_struct.TrangThai.chieu_xoay_1) 
				xoay_phai(1, toc_do); 
			else 
				xoay_trai(1, toc_do); 
		}
	}

		// tay 2 
	else if(2 == tay_number) {
		if((FEE_RTOS_struct.TrangThai.luu_count_suon_len_2  + 1) <  FEE_RTOS_struct.TrangThai.count_suon_len_2) {
			if(0 == FEE_RTOS_struct.TrangThai.chieu_xoay_2) 
				xoay_trai(2, toc_do); 
			else 
			xoay_phai(2, toc_do); 			
		}
		else if((FEE_RTOS_struct.TrangThai.luu_count_suon_len_2  + 1) == FEE_RTOS_struct.TrangThai.count_suon_len_2) {
			if(0 == FEE_RTOS_struct.TrangThai.chieu_xoay_2) 
				xoay_phai(2, toc_do); 
			else 
				xoay_trai(2, toc_do); 
		}
	}
}

void reset_chong_troi(void) {
	
	FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_1 = 0; 
	FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_2 = 0;
	FEE_RTOS_struct.TrangThai.count_delay_chong_troi_1 = 0; 
	FEE_RTOS_struct.TrangThai.count_delay_chong_troi_2 = 0; 
	FEE_RTOS_struct.TrangThai.chong_troi_tay_1  = 0; 
	FEE_RTOS_struct.TrangThai.chong_troi_tay_2  = 0; 
}





