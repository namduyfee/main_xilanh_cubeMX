/*******************************    INCLUDES   ********************************/

#include "FEE_RTOS.h"
//#include "main.h"
/***************************    GLOBAL VARIABLES   ****************************/

struct FEE_RTOS_struct_def		    FEE_RTOS_struct;
uint8_t khoi_tao = 0; 


/***************************       FUNCTIONS       ****************************/


#define thoi_gian_delay_chong_nhieu_luoc 1000 
#define thoi_gian_delay_chong_nhieu_cong_tac 5000 
#define thoi_gian_delay_chong_nhieu_canh_tay 5000 

#define thoi_gian_tha_troi_tay_1 8000
#define thoi_gian_tha_troi_tay_2 10000

#define thoi_gian_chac_chan_dem_nang_ha 0.047
#define thoi_gian_chac_chan_dem_tay 0.29
#define thoi_gian_chac_chan_dem_tay_lan_2 0.47

extern uint8_t td11_1; 
extern uint8_t mode_tem; 
extern uint8_t tx_data;  
extern uint8_t rx_data; 
extern uint8_t cam_bien_chu_u_td5; 
extern uint8_t flag_ha_canh_tay_tha_lua; 

uint8_t dem_tay_1 = 0; 					// so lan trong number ay la dc dem 
uint8_t dem_tay_2 = 0; 					

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPIO_PIN_3) {
		
		
		if(FEE_RTOS_struct.TrangThai.home == 0 && 1 == FEE_RTOS_struct.TrangThai.mode_run) {
			
			if(0 == check_nang_ha(thoi_gian_chac_chan_dem_nang_ha)) {
				delayUs(thoi_gian_delay_chong_nhieu_luoc); 
				EXTI->PR = 1<<3;
			}			
			
			if(0 == FEE_RTOS_struct.TrangThai.len_xuong) 
				FEE_RTOS_struct.TuDong.vi_tri_nang_ha--; 
			else 
				FEE_RTOS_struct.TuDong.vi_tri_nang_ha++; 			
			
			reset_nang_ha(); 
			
			if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha < 2 && FEE_RTOS_struct.Nang_ha.toc_do > 80) 
				FEE_RTOS_struct.Nang_ha.toc_do =  80; 
			else if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha < 4 && FEE_RTOS_struct.Nang_ha.toc_do > 90) 
				FEE_RTOS_struct.Nang_ha.toc_do =  90; 
			else if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha < 6 && FEE_RTOS_struct.Nang_ha.toc_do > 135) 
				FEE_RTOS_struct.Nang_ha.toc_do =  135; 
			else if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha < 8 && FEE_RTOS_struct.Nang_ha.toc_do > 180) 
				FEE_RTOS_struct.Nang_ha.toc_do =  180; 
			else if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha < 10 && FEE_RTOS_struct.Nang_ha.toc_do > 230) 
				FEE_RTOS_struct.Nang_ha.toc_do =  230;  
			else if(FEE_RTOS_struct.TuDong.vi_tri_nang_ha < 60 && FEE_RTOS_struct.Nang_ha.toc_do >= 250) 
				FEE_RTOS_struct.Nang_ha.toc_do =  250;  
			
		}
		
		else if(FEE_RTOS_struct.TrangThai.home) {
			
			if(0 == check_nang_ha(thoi_gian_chac_chan_dem_nang_ha)) {
				delayUs(thoi_gian_delay_chong_nhieu_luoc); 
				EXTI->PR = 1<<3;
			}
			
			if(0 == FEE_RTOS_struct.TrangThai.len_xuong) 
				FEE_RTOS_struct.TuDong.vi_tri_nang_ha--; 
			else 
				FEE_RTOS_struct.TuDong.vi_tri_nang_ha++; 
			
			reset_nang_ha(); 
			
			if(2 == FEE_RTOS_struct.TrangThai.mode_run) {
				if(FEE_RTOS_struct.TuDong.khoi_tao_an_toan == FEE_RTOS_struct.TuDong.vi_tri_nang_ha) {
					khoa_dc_tay(3);
					khoi_tao_kep_lua(); 
					khoi_tao = 1; 
				}
			}
			
			else if(1 == FEE_RTOS_struct.TrangThai.mode_run) {
				
				if((1 == FEE_RTOS_struct.TuDong.tu_dong_number) && (FEE_RTOS_struct.TuDong.vi_tri_nang_ha >= (FEE_RTOS_struct.TuDong.gap_lua_len + 8) && 0 == FEE_RTOS_struct.TuDong.day_keo_xilanh_an_toan[0]) 
					&& (FEE_RTOS_struct.TrangThai.len_xuong == 1)) {
						FEE_RTOS_struct.TuDong.day_keo_xilanh_an_toan[0] = 1; 
				}
					
				if( (1 == FEE_RTOS_struct.TuDong.tu_dong_number) && (FEE_RTOS_struct.TuDong.vi_tri_nang_ha >= (FEE_RTOS_struct.TuDong.tranh_cam_bien - 2)) && FEE_RTOS_struct.TuDong.day_keo_xilanh_an_toan[0] == 1
					&& (FEE_RTOS_struct.TrangThai.len_xuong == 1)) {
					thu_tay_gap_lua(); 
				}			
					
				if( (4 == FEE_RTOS_struct.TuDong.tu_dong_number) && (FEE_RTOS_struct.TuDong.vi_tri_nang_ha >= (FEE_RTOS_struct.TuDong.tranh_cam_bien - 4)) && FEE_RTOS_struct.TuDong.day_keo_xilanh_an_toan[4] == 1
					&& (FEE_RTOS_struct.TrangThai.len_xuong == 1)) {
					FEE_RTOS_struct.TuDong.day_keo_xilanh_an_toan[4] = 2; 
				}
					
				
				if( (4 == FEE_RTOS_struct.TuDong.tu_dong_number) && (FEE_RTOS_struct.TuDong.vi_tri_nang_ha >= (FEE_RTOS_struct.TuDong.gap_lua_len + 8)) && FEE_RTOS_struct.TuDong.day_keo_xilanh_an_toan[4] == 0
					&& (FEE_RTOS_struct.TrangThai.len_xuong == 1)) {
					FEE_RTOS_struct.TuDong.day_keo_xilanh_an_toan[4] = 1; 
				}
				
			
				if(FEE_RTOS_struct.TuDong.stop_nang_ha == FEE_RTOS_struct.TuDong.vi_tri_nang_ha) {  
				
					khoa_dc_tay(3);


					
					if(1 == FEE_RTOS_struct.TuDong.tu_dong_number)
						FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[1] = 1; 
					
					else if(4 == FEE_RTOS_struct.TuDong.tu_dong_number) {
						FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[4] = 1; 
					}
					
					else if(6 == FEE_RTOS_struct.TuDong.tu_dong_number) 
						FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[6] = 1;		

					/********************************************* THA LUA *******************************************************/ 
					
					else if(7 == FEE_RTOS_struct.TuDong.tu_dong_number && FEE_RTOS_struct.TuDong.nang_ha_tha_lua[7] == 4) 
							FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[7] = 1;		
				
					else if(8 == FEE_RTOS_struct.TuDong.tu_dong_number && FEE_RTOS_struct.TuDong.nang_ha_tha_lua[8] == 4)
							FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[8] = 1;		
					
					else if(9 == FEE_RTOS_struct.TuDong.tu_dong_number && 4 == FEE_RTOS_struct.TuDong.nang_ha_tha_lua[9]) 
							FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[9] = 1;							
					
					else if(11 == FEE_RTOS_struct.TuDong.tu_dong_number && 1 == FEE_RTOS_struct.TrangThai.done[11] && td11_1 == 1 )
						FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[11] = 1;				
					
					else if(11 == FEE_RTOS_struct.TuDong.tu_dong_number && 2 == FEE_RTOS_struct.TrangThai.done[11])
						FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[11] = 2;		
					
					else if(11 == FEE_RTOS_struct.TuDong.tu_dong_number && 3 == FEE_RTOS_struct.TrangThai.done[11]) 
						FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[11] = 3;		
					
					else if(11 == FEE_RTOS_struct.TuDong.tu_dong_number && 4 == FEE_RTOS_struct.TrangThai.done[11]) 
						FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[11] = 4;							
					
				else if(11 == FEE_RTOS_struct.TuDong.tu_dong_number && 5 == FEE_RTOS_struct.TrangThai.done[11])
					FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[11] = 5; 					
					
					else if(12 == FEE_RTOS_struct.TuDong.tu_dong_number && FEE_RTOS_struct.TuDong.nang_ha_tha_lua[12] == 4)
						FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[12] = 4; 
							
					
				}
			}
		}
		delayUs(thoi_gian_delay_chong_nhieu_luoc); 
		EXTI->PR = 1<<3;
	
	}	

