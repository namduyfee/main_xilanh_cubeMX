
#include "FEE_Lai_Tay.h"

#define toc_do_lai_tay_1 40
#define toc_do_lai_tay_2 40
#define toc_do_lai_tay_nang_ha 70

void nut_lai_tay(void) {
	
// nang
	if(0 == FEE_PES_Btn.S21 && 0 == FEE_PES_Btn.S20 ) {
		FEE_RTOS_struct.LaiTay.flag_nang = 1; 
		FEE_RTOS_struct.TrangThai.len_xuong = 1; 
	}
	else
		FEE_RTOS_struct.LaiTay.flag_nang = 0;
// ha 	
	if(0 == FEE_PES_Btn.S21 && 0 == FEE_PES_Btn.S19)  {
		FEE_RTOS_struct.LaiTay.flag_ha = 1;
		FEE_RTOS_struct.TrangThai.len_xuong = 0; 
	}			
	else 
		FEE_RTOS_struct.LaiTay.flag_ha = 0;
// xoay trai tay 1 		
	if(0 == FEE_PES_Btn.S18 && 0 == FEE_PES_Btn.S17) 
		FEE_RTOS_struct.LaiTay.flag_tay_1_xoay_trai = 1; 
	else {
		if(0 == FEE_RTOS_struct.TrangThai.mode_lai_tay)
			FEE_RTOS_struct.LaiTay.flag_tay_1_xoay_trai = 0; 
	}
		
// xoay phai tay 1 	
	if(0 == FEE_PES_Btn.S18 && 0 == FEE_PES_Btn.S24)
		FEE_RTOS_struct.LaiTay.flag_tay_1_xoay_phai = 1; 
	else {
		if(0 == FEE_RTOS_struct.TrangThai.mode_lai_tay)
			FEE_RTOS_struct.LaiTay.flag_tay_1_xoay_phai = 0; 
	}
// xoay trai tay 2 	
	if(0 == FEE_PES_Btn.S23 && 0 == FEE_PES_Btn.S17)
		FEE_RTOS_struct.LaiTay.flag_tay_2_xoay_trai = 1; 
	else {
		if(0 == FEE_RTOS_struct.TrangThai.mode_lai_tay)
			FEE_RTOS_struct.LaiTay.flag_tay_2_xoay_trai = 0; 
	}
// xoay phai tay 2 	
	if(0 == FEE_PES_Btn.S23 && 0 == FEE_PES_Btn.S24)
		FEE_RTOS_struct.LaiTay.flag_tay_2_xoay_phai = 1; 
	else {
		if(0 == FEE_RTOS_struct.TrangThai.mode_lai_tay)
			FEE_RTOS_struct.LaiTay.flag_tay_2_xoay_phai = 0; 
	}
// xilanh 1
	if(0 == FEE_PES.R1 && 0 == FEE_PES_Btn.S22) {
		if(0 == FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[1]) {
			FEE_RTOS_struct.LaiTay.flag_xilanh[1] ^=  1; 
			FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[1] =  1; 
		}		
	}
	else 
		FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[1] = 0; 
// xilanh 2 
	
	if(0 == FEE_PES.R1 && 0 == FEE_PES_Btn.S21) {
		if(0 == FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[2]) {
			FEE_RTOS_struct.LaiTay.flag_xilanh[2] ^=  1; 
			FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[2] =  1; 
		}		
	}
	else 
		FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[2] = 0; 

// xilanh 3

	if(0 == FEE_PES.R1 && 0 == FEE_PES_Btn.S23) {
		if(0 == FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[3]) {
			FEE_RTOS_struct.LaiTay.flag_xilanh[3] ^=  1; 
			FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[3] =  1; 
		}		
	}
	else 
		FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[3] = 0; 	
	
// xilanh 4 
	
	if(0 == FEE_PES.R1 && 0 == FEE_PES_Btn.S20) {
		if(0 == FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[4]) {
			FEE_RTOS_struct.LaiTay.flag_xilanh[4] ^=  1; 
			FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[4] =  1; 
		}		
	}
	else 
		FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[4] = 0; 	
	
// xilanh 5 
		if(0 == FEE_PES.R1 && 0 == FEE_PES_Btn.S18) {
		if(0 == FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[5]) {
			FEE_RTOS_struct.LaiTay.flag_xilanh[5] ^=  1; 
			FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[5] =  1; 
		}		
	}
	else 
		FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[5] = 0; 	

// xilanh 6 
	if(0 == FEE_PES.R1 && 0 == FEE_PES_Btn.S24) {
		if(0 == FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[6]) {
			FEE_RTOS_struct.LaiTay.flag_xilanh[6] ^=  1; 
			FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[6] =  1; 
		}		
	}
	else 
		FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[6] = 0; 	
// xilanh 7
	if(0 == FEE_PES.R1 && 0 == FEE_PES_Btn.S19) {
		if(0 == FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[7]) {
			FEE_RTOS_struct.LaiTay.flag_xilanh[7] ^=  1; 
			FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[7] =  1; 
		}		
	}
	else 
		FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[7] = 0; 		
	
// xilanh 8
	if(0 == FEE_PES.R1 && 0 == FEE_PES_Btn.S17) {
		if(0 == FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[8]) {
			FEE_RTOS_struct.LaiTay.flag_xilanh[8] ^=  1; 
			FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[8] =  1; 
		}		
	}
	else 
		FEE_RTOS_struct.LaiTay.chong_nhieu_xilanh[8] = 0; 	
	
	// chuyen mode 
	
}

