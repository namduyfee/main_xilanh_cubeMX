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


/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
// THUAN: Cun
void StartDefaultTask(void const * argument)
{
  /* init code for USB_DEVICE */
//  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
	initTimers(); 
	trang_thai_init(); 
	dong_co_init(); 

	
	
  for(;;)
  {
		
		osDelay(1);
		pid_dc1(FEE_RTOS_struct.Tay_1.chieu, FEE_RTOS_struct.Tay_1.toc_do);
    pid_dc2(FEE_RTOS_struct.Tay_2.chieu, FEE_RTOS_struct.Tay_2.toc_do);
    pid_dc3(FEE_RTOS_struct.Nang_ha.chieu, FEE_RTOS_struct.Nang_ha.toc_do); 
			
 }
  /* USER CODE END 5 */
}