/******************************************************* TAY 2 *****************************************/

  if(GPIO_Pin == GPIO_PIN_4) {
		
//==================== TU DONG =======================// 
		if(1 == FEE_RTOS_struct.TrangThai.mode_run) {
			
			// dang chong troi 
			if(1 == FEE_RTOS_struct.TrangThai.chong_troi_tay_2) {
				  
				FEE_RTOS_struct.TrangThai.chong_troi_tay_2 = 2; 
				FEE_RTOS_struct.TrangThai.count_delay_chong_troi_2 = FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_2 - 1; 
				khoa_dc_tay(2); 
				pid_dc2(FEE_RTOS_struct.Tay_2.chieu, 1);
				delayUs(thoi_gian_delay_chong_nhieu_canh_tay); 
				EXTI->PR = 1<<4;				
				return; 
			}
			
			// dang chay ham chinh 
			else if(0 == FEE_RTOS_struct.TrangThai.chong_troi_tay_2) {
				
				if(1 == dem_tay_2 && FEE_RTOS_struct.TrangThai.goc_xoay_chong_troi_tay_2 == 180) {
					if(0 == check_xoay_tay_2(thoi_gian_chac_chan_dem_tay_lan_2)) {
						delayUs(thoi_gian_delay_chong_nhieu_canh_tay); 
						EXTI->PR = 1<<4;						
						return; 
					}
				}
				else {
					if(0 == check_xoay_tay_2(thoi_gian_chac_chan_dem_tay)) {
					delayUs(thoi_gian_delay_chong_nhieu_canh_tay); 
					EXTI->PR = 1<<4;	
					return; 
					}
				}
				
				if(dem_tay_2 != 0) {
					tinh_vi_tri_tay_xoay(2); 
					dem_tay_2--; 
					if(1 == dem_tay_2 && 2 == FEE_RTOS_struct.TuDong.tu_dong_number) {
//						reset_check_xoay_tay_2();       khong nen 
					}						
				}				
				
				if(FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_hien_tai != FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_mong_muon) {
					delayUs(thoi_gian_delay_chong_nhieu_canh_tay);
					EXTI->PR = 1<<4;
					return; 
				}
				
				// thoi gian  vua chong nhieu vua tha troi canh tay 
				delayUs(thoi_gian_tha_troi_tay_2); 
				
				khoa_dc_tay(2); 
				
				pid_dc2(FEE_RTOS_struct.Tay_2.chieu, 1);
				
				if(1 == FEE_RTOS_struct.TuDong.tu_dong_number && 2 == FEE_RTOS_struct.TrangThai.done[1])
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[1] = 1; 
				else if (2 == FEE_RTOS_struct.TuDong.tu_dong_number && 0 != FEE_RTOS_struct.TrangThai.done[2]) 
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[2] = 1; 
				
				else if(4 == FEE_RTOS_struct.TuDong.tu_dong_number && FEE_RTOS_struct.TrangThai.done[4] == 2) 
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[4] = 1; 
				
				else if(7 == FEE_RTOS_struct.TuDong.tu_dong_number && 2 == FEE_RTOS_struct.TrangThai.done[7])
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[7] = 1; 	
				else if(8 == FEE_RTOS_struct.TuDong.tu_dong_number && 2 == FEE_RTOS_struct.TrangThai.done[8])
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[8] = 1;					
				
				else if(9 == FEE_RTOS_struct.TuDong.tu_dong_number && 2 == FEE_RTOS_struct.TrangThai.done[9])
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[9] = 1; 					
				
				else if(11 == FEE_RTOS_struct.TuDong.tu_dong_number && 3 == FEE_RTOS_struct.TrangThai.done[11]) 
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[11] = 1; 			
				
				else if(12 == FEE_RTOS_struct.TuDong.tu_dong_number && FEE_RTOS_struct.TrangThai.done[12] == 2)
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[12] = 1; 				
				
				if(FEE_RTOS_struct.TuDong.mau_san == 'X') {
					
					if(11 == FEE_RTOS_struct.TuDong.tu_dong_number && 5 == FEE_RTOS_struct.TrangThai.done[11]) 
						FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[11] = 2; 								
				}				

				EXTI->PR = 1<<4;
				return; 
			}		
				delayUs(thoi_gian_delay_chong_nhieu_canh_tay); 
				EXTI->PR = 1<<4;
				return;
		}
		
// ================ KHOI TAO ========== ===================== //
		else if(2 == FEE_RTOS_struct.TrangThai.mode_run) {
			pid_dc2(FEE_RTOS_struct.Tay_2.chieu, 1);
			khoa_dc_tay(2); 
			delayUs(thoi_gian_delay_chong_nhieu_canh_tay); 
			EXTI->PR = 1<<4;
			return; 
		}
		
// ================== LAI TAY ============================= //  
		
		else if(0 == FEE_RTOS_struct.TrangThai.mode_run) {
			if(0 == FEE_RTOS_struct.TrangThai.mode_lai_tay) {
				delayUs(thoi_gian_delay_chong_nhieu_canh_tay); 
				EXTI->PR = 1<<4;
			}
			else if(1 == FEE_RTOS_struct.TrangThai.mode_lai_tay) {

				pid_dc2(FEE_RTOS_struct.Tay_2.chieu, 1);
				khoa_dc_tay(2); 
				if(1 == FEE_RTOS_struct.LaiTay.flag_tay_2_xoay_trai)
					FEE_RTOS_struct.LaiTay.flag_tay_2_xoay_trai = 0; 
				if(1 == FEE_RTOS_struct.LaiTay.flag_tay_2_xoay_phai)
					FEE_RTOS_struct.LaiTay.flag_tay_2_xoay_phai = 0; 
				delayUs(thoi_gian_delay_chong_nhieu_canh_tay); 
				EXTI->PR = 1<<4;
			}
			return; 
		}	
		
		else {
			delayUs(thoi_gian_delay_chong_nhieu_canh_tay);
			EXTI->PR = 1<<4;
			return; 
		}		
	}
	
	
	
