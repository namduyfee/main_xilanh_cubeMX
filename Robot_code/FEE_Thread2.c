#include "main.h"
extern struct FEE_RTOS_struct_def	FEE_RTOS_struct;

extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;

extern I2C_HandleTypeDef hi2c1;

extern TIM_HandleTypeDef htim2;

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */

void StartTask02(void const * argument)
{
  /* USER CODE BEGIN StartTask02 */
  /* Infinite loop */
//	FEE_Compass_Innit();
//	lcd_put_cur(1,0);
//	lcd_send_string("FEE_MPU6050 Start");

	FEE_PES_Innit(&huart1);


  for(;;)
  {
    FEE_PES_Check_Connect();
  }
  /* USER CODE END StartTask02 */
}