void ham_lai_tay(void) {
	// nang_ha 			
	if(FEE_RTOS_struct.LaiTay.flag_nang == 1) {
		nang_canh_tay(toc_do_lai_tay_nang_ha);
		FEE_RTOS_struct.LaiTay.check_start_nang_ha = 1; 
	}

	else if(FEE_RTOS_struct.LaiTay.flag_ha == 1) {
		if(GPIOA->IDR & 1<<15)  {
			ha_canh_tay(toc_do_lai_tay_nang_ha);
			FEE_RTOS_struct.LaiTay.check_start_nang_ha = 1; 
		}
		else {
			if(FEE_RTOS_struct.LaiTay.check_start_nang_ha == 0)
				ha_canh_tay(0); 
			else 
				khoa_dc_tay(3); 
		}
			
	}
	else {
		if(FEE_RTOS_struct.LaiTay.check_start_tay_1 == 0)
			ha_canh_tay(0);
		else 
			khoa_dc_tay(3); 
	}
			

	// cau 1 			
	if(FEE_RTOS_struct.LaiTay.flag_tay_1_xoay_trai == 1) {
		xoay_trai(1, toc_do_lai_tay_1); 
		FEE_RTOS_struct.LaiTay.check_start_tay_1 = 1;
	}

	else if(FEE_RTOS_struct.LaiTay.flag_tay_1_xoay_phai == 1) {
		xoay_phai(1, toc_do_lai_tay_1); 
		FEE_RTOS_struct.LaiTay.check_start_tay_1 = 1;
	}
		
	else {
		if(FEE_RTOS_struct.LaiTay.check_start_tay_1 == 0)
			xoay_trai(1, 0); 
		else 
			khoa_dc_tay(1); 
	}
	// cau 2 
	if(FEE_RTOS_struct.LaiTay.flag_tay_2_xoay_trai == 1) {
		xoay_trai(2, toc_do_lai_tay_2); 
		FEE_RTOS_struct.LaiTay.check_start_tay_2 = 1;
	}

	else if(FEE_RTOS_struct.LaiTay.flag_tay_2_xoay_phai == 1) {
		xoay_phai(2, toc_do_lai_tay_2); 
		FEE_RTOS_struct.LaiTay.check_start_tay_2 = 1;
	}
		
	else {
		if(FEE_RTOS_struct.LaiTay.check_start_tay_2 == 0)
			xoay_trai(2, 0); 
		else 
			khoa_dc_tay(2); 
	}

	// xilanh tay kep 			
	for(uint8_t i = 1; i < 9;  i++) {

		if(FEE_RTOS_struct.LaiTay.flag_xilanh[i] == 1) 
			control_xilanh(FEE_RTOS_struct.TrangThai.vi_tri_tay_xilanh[i], 1); 
		else 
			control_xilanh(FEE_RTOS_struct.TrangThai.vi_tri_tay_xilanh[i], 0); 
	}
	
}