/******************************************** TAY 1 ******************************************************/
	
	
	
	if(GPIO_Pin == GPIO_PIN_5) {
		
// ==================== TU DONG ========================= //  
		if(1 == FEE_RTOS_struct.TrangThai.mode_run) {
		
			// dang chong troi 
			if(1 == FEE_RTOS_struct.TrangThai.chong_troi_tay_1) {
				
				FEE_RTOS_struct.TrangThai.chong_troi_tay_1 = 2; 
				khoa_dc_tay(1); 
				pid_dc1(FEE_RTOS_struct.Tay_1.chieu, 1);
				delayUs(thoi_gian_delay_chong_nhieu_canh_tay); 
				EXTI->PR = 1<<5;				
				return;
			}
			
			// dang chay ham chinh 
			else if(0 == FEE_RTOS_struct.TrangThai.chong_troi_tay_1) {
				
				if(1 == dem_tay_1 && FEE_RTOS_struct.TrangThai.goc_xoay_chong_troi_tay_1 == 180) {
					if(0 == check_xoay_tay_1(thoi_gian_chac_chan_dem_tay_lan_2)) {
						delayUs(thoi_gian_delay_chong_nhieu_canh_tay); 
						EXTI->PR = 1<<5;	
						return; 						
					}
				}
				else {
					if(0 == check_xoay_tay_1(thoi_gian_chac_chan_dem_tay)) {
						delayUs(thoi_gian_delay_chong_nhieu_canh_tay); 
						EXTI->PR = 1<<5;				
						return; 
					}
				}		
				if(dem_tay_1 != 0) {
					tinh_vi_tri_tay_xoay(1); 
					dem_tay_1--; 
					if(1 == dem_tay_1 && 2 == FEE_RTOS_struct.TuDong.tu_dong_number) {
//						reset_check_xoay_tay_1();       khong nen 
					}
				}				
				
				if(FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_hien_tai != FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_mong_muon) {
					delayUs(thoi_gian_delay_chong_nhieu_canh_tay);
					EXTI->PR = 1<<5;
					return; 
				}
				
				// thoi gian vua chong nhieu vua tha troi canh tay 
				delayUs(thoi_gian_tha_troi_tay_1); 
				khoa_dc_tay(1); 
				pid_dc1(FEE_RTOS_struct.Tay_1.chieu, 1);
				
				if(1 == FEE_RTOS_struct.TuDong.tu_dong_number && 2 == FEE_RTOS_struct.TrangThai.done[1])
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[1] = 1; 
				else if (2 == FEE_RTOS_struct.TuDong.tu_dong_number && 0 != FEE_RTOS_struct.TrangThai.done[2]) 
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[2] = 1; 
				
				else if(4 == FEE_RTOS_struct.TuDong.tu_dong_number && FEE_RTOS_struct.TrangThai.done[4] == 2) 
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[4] = 1; 
				
				else if(7 == FEE_RTOS_struct.TuDong.tu_dong_number && 2 == FEE_RTOS_struct.TrangThai.done[7])
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[7] = 1; 					
				else if(8 == FEE_RTOS_struct.TuDong.tu_dong_number && 2 == FEE_RTOS_struct.TrangThai.done[8])
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[8] = 1; 						
				else if(9 == FEE_RTOS_struct.TuDong.tu_dong_number && 2 == FEE_RTOS_struct.TrangThai.done[9])
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[9] = 1;
				
				else if(11 == FEE_RTOS_struct.TuDong.tu_dong_number && 3 == FEE_RTOS_struct.TrangThai.done[11]) 
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[11] = 1; 
				
				else if(12 == FEE_RTOS_struct.TuDong.tu_dong_number && FEE_RTOS_struct.TrangThai.done[12] == 2)
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[12] = 1; 
				
				if(FEE_RTOS_struct.TuDong.mau_san == 'D') {
					if(11 == FEE_RTOS_struct.TuDong.tu_dong_number && 5 == FEE_RTOS_struct.TrangThai.done[11]) 
						FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[11] = 2; 								
				}
				
				EXTI->PR = 1<<5;
				return; 
			}		
				delayUs(thoi_gian_delay_chong_nhieu_canh_tay); 
				EXTI->PR = 1<<5;
				return; 
		}
		
		
// ================= KHOI TAO ===========================// 				
		else if(FEE_RTOS_struct.TrangThai.mode_run == 2) {
			pid_dc1(FEE_RTOS_struct.Tay_1.chieu, 1);
			khoa_dc_tay(1); 
			delayUs(thoi_gian_delay_chong_nhieu_canh_tay); 
			EXTI->PR = 1<<5;
			return; 
		}
		
// ================= LAI TAY ===========================// 		
		else if(0 == FEE_RTOS_struct.TrangThai.mode_run) {
			if(0 == FEE_RTOS_struct.TrangThai.mode_lai_tay) {
				delayUs(thoi_gian_delay_chong_nhieu_canh_tay); 
				EXTI->PR = 1<<5;
			}
			else if(1 == FEE_RTOS_struct.TrangThai.mode_lai_tay) {
				khoa_dc_tay(1); 
				if(1 == FEE_RTOS_struct.LaiTay.flag_tay_1_xoay_trai)
					FEE_RTOS_struct.LaiTay.flag_tay_1_xoay_trai = 0; 
				if(1 == FEE_RTOS_struct.LaiTay.flag_tay_1_xoay_phai)
					FEE_RTOS_struct.LaiTay.flag_tay_1_xoay_phai = 0; 
				
				delayUs(thoi_gian_delay_chong_nhieu_canh_tay); 
				EXTI->PR = 1<<5;
			}
			return; 
		}		
		else {
			delayUs(thoi_gian_delay_chong_nhieu_canh_tay); 
			EXTI->PR = 1<<5;
			return; 
		}
	}

