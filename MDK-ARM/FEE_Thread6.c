#include "main.h"
#include "cmsis_os.h"

extern struct FEE_RTOS_struct_def	FEE_RTOS_struct;
//extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;

extern I2C_HandleTypeDef hi2c1;

//extern TIM_HandleTypeDef htim2;

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

extern uint8_t cam_bien_chu_u_td5; 

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */

void StartTask06(void const * argument)
{
  /* USER CODE BEGIN StartTask02 */
  /* Infinite loop */


  for(;;)
  {

		osDelay(1);
		
		/************************************ Khoi Dong Mem Tay 2 *****************************/ 
		
		if(1 == FEE_RTOS_struct.TrangThai.mode_run) {
			
			/***************************** chong troi cho danh ve ***************************/ 
			
			if(1 == FEE_RTOS_struct.TrangThai.chong_troi_tay_2) {
					
				if(1 == FEE_RTOS_struct.TrangThai.khoi_dong_mem_tay_2) {
					if(FEE_RTOS_struct.Tay_2.toc_do > 15) 
						FEE_RTOS_struct.Tay_2.toc_do = FEE_RTOS_struct.Tay_2.toc_do - (FEE_RTOS_struct.Tay_2.toc_do / 8); 
					osDelay(80); 
				}
			}
			
			/************************* chong troi xoay thuong ******************************/ 
			
			else {
				
				if(1 == FEE_RTOS_struct.TrangThai.khoi_dong_mem_tay_2) {
					
					if(FEE_RTOS_struct.Tay_2.toc_do > 40) {
						
						if(FEE_RTOS_struct.TrangThai.goc_xoay_chong_troi_tay_2 == 180)
							FEE_RTOS_struct.Tay_2.toc_do = FEE_RTOS_struct.Tay_2.toc_do - (FEE_RTOS_struct.Tay_2.toc_do / 7); 
						else if(FEE_RTOS_struct.TrangThai.goc_xoay_chong_troi_tay_2 == 90)
									FEE_RTOS_struct.Tay_2.toc_do = FEE_RTOS_struct.Tay_2.toc_do - (FEE_RTOS_struct.Tay_2.toc_do / 5); 

					}		
					
					if(FEE_RTOS_struct.TrangThai.goc_xoay_chong_troi_tay_2 == 180) 
						osDelay(130); 
					else if(FEE_RTOS_struct.TrangThai.goc_xoay_chong_troi_tay_2 == 90)
						osDelay(95); 
				}
			}
			
		}
   }
  /* USER CODE END StartTask02 */
}


