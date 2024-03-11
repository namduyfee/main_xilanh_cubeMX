#include "main.h"

#include "dwt_stm32_delay.h"


#define thoi_gian_chong_troi 700
#define toc_do_xoay_tay_tha_2_lua_dau 70
#define thoi_gian_on_dinh_ko_chong_troi 200

extern struct FEE_RTOS_struct_def	FEE_RTOS_struct;

extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;

extern I2C_HandleTypeDef hi2c1;

extern TIM_HandleTypeDef htim2;

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

/* USER CODE BEGIN Header_StartTask04 */
/**
* @brief Function implementing the myTask04 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask04 */

extern uint8_t rx_data; 
extern uint8_t tx_data; 
extern uint8_t dem_tay_1; 
extern uint8_t dem_tay_2;

uint8_t da_chong_troi = 0; 

void StartTask04(void const * argument)
{
  /* USER CODE BEGIN StartTask04 */
  /* Infinite loop */
	tu_dong_init(); 

  for(;;)
  {
    osDelay(1); 
		

/************************************ SWITCH MODE LAI TAY - TU DONG *************************************/ 
		
		if(0 == FEE_PES.Start) {
			if(0 == FEE_RTOS_struct.TrangThai.check_sw_mode) {
				FEE_RTOS_struct.TrangThai.mode_run ^= 1; 
				FEE_RTOS_struct.TrangThai.check_sw_mode = 1; 
			}
		}
		else 
			FEE_RTOS_struct.TrangThai.check_sw_mode = 0;  
		


/*********************************** TU DONG ***************************************/ 
		if(1 == FEE_RTOS_struct.TrangThai.mode_run) {
			
			HAL_UART_Receive_IT(&huart3, &rx_data, 1); 
			
			/************************** tu dong 1 *************************/
			
			if(1 == FEE_RTOS_struct.TuDong.tu_dong_number) {
				if(0 == FEE_RTOS_struct.TrangThai.done[1]) {
					tu_dong_1(); 
					FEE_RTOS_struct.TrangThai.done[1] = 1; 
				}
		
				if(1 == FEE_RTOS_struct.TuDong.day_keo_xilanh_an_toan[0]) {
					if(1 == FEE_RTOS_struct.TrangThai.done[1]) {
						
						reset_chong_troi(); 
						
						reset_check_xoay_tay_1(); 
						dem_tay_1 = 1; 
						FEE_RTOS_struct.TrangThai.luu_count_suon_len_1 = FEE_RTOS_struct.TrangThai.count_suon_len_1; 
						FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_mong_muon = FEE_RTOS_struct.TrangThai.count_vi_tri_tay_1_hien_tai + 1;
						xoay_trai(1, toc_do_xoay_tay_tha_2_lua_dau);  
						
						osDelay(5);
						
						reset_check_xoay_tay_2();
						dem_tay_2 = 1; 
						FEE_RTOS_struct.TrangThai.luu_count_suon_len_2 = FEE_RTOS_struct.TrangThai.count_suon_len_2; 
						FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_mong_muon = FEE_RTOS_struct.TrangThai.count_vi_tri_tay_2_hien_tai - 1;
						xoay_phai(2, toc_do_xoay_tay_tha_2_lua_dau);
						
						FEE_RTOS_struct.TrangThai.done[1] = 2;
					}
				}
				
				if(1 == FEE_RTOS_struct.TuDong.day_keo_xilanh_an_toan[1]) {
					tx_data = 'a'; 
					HAL_UART_Transmit(&huart3, &tx_data, 1, 20); 					
				}
				if(1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[1] && 1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[1] && 0 == da_chong_troi) {
					da_chong_troi = 1; 
					osDelay(thoi_gian_on_dinh_ko_chong_troi); 
//					osDelay(thoi_gian_chong_troi); 
//					chong_troi(); 
				}
				if( (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[1]) && (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[1]) 
				&& (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[1]) ){
					
					if(0 == da_chong_troi) {
						da_chong_troi = 1; 
						osDelay(thoi_gian_on_dinh_ko_chong_troi); 
//						osDelay(thoi_gian_chong_troi); 
//						chong_troi(); 
					}
					
					FEE_RTOS_struct.TuDong.tu_dong_number = 2; 
					FEE_RTOS_struct.TrangThai.done[2] = 0; 		
				}
			}
			
			/************************** tu dong 2 *************************/
			
			else if(2 == FEE_RTOS_struct.TuDong.tu_dong_number) {
				if(0 == FEE_RTOS_struct.TrangThai.done[2]) {
					tu_dong_2(); 
					FEE_RTOS_struct.TrangThai.done[2] = 1; 
				}		
				// ki tu &
				tx_data = 38; 
				HAL_UART_Transmit(&huart3, &tx_data, 1, 20); 				
				
				if( (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[2]) && (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[2]) && 0  == da_chong_troi) {			
					da_chong_troi = 1; 
					osDelay(thoi_gian_on_dinh_ko_chong_troi); 
//					osDelay(thoi_gian_chong_troi); 
//					chong_troi(); 
					
					FEE_RTOS_struct.TuDong.tu_dong_number = 3; 
					FEE_RTOS_struct.TrangThai.done[3] = 0; 		
				}
			}			
			
			/************************** tu dong 3 *************************/
			
			else if(3 == FEE_RTOS_struct.TuDong.tu_dong_number) {
				if(0 == FEE_RTOS_struct.TrangThai.done[3]) {	
					tu_dong_3(); 
					FEE_RTOS_struct.TrangThai.done[3] = 1; 
				}
					tx_data = 'A'; 
					HAL_UART_Transmit(&huart3, &tx_data, 1, 20); 
			}			
			
			
			/************************** tu dong 4 *************************/
			
			else if(4 == FEE_RTOS_struct.TuDong.tu_dong_number) {
				if(0 == FEE_RTOS_struct.TrangThai.done[4] && 1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[3]) {
					tu_dong_4(); 

					FEE_RTOS_struct.TrangThai.done[4] = 1; 
				}
				
				if(1 == FEE_RTOS_struct.TuDong.day_keo_xilanh_an_toan[4]) {
					tx_data = 'B'; 
					HAL_UART_Transmit(&huart3, &tx_data, 1, 20); 					
				}
				
			}			
				/************************** tu dong 5 *************************/
			
			else if(5 == FEE_RTOS_struct.TuDong.tu_dong_number) {
				if(0 == FEE_RTOS_struct.TrangThai.done[5]) {
					tu_dong_5(); 
					FEE_RTOS_struct.TrangThai.done[5] = 1; 
				}
				
				if( (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[5]) 
				&& (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[5]) ) {
					da_chong_troi = 1; 
					osDelay(thoi_gian_chong_troi); 
					chong_troi(); 
				}
				
				if( (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[5]) && (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[5]) 
				&& ( 1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[5]) ){
					
//					if(0 == da_chong_troi) {
//						da_chong_troi = 1; 
//						osDelay(thoi_gian_chong_troi); 
//						chong_troi(); 
//					}
					
					FEE_RTOS_struct.TuDong.tu_dong_number = 6; 
					FEE_RTOS_struct.TrangThai.done[6] = 0; 

				}
			}			
			/************************** tu dong 6 *************************/
			
			else if(6 == FEE_RTOS_struct.TuDong.tu_dong_number) {
				if(0 == FEE_RTOS_struct.TrangThai.done[6]) {
//					if(1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[6]) {
					tu_dong_6();
					FEE_RTOS_struct.TrangThai.done[6] = 1; 
//					}
				}
			}			
		}
	}
 }

