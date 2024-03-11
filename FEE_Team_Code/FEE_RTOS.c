/*******************************    INCLUDES   ********************************/

#include "FEE_RTOS.h"
//#include "main.h"
/***************************    GLOBAL VARIABLES   ****************************/

struct FEE_RTOS_struct_def		    FEE_RTOS_struct;
uint8_t khoi_tao = 0; 
uint8_t tem = 0; 


/***************************       FUNCTIONS       ****************************/


#define thoi_gian_chong_nhieu_luoc 10000 
#define thoi_gian_chong_nhieu_cong_tac 10000
#define thoi_gian_chong_nhieu_canh_tay 1000 
#define thoi_gian_chac_chan_dem_tay 0.25
#define thoi_gian_chac_chan_dem_tay_lan_2 0.20

extern uint8_t mode_tem; 
extern uint8_t tx_data;  
extern uint8_t rx_data; 

uint8_t dem_tay_1 = 0; 					// so lan trong number ay la dc dem 
uint8_t dem_tay_2 = 0; 					

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPIO_PIN_3) {
		if(FEE_RTOS_struct.TrangThai.home) {
			
			if(0 == FEE_RTOS_struct.TrangThai.len_xuong) 
				FEE_RTOS_struct.TuDong.vi_tri_nang_ha--; 
			else 
				FEE_RTOS_struct.TuDong.vi_tri_nang_ha++; 
			
			if(2 == FEE_RTOS_struct.TrangThai.mode_run) {
				if(FEE_RTOS_struct.TuDong.khoi_tao_an_toan == FEE_RTOS_struct.TuDong.vi_tri_nang_ha) {
					khoa_dc_tay(3);
					khoi_tao_kep_lua(); 
					khoi_tao = 1; 
				}
				
				if(FEE_RTOS_struct.TuDong.kep_lua == FEE_RTOS_struct.TuDong.vi_tri_nang_ha && 1 == khoi_tao) {
					khoa_dc_tay(3);
					FEE_RTOS_struct.TrangThai.mode_run = mode_tem; 		
					khoi_tao = 0; 
				}
			}
			
			else if(1 == FEE_RTOS_struct.TrangThai.mode_run) {
				
				if((1 == FEE_RTOS_struct.TuDong.tu_dong_number) && (FEE_RTOS_struct.TuDong.vi_tri_nang_ha >= (FEE_RTOS_struct.TuDong.gap_lua_len)) 
					&& (FEE_RTOS_struct.TrangThai.len_xuong == 1)) {
						FEE_RTOS_struct.TuDong.day_keo_xilanh_an_toan[0] = 1; 
				}
					
				if((1 == FEE_RTOS_struct.TuDong.tu_dong_number) && (FEE_RTOS_struct.TuDong.vi_tri_nang_ha >= (FEE_RTOS_struct.TuDong.tranh_cam_bien - 10)) 
					&& (FEE_RTOS_struct.TrangThai.len_xuong == 1)) {
					FEE_RTOS_struct.TuDong.day_keo_xilanh_an_toan[1] = 1; 
					tx_data = 'a'; 
					HAL_UART_Transmit(&huart3, &tx_data, 1, 10); 
				}
				
				if((4 == FEE_RTOS_struct.TuDong.tu_dong_number) && (FEE_RTOS_struct.TuDong.vi_tri_nang_ha >= (FEE_RTOS_struct.TuDong.tranh_cam_bien - 10))
					&& (FEE_RTOS_struct.TrangThai.len_xuong == 1)) {
					FEE_RTOS_struct.TuDong.day_keo_xilanh_an_toan[4] = 1; 
					tx_data = 'B'; 
					HAL_UART_Transmit(&huart3, &tx_data, 1, 20); 
				}
			
				if(FEE_RTOS_struct.TuDong.stop_nang_ha == FEE_RTOS_struct.TuDong.vi_tri_nang_ha) {
				
					khoa_dc_tay(3);
				
					if(1 == FEE_RTOS_struct.TuDong.tu_dong_number)
						FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[1] = 1; 
					
					else if(((3 == FEE_RTOS_struct.TuDong.tu_dong_number) || (4 == FEE_RTOS_struct.TuDong.tu_dong_number)) && (0 == FEE_RTOS_struct.TrangThai.len_xuong)) {
						if(0 == FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[3]) 
							FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[3] = 1; 
					}
					else if(4 == FEE_RTOS_struct.TuDong.tu_dong_number) {
						FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[4] = 1; 
					}
						
					else if(5 == FEE_RTOS_struct.TuDong.tu_dong_number) 
						FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[5] = 1;
				}
			}
		}
		delayUs(thoi_gian_chong_nhieu_luoc); 
		EXTI->PR = 1<<3;
	
	}	

