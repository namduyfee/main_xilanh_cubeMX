#ifndef		__FEE_RTOS_H__
#define		__FEE_RTOS_H__
/*******************************    INCLUDES   ********************************/

#include "main.h"

/***************************    GLOBAL VARIABLES   ****************************/

extern struct FEE_RTOS_struct_def	FEE_RTOS_struct;

extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;

extern I2C_HandleTypeDef hi2c1;

extern TIM_HandleTypeDef htim2;

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern  uint8_t ktra_khoa;

/***************************       FUNCTIONS       ****************************/

void FEE_RTOS_Innit(void);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim);
void FEE_Data_Innit(void);

#endif
