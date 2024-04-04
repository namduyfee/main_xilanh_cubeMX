#include "main.h"
#include "cmsis_os.h"
#define toc_do_den_vi_tri_kep 250

extern struct FEE_RTOS_struct_def	FEE_RTOS_struct;
//extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;

extern I2C_HandleTypeDef hi2c1;

//extern TIM_HandleTypeDef htim2;

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

extern uint8_t cam_bien_chu_u_td5; 
uint8_t check_day_tay_gap_td5 = 0; 

uint8_t td11_4 = 0; 

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */

void StartTask05(void const * argument)
{
  /* USER CODE BEGIN StartTask02 */
  /* Infinite loop */


  for(;;)
  {

		osDelay(1);
		
		if(1 == FEE_RTOS_struct.TrangThai.mode_run) {
			if(45 == FEE_RTOS_struct.TuDong.tu_dong_number) {
				
				thu_tay_gap_lua(); 
				stop_dc_keo_sung(); 
				nang_tay_kep_bong(); 
				kep_bong(); 
				nha(1); 
				nha(2);				
			}
			
			if(1 == FEE_RTOS_struct.TuDong.tu_dong_number) {
				if(1 == FEE_RTOS_struct.TuDong.day_keo_xilanh_an_toan[1])  {
					thu_tay_gap_lua(); 	
					FEE_RTOS_struct.Nang_ha.toc_do = 165; 
					FEE_RTOS_struct.TuDong.day_keo_xilanh_an_toan[1] = 2; 
				}	
			}
			

			if(td11_4 == 1) {
				
				osDelay(100); 
				day_tay_gap_lua(); 	
				osDelay(400); 
				
				nang_ha_tay_gap_tu_dong(FEE_RTOS_struct.TuDong.di_tha_lua_an_toan, 150); 

				td11_4 = 2; 
			}
		}
   }
  /* USER CODE END StartTask02 */
}


