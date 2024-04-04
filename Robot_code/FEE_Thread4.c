#include "main.h"

#include "dwt_stm32_delay.h"

#define thoi_gian_chong_troi 100
#define toc_do_xoay_tay_tha_2_lua_dau 220
#define thoi_gian_di_chuyen_tranh_va_vao_lua 500
#define toc_do_nang_ha 250 
#define toc_do_xoay_tay_tha_lua 250

extern struct FEE_RTOS_struct_def	FEE_RTOS_struct;

//extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;

extern I2C_HandleTypeDef hi2c1;

//extern TIM_HandleTypeDef htim2;

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

/************************ VARIABLE Tu Dong 11 *****************/
uint8_t td11_2 = 0; 
uint8_t td11_1 = 0; 
extern uint8_t td11_4; 
/*********************** VARIABLE Tu Dong 5 *******************/ 
uint8_t cam_bien_chu_u_td5 = 0; 
uint8_t tem_tx_data = '+'; 

uint8_t Connected = 0; 

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
			if(0 == Connected) {
				HAL_UART_Receive_IT(&huart3, &rx_data, 1); 
				Connected = 1; 
			}
			
// ================== LAY LUA ===================// 		
			
			/************************** tu dong 1 *************************/
			
			if(1 == FEE_RTOS_struct.TuDong.tu_dong_number) {
				if(0 == FEE_RTOS_struct.TrangThai.done[1]) {
						tu_dong_1(); 
						FEE_RTOS_struct.TrangThai.done[1] = 1; 
				}
				
				if(1 == FEE_RTOS_struct.TrangThai.done[1]) {
					
					if(1 == FEE_RTOS_struct.TuDong.day_keo_xilanh_an_toan[0]) {
						
						
						reset_khoi_dong_mem(1);
						khoi_dong_mem(1, 90); 
						
						reset_khoi_dong_mem(2);
						khoi_dong_mem(2, 90); 
						
						reset_chong_troi(); 
						
						xoay_90(1, 0, toc_do_xoay_tay_tha_2_lua_dau); 
						osDelay(5);
						xoay_90(2, 1, toc_do_xoay_tay_tha_2_lua_dau); 
						
						FEE_RTOS_struct.TrangThai.done[1] = 2; 
						
					}
				}
				
				if(1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[1] && 1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[1] && 0 == FEE_RTOS_struct.TrangThai.da_chong_troi) {
						FEE_RTOS_struct.TrangThai.da_chong_troi = 1; 
						osDelay(thoi_gian_chong_troi); 
						chong_troi(0); 
				}
				
				if( (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[1]) && (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[1]) 
				&& (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[1]) ){
					
					if(0 == FEE_RTOS_struct.TrangThai.da_chong_troi) {
						FEE_RTOS_struct.TrangThai.da_chong_troi = 1; 
						osDelay(thoi_gian_chong_troi); 
						chong_troi(0); 
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
				
				tx_data = 'a';
				so_lan_trans(20); 
				
				if( (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[2]) && (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[2]) && 0  == FEE_RTOS_struct.TrangThai.da_chong_troi) {			
					
					FEE_RTOS_struct.TrangThai.da_chong_troi = 1; 
					osDelay(thoi_gian_chong_troi); 
					chong_troi(0); 
					
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
			}			
			
			/************************** tu dong 4 *************************/
			
			else if(4 == FEE_RTOS_struct.TuDong.tu_dong_number) {
			
				if(0 == FEE_RTOS_struct.TrangThai.done[4]) {
					day_tay_gap_lua();
				}
				
				if(0 == FEE_RTOS_struct.TrangThai.done[4] && 1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[3]) {
					osDelay(600); 
					tu_dong_4(); 
					FEE_RTOS_struct.TrangThai.done[4] = 1; 
				}
				
				if(1 == FEE_RTOS_struct.TuDong.day_keo_xilanh_an_toan[4] && FEE_RTOS_struct.TrangThai.done[4] == 1) {
					tu_dong_4_2(); 
					FEE_RTOS_struct.TrangThai.done[4] = 2; 
				}
				
				if(1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[4] && 1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[4] && 0 == FEE_RTOS_struct.TrangThai.da_chong_troi) {
						FEE_RTOS_struct.TrangThai.da_chong_troi = 1; 
						osDelay(thoi_gian_chong_troi); 
						chong_troi(0); 
				}				
				
				
				if(2 == FEE_RTOS_struct.TuDong.day_keo_xilanh_an_toan[4]) {
					
					if(2 == FEE_RTOS_struct.TrangThai.done[4]) {
						thu_tay_gap_lua(); 
						FEE_RTOS_struct.TrangThai.done[4] = 3; 
						osDelay(300); 
					}
					tx_data = 'B'; 
					so_lan_trans(20); 		
					
				}				
				
				
			}			
				/************************** tu dong 5 *************************/
			
			else if(5 == FEE_RTOS_struct.TuDong.tu_dong_number) {
				
				if(0 == FEE_RTOS_struct.TrangThai.done[5]) {
					day_tay_gap_lua(); 
					FEE_RTOS_struct.TrangThai.done[5] = 1; 
				}
				
				if(FEE_RTOS_struct.TrangThai.done[5] == 1) {
					osDelay(950); 
					den_vi_tri_kep_lua(250); 
					FEE_RTOS_struct.TrangThai.done[5] = 2; 
				}
				if(FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[5] == 1 && FEE_RTOS_struct.TrangThai.done[5] == 2) {
					FEE_RTOS_struct.TuDong.tu_dong_number = 6; 
					FEE_RTOS_struct.TrangThai.done[6] = 0; 
				}
			}			
			/************************** tu dong 6 *************************/
			
			else if(6 == FEE_RTOS_struct.TuDong.tu_dong_number) {

				if(0 == FEE_RTOS_struct.TrangThai.done[6]) {
					
					tu_dong_6();
					FEE_RTOS_struct.TrangThai.done[6] = 1; 
				}
				if(1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[6]) {
					
					tx_data = 'c'; 
					so_lan_trans(20); 
				
					FEE_RTOS_struct.TrangThai.done[6] = 2; 
				}
				
				if(2 == FEE_RTOS_struct.TrangThai.done[6] && FEE_RTOS_struct.TrangThai.comple_reciver[6] == 1) {
						osDelay(500); 
						nang_ha_tay_gap_tu_dong(FEE_RTOS_struct.TuDong.nang_start_di_tha_lua, 80); 					
						FEE_RTOS_struct.TrangThai.done[6] = 3; 
					
				}
			}
			
// ================= THA LUA ===================//
			
			/************************** tu dong 7 *************************/
			else if(7 == FEE_RTOS_struct.TuDong.tu_dong_number) {
				
				if(0 == FEE_RTOS_struct.TrangThai.done[7] && 0 == FEE_RTOS_struct.TuDong.nang_ha_tha_lua[7]) {
					
					if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) == 0) {
						nang_canh_tay(90); 
						while(FEE_RTOS_struct.TuDong.vi_tri_nang_ha < 5) 
							osDelay(1); 
					}
					
					
					den_vi_tri_kep_lua(250); 
					FEE_RTOS_struct.TuDong.nang_ha_tha_lua[7] = 1; 
					
				}
				
				if(0 == FEE_RTOS_struct.TrangThai.done[7] && 2 == FEE_RTOS_struct.TuDong.nang_ha_tha_lua[7]) {
					osDelay(50); 
					if(FEE_RTOS_struct.TuDong.mau_san == 'D') {
					control_xilanh(1,0); 
					control_xilanh(5,0); 
					}
					else if(FEE_RTOS_struct.TuDong.mau_san == 'X') {
					control_xilanh(3,0); 
					control_xilanh(7,0); 
					}
					
					osDelay(400); 																																	// thoi gian mo tay xilanh 
					FEE_RTOS_struct.TrangThai.done[7] = 1;					
					FEE_RTOS_struct.TuDong.nang_ha_tha_lua[7] = 3; 
					
				}
				
				if(1 == FEE_RTOS_struct.TrangThai.done[7] && FEE_RTOS_struct.TuDong.nang_ha_tha_lua[7] == 3) {
					
					nang_ha_tay_gap_tu_dong(FEE_RTOS_struct.TuDong.di_tha_lua_an_toan, 150); 
					osDelay(80); 
					FEE_RTOS_struct.TuDong.nang_ha_tha_lua[7] = 4; 
					
				}
				
				if(FEE_RTOS_struct.TrangThai.done[7] == 1 && 4 == FEE_RTOS_struct.TuDong.nang_ha_tha_lua[7]) {
					tx_data = 'N'; 
					so_lan_trans(15); 					
				}
				
				if(1 == FEE_RTOS_struct.TrangThai.done[7] && FEE_RTOS_struct.TrangThai.comple_reciver[7] == 2) {
					tu_dong_xoay_tha_90(); 
					FEE_RTOS_struct.TrangThai.done[7] = 2; 
				}
				
				if( (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[7]) 
				&& (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[7]) && 2 == FEE_RTOS_struct.TrangThai.done[7]) {
					if(0 == FEE_RTOS_struct.TrangThai.da_chong_troi) {
						FEE_RTOS_struct.TrangThai.da_chong_troi = 1; 
						osDelay(thoi_gian_chong_troi); 
						chong_troi(1); 
					}
				}				
				
				if(1 == FEE_RTOS_struct.TrangThai.da_chong_troi && 2 == FEE_RTOS_struct.TrangThai.done[7] && 
					FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[7] == 1) {
					tx_data = 'd'; 
					so_lan_trans(20); 					
				}	
			}
			
			/************************** tu dong 8 *************************/
			
			else if(8 == FEE_RTOS_struct.TuDong.tu_dong_number) {
				
				if(0 == FEE_RTOS_struct.TrangThai.done[8] && 0 == FEE_RTOS_struct.TuDong.nang_ha_tha_lua[8]) {
					
					if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) == 0) {
						nang_canh_tay(90); 
						while(FEE_RTOS_struct.TuDong.vi_tri_nang_ha < 5) 
							osDelay(1); 
					}
					
					den_vi_tri_kep_lua(250); 
					FEE_RTOS_struct.TuDong.nang_ha_tha_lua[8] = 1; 
				}
				
				if(0 == FEE_RTOS_struct.TrangThai.done[8] && 2 == FEE_RTOS_struct.TuDong.nang_ha_tha_lua[8]) {
					osDelay(50); 
					
					if(FEE_RTOS_struct.TuDong.mau_san == 'D') {
					control_xilanh(2,0); 
					control_xilanh(8,0); 
					}
					else if(FEE_RTOS_struct.TuDong.mau_san == 'X') {
					control_xilanh(4,0); 
					control_xilanh(6,0); 
					}
					
					osDelay(400); 
					FEE_RTOS_struct.TrangThai.done[8] = 1; 
					FEE_RTOS_struct.TuDong.nang_ha_tha_lua[8] = 3; 
					
				}
				
				if(1 == FEE_RTOS_struct.TrangThai.done[8] && FEE_RTOS_struct.TuDong.nang_ha_tha_lua[8] == 3) {
					nang_ha_tay_gap_tu_dong(FEE_RTOS_struct.TuDong.di_tha_lua_an_toan, 150); 
					 FEE_RTOS_struct.TuDong.nang_ha_tha_lua[8] = 4; 
				}						
				
				if(FEE_RTOS_struct.TrangThai.done[8] == 1 && FEE_RTOS_struct.TuDong.nang_ha_tha_lua[8] == 4) {
					tx_data = 'N'; 
					so_lan_trans(15); 					
				}				
						
	
				if(1 == FEE_RTOS_struct.TrangThai.done[8] && FEE_RTOS_struct.TrangThai.comple_reciver[8] == 2) {

						reset_chong_troi(); 
						
					
					if(FEE_RTOS_struct.TuDong.mau_san == 'D') {
						khoi_dong_mem(1, 90);
						khoi_dong_mem(2, 180);
						
						xoay_90(1, 1, toc_do_xoay_tay_tha_lua); 
						xoay_180(2, 1, toc_do_xoay_tay_tha_lua); 
					}
					else if(FEE_RTOS_struct.TuDong.mau_san == 'X') {
						
						khoi_dong_mem(2, 90);
						khoi_dong_mem(1, 180);		
						
						xoay_90(2, 0, toc_do_xoay_tay_tha_lua); 
						xoay_180(1, 0, toc_do_xoay_tay_tha_lua); 
					}					
					FEE_RTOS_struct.TrangThai.done[8] = 2; 
				}
				
				if( (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[8]) 
				&& (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[8]) && FEE_RTOS_struct.TrangThai.done[8] == 2) {
					if(0 == FEE_RTOS_struct.TrangThai.da_chong_troi) {
						FEE_RTOS_struct.TrangThai.da_chong_troi = 1; 
						osDelay(thoi_gian_chong_troi); 
						chong_troi(1); 
					}
				}
				
				if(1 == FEE_RTOS_struct.TrangThai.da_chong_troi && 2 == FEE_RTOS_struct.TrangThai.done[8] && 
					FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[8] == 1) {
					tx_data = 'e'; 
					so_lan_trans(20); 					
				}
				
			}
			
			/************************** tu dong 9 *************************/
			
			else if(9 == FEE_RTOS_struct.TuDong.tu_dong_number) {			
				
				if(0 == FEE_RTOS_struct.TrangThai.done[9] && 0 == FEE_RTOS_struct.TuDong.nang_ha_tha_lua[9]) {
					
					if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) == 0) {
						nang_canh_tay(90); 
						while(FEE_RTOS_struct.TuDong.vi_tri_nang_ha < 5) 
							osDelay(1); 
					}				
					
					den_vi_tri_kep_lua(250); 
					FEE_RTOS_struct.TuDong.nang_ha_tha_lua[9] = 1; 
				}
				
				if(0 == FEE_RTOS_struct.TrangThai.done[9] && 2 == FEE_RTOS_struct.TuDong.nang_ha_tha_lua[9]) {
					osDelay(50); 
					if(FEE_RTOS_struct.TuDong.mau_san == 'D') {
					control_xilanh(3,0); 
					control_xilanh(6,0); 
					}
					else if(FEE_RTOS_struct.TuDong.mau_san == 'X') {
					control_xilanh(2,0); 
					control_xilanh(5,0); 
					} 
					osDelay(400); 
					FEE_RTOS_struct.TrangThai.done[9] = 1; 
					FEE_RTOS_struct.TuDong.nang_ha_tha_lua[9] = 3; 
				}
		
				if(1 == FEE_RTOS_struct.TrangThai.done[9] && FEE_RTOS_struct.TuDong.nang_ha_tha_lua[9] == 3) {
					nang_ha_tay_gap_tu_dong(FEE_RTOS_struct.TuDong.di_tha_lua_an_toan, 150); 
					 FEE_RTOS_struct.TuDong.nang_ha_tha_lua[9] = 4; 
				}				
				
				if(FEE_RTOS_struct.TrangThai.done[9] == 1 && 4 == FEE_RTOS_struct.TuDong.nang_ha_tha_lua[9]) {
					tx_data = 'N'; 
					so_lan_trans(15); 					
				}				
			
				if(1 == FEE_RTOS_struct.TrangThai.done[9] && FEE_RTOS_struct.TrangThai.comple_reciver[9] == 2) {
					
					reset_chong_troi(); 
					
					khoi_dong_mem(1, 90); 
					khoi_dong_mem(2, 90); 
					
					if(FEE_RTOS_struct.TuDong.mau_san == 'D') {
						xoay_90(1, 1, toc_do_xoay_tay_tha_lua); 
						xoay_90(2, 1, toc_do_xoay_tay_tha_lua); 
					}
					else if(FEE_RTOS_struct.TuDong.mau_san == 'X') {
						xoay_90(1, 0, toc_do_xoay_tay_tha_lua); 
						xoay_90(2, 0, toc_do_xoay_tay_tha_lua); 
					} 
					FEE_RTOS_struct.TrangThai.done[9] = 2; 
				}
				
				if( (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[9]) 
				&& (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[9]) && FEE_RTOS_struct.TrangThai.done[9] == 2) {
					if(0 == FEE_RTOS_struct.TrangThai.da_chong_troi) {
						FEE_RTOS_struct.TrangThai.da_chong_troi = 1; 
						osDelay(thoi_gian_chong_troi); 
						chong_troi(1); 
					}
				}
				
				if(1 == FEE_RTOS_struct.TrangThai.da_chong_troi && 2 == FEE_RTOS_struct.TrangThai.done[9] && 
					FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[9] == 1) {
					tx_data = 'f'; 
					so_lan_trans(20); 					
				}			
				
			}
			/************************** tu dong 10 *************************/
			
			else if(10 ==  FEE_RTOS_struct.TuDong.tu_dong_number) {			
				
				if(0 == FEE_RTOS_struct.TrangThai.done[10] && 0 == FEE_RTOS_struct.TuDong.nang_ha_tha_lua[10]) {
					
					if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) == 0) {
						nang_canh_tay(90); 
						while(FEE_RTOS_struct.TuDong.vi_tri_nang_ha < 5) 
							osDelay(1); 
					}							
					
					den_vi_tri_kep_lua(250); 
					FEE_RTOS_struct.TuDong.nang_ha_tha_lua[10] = 1; 
				}
				
				if(0 == FEE_RTOS_struct.TrangThai.done[10] && 2 == FEE_RTOS_struct.TuDong.nang_ha_tha_lua[10]) {
					osDelay(50); 
					if(FEE_RTOS_struct.TuDong.mau_san == 'D') {
					control_xilanh(4,0); 
					control_xilanh(7,0); 
					}
					else if(FEE_RTOS_struct.TuDong.mau_san == 'X') {
					control_xilanh(1,0); 
					control_xilanh(8,0); 
					} 
					
					osDelay(300); 
					
					FEE_RTOS_struct.TrangThai.done[10] = 1; 
					FEE_RTOS_struct.TuDong.nang_ha_tha_lua[10] = 3; 
					
				}
	
				if(FEE_RTOS_struct.TrangThai.done[10] == 1 && FEE_RTOS_struct.TuDong.nang_ha_tha_lua[10] == 3) {
					tx_data = 'N'; 
					so_lan_trans(15); 					
				}				
				
				if(1 == FEE_RTOS_struct.TrangThai.done[10] && FEE_RTOS_struct.TrangThai.comple_reciver[10] == 2) { 
					FEE_RTOS_struct.TrangThai.done[10] = 2; 
					FEE_RTOS_struct.TuDong.tu_dong_number = 11;
					FEE_RTOS_struct.TrangThai.done[11] = 0; 
				}
				
			}				
			/************************** tu dong 11 *************************/
			
			else if(11 == FEE_RTOS_struct.TuDong.tu_dong_number) {
				
				if(0 == FEE_RTOS_struct.TrangThai.done[11] && td11_1 == 0) {

					// da dc delay bang encoder 
					
					
					
					tu_dong_11_1(FEE_RTOS_struct.TuDong.kep_lua_tren_ro); 
					
					thu_tay_gap_lua();
					
					FEE_RTOS_struct.TrangThai.done[11] = 1; 
					
					td11_1 = 1; 
					
				}
				
				
				if(1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[11] && 1 == FEE_RTOS_struct.TrangThai.done[11]) {
					
					osDelay(400); 
					
					if(FEE_RTOS_struct.TuDong.mau_san == 'D') {
					control_xilanh(3,1); 
					control_xilanh(6,1); 
					}
					else if(FEE_RTOS_struct.TuDong.mau_san == 'X') {
					control_xilanh(2,1); 
					control_xilanh(5,1); 
					} 

					osDelay(400);
					
					tu_dong_11_2(FEE_RTOS_struct.TuDong.nang_lua_khoi_ro); 
					
					
					FEE_RTOS_struct.TrangThai.done[11] = 2;
				}
				
				if(2 == FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[11] && 2 == FEE_RTOS_struct.TrangThai.done[11]) {
					
					tu_dong_xoay_tha_90(); 
					osDelay(130); 
					
					tu_dong_11_1(FEE_RTOS_struct.TuDong.kep_lua_tren_ro); 
					
					td11_2 = 1; 
					FEE_RTOS_struct.TrangThai.done[11] = 3; 
				}
				
				if(td11_2 == 1) {

					tx_data = '^'; 
					so_lan_trans(20); 								
				}
				
				if( (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[11]) 
				&& (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[11]) && FEE_RTOS_struct.TrangThai.done[11] == 3) {
					
					if(0 == FEE_RTOS_struct.TrangThai.da_chong_troi) {
						FEE_RTOS_struct.TrangThai.da_chong_troi = 1; 
						osDelay(thoi_gian_chong_troi); 
						chong_troi(1); 
					}
				}		
				
				if( (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[11]) && (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[11]) 
				&& (3 == FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[11]) && FEE_RTOS_struct.TrangThai.done[11] == 3){
					
					if(0 == FEE_RTOS_struct.TrangThai.da_chong_troi) {
						FEE_RTOS_struct.TrangThai.da_chong_troi = 1; 
						osDelay(thoi_gian_chong_troi); 
						chong_troi(1); 
					}
					
					osDelay(800); 
					
					if(FEE_RTOS_struct.TuDong.mau_san == 'D') {
					control_xilanh(4,1); 
					control_xilanh(5,1); 
					}
					else if(FEE_RTOS_struct.TuDong.mau_san == 'X') {
					control_xilanh(3,1); 
					control_xilanh(8,1); 
					} 
					osDelay(300);
					
					tu_dong_11_2(FEE_RTOS_struct.TuDong.nang_lua_khoi_ro); 
					
					FEE_RTOS_struct.TrangThai.done[11] = 4; 
				}
				
				if(4 == FEE_RTOS_struct.TrangThai.done[11] && 4 == FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[11]) {					
	
					if(FEE_RTOS_struct.TuDong.mau_san == 'D') {
						
						reset_chong_troi_1(); 
						
						khoi_dong_mem(1, 180); 
						
						xoay_180(1, 1, toc_do_xoay_tay_tha_lua); 
					}
					
					else if(FEE_RTOS_struct.TuDong.mau_san == 'X') {
						
						reset_chong_troi_2(); 
						
						khoi_dong_mem(2, 180);
						
						xoay_180(2, 0, toc_do_xoay_tay_tha_lua);  
					}
					
					td11_4 = 1; 					// thread 5 
				
					FEE_RTOS_struct.TrangThai.done[11] = 5; 
					
					osDelay(100); 
				}
				
				if(td11_4 == 1 || td11_4 == 2) {
					tx_data = '&'; 
					so_lan_trans(20); 								
				}
				
				if(FEE_RTOS_struct.TrangThai.done[11] == 5) {
					
					if(FEE_RTOS_struct.TuDong.mau_san == 'D') {
						
						if(2 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[11]) {
							
							if(0 == FEE_RTOS_struct.TrangThai.da_chong_troi) {
								
								FEE_RTOS_struct.TrangThai.da_chong_troi = 1; 
								osDelay(thoi_gian_chong_troi); 
								chong_troi_tay_1(1); 
							}
						}						
					}
					else if(FEE_RTOS_struct.TuDong.mau_san == 'X') {
						
						if(2 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[11]) {
							
							if(0 == FEE_RTOS_struct.TrangThai.da_chong_troi) {
								
								FEE_RTOS_struct.TrangThai.da_chong_troi = 1; 
								osDelay(thoi_gian_chong_troi); 
								chong_troi_tay_2(1); 
							}
						}								
					}
					if(FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[11] == 5 && FEE_RTOS_struct.TrangThai.da_chong_troi == 1 &&
						FEE_RTOS_struct.TrangThai.done[11] == 5) {
						osDelay(100); 
						tx_data = 'g'; 
						so_lan_trans(20); 							
					}
					
				}
			}
			
			else if(12 == FEE_RTOS_struct.TuDong.tu_dong_number) {
				
				if(0 == FEE_RTOS_struct.TrangThai.done[12] && FEE_RTOS_struct.TuDong.nang_ha_tha_lua[12] == 0) {
					
					if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) == 0) {
						nang_canh_tay(90); 
						while(FEE_RTOS_struct.TuDong.vi_tri_nang_ha < 5) 
							osDelay(1); 
					}							
					
					den_vi_tri_kep_lua(250); 
					FEE_RTOS_struct.TuDong.nang_ha_tha_lua[12] = 1; 
					
				}
				
				if(0 == FEE_RTOS_struct.TrangThai.done[12] && FEE_RTOS_struct.TuDong.nang_ha_tha_lua[12] == 2) {
					osDelay(50); 
					if(FEE_RTOS_struct.TuDong.mau_san == 'D') {
					control_xilanh(3,0); 
					control_xilanh(6,0); 
					}
					else if(FEE_RTOS_struct.TuDong.mau_san == 'X') {
					control_xilanh(2,0); 
					control_xilanh(5,0); 
					} 
					osDelay(400); 
					FEE_RTOS_struct.TuDong.nang_ha_tha_lua[12] = 3; 
					FEE_RTOS_struct.TrangThai.done[12] = 1; 
				}
				
				if(1 == FEE_RTOS_struct.TrangThai.done[12] && FEE_RTOS_struct.TuDong.nang_ha_tha_lua[12] == 3) {
					nang_ha_tay_gap_tu_dong(FEE_RTOS_struct.TuDong.di_tha_lua_an_toan, 100); 
					 FEE_RTOS_struct.TuDong.nang_ha_tha_lua[12] = 4; 
				}						
				
				if(FEE_RTOS_struct.TrangThai.done[12] == 1 && 4 == FEE_RTOS_struct.TuDong.nang_ha_tha_lua[12]) {
					tx_data = 'N'; 
					so_lan_trans(15); 						
				}
				

				
				if(1 == FEE_RTOS_struct.TrangThai.done[12] && FEE_RTOS_struct.TrangThai.comple_reciver[12] == 2) {

					reset_chong_troi(); 
					
					khoi_dong_mem(1, 90); 
					khoi_dong_mem(2, 90); 
					
					if(FEE_RTOS_struct.TuDong.mau_san == 'D') {
						xoay_90(1, 1, toc_do_xoay_tay_tha_lua); 
						xoay_90(2, 0, toc_do_xoay_tay_tha_lua); 
					}
					else if(FEE_RTOS_struct.TuDong.mau_san == 'X') {
						xoay_90(1, 1, toc_do_xoay_tay_tha_lua); 
						xoay_90(2, 0, toc_do_xoay_tay_tha_lua); 
					}					
					FEE_RTOS_struct.TrangThai.done[12] = 2; 
				}		
				
				if( (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_1[12]) 
				&& (1 == FEE_RTOS_struct.TuDong.check_cam_bien_td_tay_2[12]) && FEE_RTOS_struct.TrangThai.done[12] == 2) {
					if(0 == FEE_RTOS_struct.TrangThai.da_chong_troi) {
						FEE_RTOS_struct.TrangThai.da_chong_troi = 1; 
						osDelay(thoi_gian_chong_troi); 
						chong_troi(1); 
					}
				}					
				
				if(1 == FEE_RTOS_struct.TrangThai.da_chong_troi && 2 == FEE_RTOS_struct.TrangThai.done[12] && 
					FEE_RTOS_struct.TuDong.check_cam_bien_td_nang_ha[12] == 4) {
					tx_data = 'h'; 
					so_lan_trans(20); 					
				}
				
			}
			
			else if(13 == FEE_RTOS_struct.TuDong.tu_dong_number) {
				
				
				if(0 == FEE_RTOS_struct.TrangThai.done[13] &&  FEE_RTOS_struct.TuDong.nang_ha_tha_lua[13] == 0) {
					
					if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) == 0) {
						nang_canh_tay(90); 
						while(FEE_RTOS_struct.TuDong.vi_tri_nang_ha < 5) 
							osDelay(1); 
					}									
					
					den_vi_tri_kep_lua(250); 
					FEE_RTOS_struct.TuDong.nang_ha_tha_lua[13] = 1; 
				}
				
				if(0 == FEE_RTOS_struct.TrangThai.done[13] && FEE_RTOS_struct.TuDong.nang_ha_tha_lua[13] == 2) {
					osDelay(50); 
					if(FEE_RTOS_struct.TuDong.mau_san == 'D') {
					control_xilanh(4,0); 
					control_xilanh(5,0); 
					}
					else if(FEE_RTOS_struct.TuDong.mau_san == 'X') {
					control_xilanh(3,0); 
					control_xilanh(8,0); 
					} 
					FEE_RTOS_struct.TrangThai.done[13] = 1; 
				}
				if(FEE_RTOS_struct.TrangThai.done[13] == 1) {
					tx_data = '6'; 
					so_lan_trans(20); 
				}
			}
		}
	}
 }