/******************************************************* TAY 2 *****************************************/

  if(GPIO_Pin == GPIO_PIN_4) {
		
//==================== TU DONG =======================// 
		if(1 == FEE_RTOS_struct.TrangThai.mode_run) {
			
			
			
			FEE_RTOS_struct.TrangThai.count_suon_len_2++; 
			
			// dang chong troi 
			if(1 == FEE_RTOS_struct.TrangThai.chong_troi_tay_2) {
				
				FEE_RTOS_struct.TrangThai.chong_troi_tay_2 = 2; 
				FEE_RTOS_struct.TrangThai.count_delay_chong_troi_2 = FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_2 - 1; 
				khoa_dc_tay(2); 
				delayUs(thoi_gian_chong_nhieu_canh_tay); 
				EXTI->PR = 1<<4;				
				
			}
			
			// dang chay ham chinh 
			else if(0 == FEE_RTOS_struct.TrangThai.chong_troi_tay_2) {
				
				if(1 == dem_tay_2 && 2 == FEE_RTOS_struct.TuDong.tu_dong_number) {
					if(0 == check_xoay_tay_2(thoi_gian_chac_chan_dem_tay_lan_2)) {
						delayUs(thoi_gian_chong_nhieu_canh_tay); 
						tem= 1; 
						EXTI->PR = 1<<4;						
						return; 
					}
				}
				else {
					if(0 == check_xoay_tay_2(thoi_gian_chac_chan_dem_tay)) {
					delayUs(thoi_gian_chong_nhieu_canh_tay); 
					EXTI->PR = 1<<4;	
					return; 
					}
				}
				
				if(dem_tay_2 != 0) {
					tinh_vi_tri_tay_xoay(2); 
					if(1 == dem_tay_2 && 2 == FEE_RTOS_struct.TuDong.tu_dong_number) {
						FEE_RTOS_struct.TrangThai.luu_count_suon_len_2 = FEE_RTOS_struct.TrangThai.count_suon_len_2 -  1; 		
						reset_check_xoay_tay_2(); 
					}						
					dem_tay_2--; 
				}				
				
				if(FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_hien_tai != FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_mong_muon) {
					delayUs(thoi_gian_chong_nhieu_canh_tay);
					EXTI->PR = 1<<4;
					return; 
				}
				khoa_dc_tay(2); 
				if(1 == FEE_RTOS_struct.TuDong.tu_dong_number)
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[1] = 1; 
				else if (2 == FEE_RTOS_struct.TuDong.tu_dong_number) 
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[2] = 1; 
				else if(5 == FEE_RTOS_struct.TuDong.tu_dong_number)
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[5] = 1; 		
				
				delayUs(thoi_gian_chong_nhieu_canh_tay);
				EXTI->PR = 1<<4;
				return; 
			}		
		}
		
// ================ KHOI TAO ========== ===================== //
		else if(2 == FEE_RTOS_struct.TrangThai.mode_run) {
			khoa_dc_tay(2); 
			delayUs(thoi_gian_chong_nhieu_canh_tay); 
			EXTI->PR = 1<<4;
		}
		
// ================== LAI TAY ============================= //  
		
		else if(0 == FEE_RTOS_struct.TrangThai.mode_run) {
			if(0 == FEE_RTOS_struct.TrangThai.mode_lai_tay) {
				delayUs(thoi_gian_chong_nhieu_canh_tay); 
				EXTI->PR = 1<<4;
			}
			else if(1 == FEE_RTOS_struct.TrangThai.mode_lai_tay) {
				khoa_dc_tay(2); 
				if(1 == FEE_RTOS_struct.LaiTay.flag_tay_2_xoay_trai)
					FEE_RTOS_struct.LaiTay.flag_tay_2_xoay_trai = 0; 
				if(1 == FEE_RTOS_struct.LaiTay.flag_tay_2_xoay_phai)
					FEE_RTOS_struct.LaiTay.flag_tay_2_xoay_phai = 0; 
				delayUs(thoi_gian_chong_nhieu_canh_tay); 
				EXTI->PR = 1<<4;
			}
		}	
		
		else {
			EXTI->PR = 1<<4;
		}		
	}
	
	
	