/********************************************** CONG TAC HANH TRINH ************************************/

	if(GPIO_Pin == GPIO_PIN_15) {
		
		FEE_RTOS_struct.TuDong.vi_tri_nang_ha = 0; 
		if( 0 == FEE_RTOS_struct.TrangThai.home)
			FEE_RTOS_struct.TrangThai.home = 1; 
		
		pid_dc3(FEE_RTOS_struct.Nang_ha.chieu, 1); 
		khoa_dc_tay(3);
		
		if(2 == FEE_RTOS_struct.TrangThai.mode_run && khoi_tao == 0) {
			if(0 == FEE_RTOS_struct.TrangThai.vi_tri_kep_lua) {
				khoi_tao_an_toan(); 
				FEE_RTOS_struct.TrangThai.vi_tri_kep_lua = 1; 
			}
		}
		
		else if(2 == FEE_RTOS_struct.TrangThai.mode_run && khoi_tao == 1) {
				FEE_RTOS_struct.TrangThai.mode_run = mode_tem; 		
				khoi_tao = 0; 			
		}
		
		else if(1 == FEE_RTOS_struct.TrangThai.mode_run) {
			
			 if(((3 == FEE_RTOS_struct.TuDong.tu_dong_number) || (4 == FEE_RTOS_struct.TuDong.tu_dong_number)) && (0 == FEE_RTOS_struct.TrangThai.len_xuong)) {
					if(0 == FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[3]) 
						FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[3] = 1; 
				}
				else if(5 == FEE_RTOS_struct.TuDong.tu_dong_number && FEE_RTOS_struct.TrangThai.done[5] == 2) 
					FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[5] = 1;		
				
				/********************************************** Tha Lua *********************************************/ 
				
				else if(7 == FEE_RTOS_struct.TuDong.tu_dong_number && 1 == FEE_RTOS_struct.TuDong.nang_ha_tha_lua[7]) 
					FEE_RTOS_struct.TuDong.nang_ha_tha_lua[7] = 2; 
				
				else if(8 == FEE_RTOS_struct.TuDong.tu_dong_number && 1 == FEE_RTOS_struct.TuDong.nang_ha_tha_lua[8]) 
					FEE_RTOS_struct.TuDong.nang_ha_tha_lua[8] = 2; 				
				
				else if(9 == FEE_RTOS_struct.TuDong.tu_dong_number && 1 == FEE_RTOS_struct.TuDong.nang_ha_tha_lua[9]) 
					FEE_RTOS_struct.TuDong.nang_ha_tha_lua[9] = 2; 				
				
				else if(10 == FEE_RTOS_struct.TuDong.tu_dong_number && 1 == FEE_RTOS_struct.TuDong.nang_ha_tha_lua[10]) 
					FEE_RTOS_struct.TuDong.nang_ha_tha_lua[10] = 2; 				
				
					else if(12 == FEE_RTOS_struct.TuDong.tu_dong_number && 1 == FEE_RTOS_struct.TuDong.nang_ha_tha_lua[12])
						FEE_RTOS_struct.TuDong.nang_ha_tha_lua[12] = 2; 						

				else if(13 == FEE_RTOS_struct.TuDong.tu_dong_number && 1 == FEE_RTOS_struct.TuDong.nang_ha_tha_lua[13]) 
					FEE_RTOS_struct.TuDong.nang_ha_tha_lua[13] = 2; 				
				
		}
		
		delayUs(thoi_gian_delay_chong_nhieu_cong_tac); 
		EXTI->PR = 1<<15;		
	
	}

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{	
	
	if(huart->Instance == USART1)
	{	
			pes_uart_event_handle(); 
	}		
	
	if(huart->Instance == USART3)
	{	
		if(1 == FEE_RTOS_struct.TrangThai.mode_run ) {
			
			if(rx_data == 'a') { 
				if(0 == FEE_RTOS_struct.TrangThai.comple_reciver[1]) {
					FEE_RTOS_struct.TrangThai.comple_reciver[1] = 1; 
					FEE_RTOS_struct.TuDong.tu_dong_number = 1; 
					FEE_RTOS_struct.TrangThai.done[1] = 0;
				}
			}
			
			
			if(rx_data == 'b') {
				if(0 == FEE_RTOS_struct.TrangThai.comple_reciver[4]) {
					FEE_RTOS_struct.TrangThai.comple_reciver[4] = 1; 
					FEE_RTOS_struct.TuDong.tu_dong_number = 4; 
					FEE_RTOS_struct.TrangThai.done[4] = 0;
				}
			}
	
		
			if(rx_data == 'c') {
				if(0 == FEE_RTOS_struct.TrangThai.comple_reciver[5]) {
					FEE_RTOS_struct.TrangThai.comple_reciver[5] = 1; 
					FEE_RTOS_struct.TuDong.tu_dong_number = 5; 
					FEE_RTOS_struct.TrangThai.done[5] = 0;
				}
			}
			
			if(rx_data == '1') {
				if(0 == FEE_RTOS_struct.TrangThai.comple_reciver[7]) {
					FEE_RTOS_struct.TrangThai.comple_reciver[7] = 1; 
					FEE_RTOS_struct.TuDong.tu_dong_number = 7; 
					FEE_RTOS_struct.TrangThai.done[7] = 0;
				}
			}
			
			if(rx_data == 'd') {
				if(1 == FEE_RTOS_struct.TrangThai.comple_reciver[7]) {
					FEE_RTOS_struct.TrangThai.comple_reciver[7] = 2; 
				}
			}
						
			
			if(rx_data == '2') {
				if(0 == FEE_RTOS_struct.TrangThai.comple_reciver[8]) {
					FEE_RTOS_struct.TrangThai.comple_reciver[8] = 1; 
					FEE_RTOS_struct.TuDong.tu_dong_number = 8; 
					FEE_RTOS_struct.TrangThai.done[8] = 0;
				}
			}
			
			if(rx_data == 'e') {
				if(1 == FEE_RTOS_struct.TrangThai.comple_reciver[8]) {
					FEE_RTOS_struct.TrangThai.comple_reciver[8] = 2; 
				}
			}			
			
			if(rx_data == '3') {
				if(0 == FEE_RTOS_struct.TrangThai.comple_reciver[9]) {
					FEE_RTOS_struct.TrangThai.comple_reciver[9] = 1; 
					FEE_RTOS_struct.TuDong.tu_dong_number = 9; 
					FEE_RTOS_struct.TrangThai.done[9] = 0;
				}
			}
			
			if(rx_data == 'f') {
				if(1 == FEE_RTOS_struct.TrangThai.comple_reciver[9]) {
					FEE_RTOS_struct.TrangThai.comple_reciver[9] = 2; 
				}
			}					

			if(rx_data == '4') {
				if(0 == FEE_RTOS_struct.TrangThai.comple_reciver[10]) {
					FEE_RTOS_struct.TrangThai.comple_reciver[10] = 1; 
					FEE_RTOS_struct.TuDong.tu_dong_number = 10; 
					FEE_RTOS_struct.TrangThai.done[10] = 0;
				}
			}	

			if(rx_data == 'g') {
				if(1 == FEE_RTOS_struct.TrangThai.comple_reciver[10]) {
					FEE_RTOS_struct.TrangThai.comple_reciver[10] = 2; 
				}
			}

			if(rx_data == '5') {
				if(0 == FEE_RTOS_struct.TrangThai.comple_reciver[12]) {
					FEE_RTOS_struct.TrangThai.comple_reciver[12] = 1; 
					FEE_RTOS_struct.TuDong.tu_dong_number = 12; 
					FEE_RTOS_struct.TrangThai.done[12] = 0;
				}
			}	
			
			if(rx_data == 'h') {
				if(1 == FEE_RTOS_struct.TrangThai.comple_reciver[12]) {
					FEE_RTOS_struct.TrangThai.comple_reciver[12] = 2; 
				}
			}	
			
			if(rx_data == '6') {
				if(0 == FEE_RTOS_struct.TrangThai.comple_reciver[13]) {
					FEE_RTOS_struct.TrangThai.comple_reciver[13] = 1; 
					FEE_RTOS_struct.TuDong.tu_dong_number = 13; 
					FEE_RTOS_struct.TrangThai.done[13] = 0;
				}
			}	
			
//			if(rx_data == 'M')
//				flag_ha_canh_tay_tha_lua = 1; 
			
			
		}
		HAL_UART_Receive_IT(&huart3, &rx_data, 1); 
	}
}


void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{	

}

void FEE_Data_Innit(void)
{
	FEE_RTOS_struct.UART_Update 		= 0;
	FEE_RTOS_struct.UART_Loss 			= 0;

	FEE_RTOS_struct.Process_Mode		= 0;
	FEE_RTOS_struct.Process_done		= 0;
	FEE_RTOS_struct.Request_Save_Flash	= 0;
	FEE_RTOS_struct.Request_Read_Flash	= 0;

	FEE_RTOS_struct.Pulse 				= 0;
	FEE_RTOS_struct.Buff_Duty 			= 0;
	
}



//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
//{		

//}

void FEE_RTOS_Innit(void)
{	
  FEE_UART_Innit();
	FEE_Data_Innit();
	FEE_GPIO_Innit();
HAL_UART_Receive_IT(&huart1, FEE_RTOS_struct.H_UART1.rxBuffer, 1);

}
	

