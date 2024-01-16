#include "main.h"
#include "cmsis_os.h"

extern struct FEE_RTOS_struct_def	FEE_RTOS_struct;

extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;

extern I2C_HandleTypeDef hi2c1;

extern TIM_HandleTypeDef htim2;

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

int tem = 0; 

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
	
    pid_dc1(0,0);
    pid_dc2(0,0);
    pid_dc3(0,0); 
	
  for(;;)
  {
   osDelay(1);
//		ve_vi_tri_0(); 
  }
  /* USER CODE END 5 */
}