/******************************************** TAY 1 ******************************************************/
	
	
	
	if(GPIO_Pin == GPIO_PIN_5) {
		
// ==================== TU DONG ========================= //  
		if(1 == FEE_RTOS_struct.TrangThai.mode_run) {
			
			FEE_RTOS_struct.TrangThai.count_suon_len_1++; 
			
			// dang chong troi 
			if(1 == FEE_RTOS_struct.TrangThai.chong_troi_tay_1) {
				
				FEE_RTOS_struct.TrangThai.chong_troi_tay_1 = 2; 
				FEE_RTOS_struct.TrangThai.count_delay_chong_troi_1 = FEE_RTOS_struct.TrangThai.limit_delay_chong_troi_1 - 1; 
				khoa_dc_tay(1); 
				delayUs(thoi_gian_chong_nhieu_canh_tay); 
				EXTI->PR = 1<<5;				
				
			}
			
			// dang chay ham chinh 
			else if(0 == FEE_RTOS_struct.TrangThai.chong_troi_tay_1) {
				
				if(1 == dem_tay_1 && 2 == FEE_RTOS_struct.TuDong.tu_dong_number) {
					if(0 == check_xoay_tay_1(thoi_gian_chac_chan_dem_tay_lan_2)) {
						delayUs(thoi_gian_chong_nhieu_canh_tay); 
						tem= 1; 
						EXTI->PR = 1<<5;	
						return; 						
					}
				}
				else {
					if(0 == check_xoay_tay_1(thoi_gian_chac_chan_dem_tay)) {
						delayUs(thoi_gian_chong_nhieu_canh_tay); 
						tem = 1; 
						EXTI->PR = 1<<5;				
						return; 
					}
				}		
				if(dem_tay_1 != 0) {
					tinh_vi_tri_tay_xoay(1); 
					if(1 == dem_tay_1 && 2 == FEE_RTOS_struct.TuDong.tu_dong_number) {
						FEE_RTOS_struct.TrangThai.luu_count_suon_len_1 = FEE_RTOS_struct.TrangThai.count_suon_len_1 -  1; 
						reset_check_xoay_tay_1(); 
					}
					dem_tay_1--; 
				}				
				
				if(FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_hien_tai != FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_mong_muon) {
					delayUs(thoi_gian_chong_nhieu_canh_tay);
					EXTI->PR = 1<<5;
					return; 
				}
				
				khoa_dc_tay(1); 
				if(1 == FEE_RTOS_struct.TuDong.tu_dong_number)
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[1] = 1; 
				else if (2 == FEE_RTOS_struct.TuDong.tu_dong_number) 
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[2] = 1; 
				else if(5 == FEE_RTOS_struct.TuDong.tu_dong_number)
					FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[5] = 1; 		
				delayUs(thoi_gian_chong_nhieu_canh_tay);
				EXTI->PR = 1<<5;
				return; 
			}		
		}
		
		
// ================= KHOI TAO ===========================// 				
		else if(FEE_RTOS_struct.TrangThai.mode_run == 2) {
			khoa_dc_tay(1); 
			delayUs(thoi_gian_chong_nhieu_canh_tay); 
			EXTI->PR = 1<<5;
		}
		
// ================= LAI TAY ===========================// 		
		else if(0 == FEE_RTOS_struct.TrangThai.mode_run) {
			if(0 == FEE_RTOS_struct.TrangThai.mode_lai_tay) {
				delayUs(thoi_gian_chong_nhieu_canh_tay); 
				EXTI->PR = 1<<5;
			}
			else if(1 == FEE_RTOS_struct.TrangThai.mode_lai_tay) {
				khoa_dc_tay(1); 
				if(1 == FEE_RTOS_struct.LaiTay.flag_tay_1_xoay_trai)
					FEE_RTOS_struct.LaiTay.flag_tay_1_xoay_trai = 0; 
				if(1 == FEE_RTOS_struct.LaiTay.flag_tay_1_xoay_phai)
					FEE_RTOS_struct.LaiTay.flag_tay_1_xoay_phai = 0; 
				
				delayUs(thoi_gian_chong_nhieu_canh_tay); 
				EXTI->PR = 1<<5;
			}
		}		
	}

/********************************************** CONG TAC HANH TRINH ************************************/

	if(GPIO_Pin == GPIO_PIN_15) {
		FEE_RTOS_struct.TuDong.vi_tri_nang_ha = 0; 
		if( 0 == FEE_RTOS_struct.TrangThai.home)
			FEE_RTOS_struct.TrangThai.home = 1; 
			
		khoa_dc_tay(3);
		
		if(2 == FEE_RTOS_struct.TrangThai.mode_run ) {
			if(0 == FEE_RTOS_struct.TrangThai.vi_tri_kep_lua) {
				khoi_tao_an_toan(); 
				FEE_RTOS_struct.TrangThai.vi_tri_kep_lua = 1; 
			}
	
		}
		delayUs(thoi_gian_chong_nhieu_cong_tac); 
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
			else 
				FEE_RTOS_struct.TrangThai.comple_reciver[1] = 0; 
			
			if(rx_data == 'b') {
				if(0 == FEE_RTOS_struct.TrangThai.comple_reciver[4]) {
					FEE_RTOS_struct.TrangThai.comple_reciver[4] = 1; 
					FEE_RTOS_struct.TuDong.tu_dong_number = 4; 
					FEE_RTOS_struct.TrangThai.done[4] = 0;
				}
			}
			else 
				FEE_RTOS_struct.TrangThai.comple_reciver[4] = 0; 
		
			if(rx_data == 'c' && FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[4] == 1) {
				if(0 == FEE_RTOS_struct.TrangThai.comple_reciver[5]) {
					FEE_RTOS_struct.TrangThai.comple_reciver[5] = 1; 
					FEE_RTOS_struct.TuDong.tu_dong_number = 5; 
					FEE_RTOS_struct.TrangThai.done[5] = 0;
				}
			}
			else 
				FEE_RTOS_struct.TrangThai.comple_reciver[5] = 0; 
			
			if(rx_data == 'd') {

			}
			HAL_UART_Receive_IT(&huart3, &rx_data, 1); 
		}		
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



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{		

}

void FEE_RTOS_Innit(void)
{	
  FEE_UART_Innit();
	FEE_Data_Innit();
	FEE_GPIO_Innit();
HAL_UART_Receive_IT(&huart1, FEE_RTOS_struct.H_UART1.rxBuffer, 1);

}
	

