#include "main.h"
#include "stm32f1xx_hal.h"
extern struct FEE_RTOS_struct_def	FEE_RTOS_struct;

extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;

extern I2C_HandleTypeDef hi2c1;

extern TIM_HandleTypeDef htim2;

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

/* USER CODE BEGIN Header_StartTask03 */
/**
* @brief Function implementing the myTask03 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask03 */
void StartTask03(void const * argument)
{
  /* USER CODE BEGIN StartTask03 */
  /* Infinite loop */
	lai_tay_init(); 
  for(;;)
  {
		osDelay(1);
		
/*************************** KHOI TAO TU DONG _ VE VI TRI  *************************************/ 		
		
		khoi_tao_tu_dong(); 
		
/************************************ SWITCH MODE  LAI TAY 1 - 2 *************************************/ 
		
		if(0 == FEE_PES.Select && 0 == FEE_PES.R2) {
			if(0 == FEE_RTOS_struct.TrangThai.check_sw_mode_lai_tay) {
				FEE_RTOS_struct.TrangThai.mode_lai_tay ^= 1; 
				FEE_RTOS_struct.TrangThai.check_sw_mode_lai_tay = 1; 
			}
		}
		else 
			FEE_RTOS_struct.TrangThai.check_sw_mode_lai_tay = 0;  
		
/********************************** KHOI DONG MEM ************************************************/
//		if(1 == FEE_RTOS_struct.TrangThai.khoi_dong_mem_tay_1 || 1 == FEE_RTOS_struct.TrangThai.khoi_dong_mem_tay_2) {
//			uint16_t tem1 = FEE_RTOS_struct.Tay_1.toc_do; 
//			uint16_t tem2 = FEE_RTOS_struct.Tay_2.toc_do; 
//			if(1 == FEE_RTOS_struct.TrangThai.khoi_dong_mem_tay_1) {
//				if(1 != FEE_RTOS_struct.Tay_1.toc_do) {
//					FEE_RTOS_struct.Tay_1.toc_do = tem1 - (tem1 / 5); 
//				}
//			}
//			
//			if(1 == FEE_RTOS_struct.TrangThai.khoi_dong_mem_tay_2) {
//				
//				if(1 != FEE_RTOS_struct.Tay_2.toc_do) {
//					FEE_RTOS_struct.Tay_2.toc_do = tem2 - (tem2 / 5); 
//				}				
//			}
//			osDelay(50); 
//		}
		
/*********************************** LAI TAY ***************************************/ 		
		
		if(0 == FEE_RTOS_struct.TrangThai.mode_run) {
			nut_lai_tay(); 
			ham_lai_tay(); 
		}	
			


	}
  /* USER CODE END StartTask03 */
}

